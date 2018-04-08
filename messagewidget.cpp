#include "messagewidget.h"
#include "ui_messagewidget.h"
#include "ui_onlinescreen.h"

MessageWidget::MessageWidget(QWidget *parent,int cholded_id) :
    QWidget(parent),
    ui(new Ui::MessageWidget)
{
    holded_id=cholded_id;
    screen=dynamic_cast<OnlineScreen*>(parent);
    ui->setupUi(this);
    setMaximumHeight(25);
    setMinimumHeight(25);
    show();
    screen->base->sdb->open();
    QString name;
    QSqlQuery query;
    query.prepare("SELECT login FROM main WHERE id="+QString::number(holded_id));
    query.exec();
    QSqlRecord rec=query.record();
    while(query.next()){
        name=query.value(rec.indexOf("login")).toString();
    }
    screen->base->sdb->close();
    ui->pushButton_2->setText(name);
}

MessageWidget::~MessageWidget()
{
    delete ui;
}

void MessageWidget::update()
{
    if(screen->user->friends_list.indexOf(holded_id)!=-1){
        bool online=false;
        bool ndist=false;
        for(int i=0;i<screen->base->onlineUsers.size();i++){
            if(screen->base->onlineUsers[i]->user->id==holded_id){
                online=true;
                double dist=screen->base->getDist(screen->user->location,screen->base->onlineUsers[i]->user->location);
                if(dist<=screen->user->radius&&dist<=screen->base->onlineUsers[i]->user->radius)
                    ndist=true;
            }
        }
        if(online&&ndist){
            QPalette palete=ui->pushButton_2->palette();
            palete.setColor(QPalette::Normal,QPalette::Button,QColor::fromRgb(0, 255, 0));
            ui->pushButton_2->setPalette(palete);
            ui->lineEdit->setPlaceholderText("Текст сообщения");
            ui->lineEdit->setReadOnly(false);
        }else{
            QPalette palete=ui->pushButton_2->palette();
            palete.setColor(QPalette::Normal,QPalette::Button,QColor::fromRgb(170, 170, 170,200));
            ui->pushButton_2->setPalette(palete);
            ui->lineEdit->setPlaceholderText("Пользов. не в сети");
            ui->lineEdit->setReadOnly(true);
        }
        ui->pushButton_3->setText("Уд. из друзей");
    }else{
        if(screen->user->incoming_shakes.indexOf(holded_id)!=-1){
            QPalette palete=ui->pushButton_2->palette();
            palete.setColor(QPalette::Normal,QPalette::Button,QColor::fromRgb(255, 127, 0));
            ui->pushButton_2->setPalette(palete);
            ui->pushButton_3->setText("Shake");
            ui->lineEdit->setReadOnly(false);
            QString name;
            for(int i=0;i<screen->base->onlineUsers.size();i++){
                if(screen->base->onlineUsers[i]->user->id==holded_id){
                    name=screen->base->onlineUsers[i]->user->login;
                }
            }
            screen->ui->label_2->setText(screen->ui->label_2->text()+"Входящий Shake пользователь "+name+"\n");
        }else{
            QPalette palete=ui->pushButton_2->palette();
            palete.setColor(QPalette::Normal,QPalette::Button,QColor::fromRgb(255,255,255,180));
            ui->pushButton_2->setPalette(palete);
            ui->pushButton_3->setText("Доб. в друзья");
            ui->lineEdit->setReadOnly(false);
        }

    }

    if(mess_opend){
        setMaximumHeight(145);
        setMinimumHeight(145);
        //NOTE load messages
        screen->base->sdb->open();
        QSqlQuery query;
        query.prepare("SELECT mesg FROM mesg_"+QString::number(screen->user->id)+" WHERE sender_id="+QString::number(holded_id));
        query.exec();
        QSqlRecord rec=query.record();
        QStringList to_owner;
        while(query.next()){
            to_owner.push_back(query.value(rec.indexOf("mesg")).toString());
        }
//        query.prepare("SELECT mesg FROM mesg_"+QString::number(holded_id)+" WHERE sender_id="+QString::number(screen->user->id));
//        query.exec();
//        QStringList from_owner;
//        while(query.next()){
//            from_owner.push_back(query.value(rec.indexOf("mesg")).toString());
//        }
        //if(to_owner.size()!=0||from_owner.size()!=0){
        if(to_owner.size()!=0){
            ui->label->setText("");
            for(int i=0;i<to_owner.size();i++){
                ui->label->setText(ui->label->text()+to_owner[i]+"\n");
            }
        }
        screen->base->sdb->close();
    }else{
        setMaximumHeight(25);
        setMinimumHeight(25);
    }
}

void MessageWidget::on_pushButton_clicked()
{
    if(!screen->send_button_clicked(ui->lineEdit->text(), holded_id))
        ui->lineEdit->setText("Ошибка отправки");
}

void MessageWidget::on_pushButton_2_clicked()
{
    mess_opend=!mess_opend;
}

void MessageWidget::on_pushButton_4_clicked()
{
    screen->user->incoming_shakes.removeOne(holded_id);
    screen->user->shaked_users.removeOne(holded_id);
    screen->user->friends_list.removeOne(holded_id);
    screen->user->black_list.push_back(holded_id);
    for(int i=0;i<screen->base->onlineUsers.size();i++){
        if(screen->base->onlineUsers[i]->user->id==holded_id){
            screen->base->onlineUsers[i]->user->friends_list.removeOne(screen->user->id);
        }
    }
    screen->base->sdb->open();
    QSqlQuery query;
    QString str;
    for(int i=0;i<screen->base->onlineUsers.size();i++){
        if(screen->base->onlineUsers[i]->user->id==holded_id){
            for(int j=0;j<screen->base->onlineUsers[i]->user->friends_list.size();j++){
                str+=QString::number(screen->base->onlineUsers[i]->user->friends_list[j]);
                if(j<screen->base->onlineUsers[i]->user->friends_list.size()-1)
                    str+=" ";
            }
        }
    }
    query.prepare("UPDATE main SET friend_list='"+str+"' WHERE id="+QString::number(holded_id)+";");
    query.exec();
    for(int j=0;j<screen->user->friends_list.size();j++){
        str+=QString::number(screen->user->friends_list[j]);
        if(j<screen->user->friends_list.size()-1)
            str+=" ";
    }
    query.prepare("UPDATE main SET friend_list='"+str+"' WHERE id="+QString::number(screen->user->id)+";");
    query.exec();
    for(int j=0;j<screen->user->black_list.size();j++){
        str+=QString::number(screen->user->black_list[j]);
        if(j<screen->user->black_list.size()-1)
            str+=" ";
    }
    query.prepare("UPDATE main SET black_list='"+str+"' WHERE id="+QString::number(screen->user->id)+";");
    query.exec();
    screen->base->sdb->close();
}

void MessageWidget::on_pushButton_3_clicked()
{
    if(screen->user->incoming_shakes.indexOf(holded_id)!=-1){
        screen->user->incoming_shakes.removeOne(holded_id);
        for(int i=0;i<screen->base->onlineUsers.size();i++){
            if(screen->base->onlineUsers[i]->user->id==holded_id){
                screen->base->onlineUsers[i]->user->shaked_users.push_back(screen->user->id);
            }
        }
        screen->user->shaked_users.push_back(holded_id);
        return;
    }
    if(screen->user->friends_list.indexOf(holded_id)!=-1){
        screen->user->friends_list.removeOne(holded_id);
        for(int i=0;i<screen->base->onlineUsers.size();i++){
            if(screen->base->onlineUsers[i]->user->id==holded_id){
                screen->base->onlineUsers[i]->user->friends_list.removeOne(screen->user->id);
            }
        }
    }else{
        screen->user->friends_list.push_back(holded_id);
        for(int i=0;i<screen->base->onlineUsers.size();i++){
            if(screen->base->onlineUsers[i]->user->id==holded_id){
                screen->base->onlineUsers[i]->user->friends_list.push_back(screen->user->id);
            }
        }
    }
    screen->base->sdb->open();
    QSqlQuery query;
    QString str;
    for(int i=0;i<screen->base->onlineUsers.size();i++){
        if(screen->base->onlineUsers[i]->user->id==holded_id){
            for(int j=0;j<screen->base->onlineUsers[i]->user->friends_list.size();j++){
                str+=QString::number(screen->base->onlineUsers[i]->user->friends_list[j]);
                if(j<screen->base->onlineUsers[i]->user->friends_list.size()-1)
                    str+=" ";
            }
        }
    }
    query.prepare("UPDATE main SET friend_list='"+str+"' WHERE id="+QString::number(holded_id)+";");
    query.exec();
    str="";
    for(int j=0;j<screen->user->friends_list.size();j++){
        str+=QString::number(screen->user->friends_list[j]);
        if(j<screen->user->friends_list.size()-1)
            str+=" ";
    }
    query.prepare("UPDATE main SET friend_list='"+str+"' WHERE id="+QString::number(screen->user->id)+";");
    query.exec();
    screen->base->sdb->close();
}
