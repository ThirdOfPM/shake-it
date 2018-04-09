#include "messagewidget.h"
#include "onlinescreen.h"
#include "ui_onlinescreen.h"
#include "ui_scrolablemessageslayout.h"

#include <QCloseEvent>

OnlineScreen::OnlineScreen(QWidget *parent, Qt::WindowFlags flags, OnlineUser* us):
    QWidget(parent,flags),
    ui(new Ui::OnlineScreen)
{
    user=us;
    base=dynamic_cast<MainScreen*>(parent);
    map=new MapWidget(this);
    map->move(365,30);
    map->resize(450,450);
    map->show();
    ui->setupUi(this);
    maptimer = new QTimer(this);
    connect(maptimer, SIGNAL(timeout()), this, SLOT(MaptimerEnd()));
    maptimer->start(1000);

    uitimer = new QTimer(this);
    connect(uitimer, SIGNAL(timeout()), this, SLOT(UitimerEnd()));
    uitimer->start(100);
    sml=new ScrolableMessagesLayout(ui->scrollArea);
    ui->scrollArea->setWidget(sml);
    sml->show();
//    MessageWidget* widget;
//    widget=new MessageWidget(this);
//    messageWidgets.push_back(widget);
//    sml->ui->verticalLayout->addWidget(widget);
    this->setWindowTitle("Shake-It - "+user->login+" - Online Screen");
    for(int i=0;i<base->onlineUsers.size();i++){
        if(user->friends_list.indexOf(base->onlineUsers[i]->user->id)!=-1){
            double dist=base->getDist(user->location,base->onlineUsers[i]->user->location);
            if(dist<=user->radius&&dist<=base->onlineUsers[i]->user->radius)
                base->onlineUsers[i]->ui->label_2->setText(base->onlineUsers[i]->ui->label_2->text()+"Ваш друг "+user->login+" в зоне доступа\n");
        }
    }
}
OnlineScreen::~OnlineScreen()
{
    delete ui;

}


bool OnlineScreen::send_button_clicked(QString message,int target)
{
    bool online=false;
    for(int i=0;i<base->onlineUsers.size();i++){
        if(base->onlineUsers[i]->user->id==target){
            online=true;
            base->onlineUsers[i]->ui->label_2->setText(base->onlineUsers[i]->ui->label_2->text()+"Новое сообщение от "+user->login+"\n");
        }
    }
    if(!online)
        return false;
    QString str=QDateTime::currentDateTime().toString()+" - "+message;
    base->sdb->open();
    QSqlQuery query;
    query.prepare("INSERT INTO messages (mesg,sender,target) VALUES ('"+str+"',"+QString::number(user->id)+","+QString::number(target)+");");
    query.exec();
    base->sdb->close();

    return true;
}

void OnlineScreen::on_pushButton_clicked()
{
    for(int i=0;i<base->onlineUsers.size();i++){
        double dist=base->getDist(user->location,base->onlineUsers[i]->user->location);
        if((dist>user->radius||dist>base->onlineUsers[i]->user->radius)||base->onlineUsers[i]==this){}else{
            base->onlineUsers[i]->user->incoming_shakes.push_back(user->id);
        }
    }
}

void OnlineScreen::MaptimerEnd()
{
    map->loadData(user->radius,user->location[0], user->location[1]);
    //map->loadData(500,56.284335, 44.080579);
    map->update();


}

void OnlineScreen::UitimerEnd()
{
    ui->label_2->adjustSize();
    ui->label_2->setMinimumSize(ui->label_2->sizeHint());
    ui->label_2->updateGeometry();
    ui->label_2->update();
    ui->scrollAreaWidgetContents_2->setMinimumSize(ui->label_2->sizeHint());
    ui->scrollArea_2->updateGeometry();
    ui->scrollArea_2->update();
    for(int i=0;i<user->shaked_users.size();i++){
        bool online=false;
        for(int j=0;j<base->onlineUsers.size();j++){
            if(base->onlineUsers[j]->user->id==user->shaked_users[i]){
                double dist=base->getDist(user->location,base->onlineUsers[j]->user->location);
                if(dist>user->radius||dist>base->onlineUsers[j]->user->radius){

                }else
                    online=true;
            }
        }
        if(!online){
            user->shaked_users.removeOne(user->shaked_users[i]);
        }
    }
    MessageWidget* widget;
    QList<int> existed;
    for(int i=0;i<messageWidgets.size();i++){
         sml->ui->verticalLayout->removeWidget(messageWidgets[i]);
         existed.push_back(messageWidgets[i]->holded_id);
    }

    for(int i=0;i<user->friends_list.size();i++){
        if(existed.indexOf(user->friends_list[i])==-1){
            //create new
            if(user->friends_list[i]!=0){
                widget=new MessageWidget(this,user->friends_list[i]);
                messageWidgets.push_back(widget);
                sml->ui->verticalLayout->addWidget(widget);
            }
        }else{
            //add existed
            sml->ui->verticalLayout->addWidget(messageWidgets[existed.indexOf(user->friends_list[i])]);
        }
    }
    for(int i=0;i<user->shaked_users.size();i++){
        if(existed.indexOf(user->shaked_users[i])==-1){
            //create new
            widget=new MessageWidget(this,user->shaked_users[i]);
            messageWidgets.push_back(widget);
            sml->ui->verticalLayout->addWidget(widget);
        }else{
            //add existed
            sml->ui->verticalLayout->addWidget(messageWidgets[existed.indexOf(user->shaked_users[i])]);
        }
    }
    for(int i=0;i<user->incoming_shakes.size();i++){
        if(existed.indexOf(user->incoming_shakes[i])==-1){
            //create new
            widget=new MessageWidget(this,user->incoming_shakes[i]);
            messageWidgets.push_back(widget);
            sml->ui->verticalLayout->addWidget(widget);
        }else{
            //add existed
            sml->ui->verticalLayout->addWidget(messageWidgets[existed.indexOf(user->incoming_shakes[i])]);
        }
    }

    ui->spinBox->setValue(user->radius);
    int vsize=0;
    for(int i=0;i<messageWidgets.size();i++){
        messageWidgets[i]->update();
        vsize+=messageWidgets[i]->height()+3;
    }
    //ui->verticalLayout->setGeometry(QRect(QPoint(0,0), QSize(250,vsize-3)));
    //sml->resize(250,vsize-3+16);
    sml->setMinimumSize(300,vsize-3+16);
    ui->scrollArea->setWidget(sml);
}

void OnlineScreen::on_OnlineScreen_destroyed()
{

}

void OnlineScreen::closeEvent(QCloseEvent *bar)
{
    delete user;
    delete map;
    delete sml;
    delete maptimer;
    delete uitimer;
    base->onlineUsers.removeOne(this);
    bar->accept();
}

void OnlineScreen::on_spinBox_valueChanged(int arg1)
{
    user->radius=arg1;
    for(int i=0;i<base->onlineUsers.size();i++){
        if(user->friends_list.indexOf(base->onlineUsers[i]->user->id)!=-1){
            double dist=base->getDist(user->location,base->onlineUsers[i]->user->location);
            if(dist<=user->radius&&dist<=base->onlineUsers[i]->user->radius)
                base->onlineUsers[i]->ui->label_2->setText(base->onlineUsers[i]->ui->label_2->text()+"Ваш друг "+user->login+" в зоне доступа\n");
        }
    }
}

void OnlineScreen::on_pushButton_5_clicked()
{
    //left
    double point[2]={user->location[0],user->location[1]};
    double deltaH=(user->radius/3)/(111300*cos(point[0]*3.14159265359/180));
    //double deltaV=(user->radius/3)/111111.0;
    point[1]-=deltaH;
    if(point[1]<-180){
        double pereval=-(point[1]+180);
        point[1]+=deltaH*(1/sqrt(2));
        point[1]*=-1;
        point[1]=180-pereval;
    }
    user->location[0]=point[0];
    user->location[1]=point[1];
    base->sdb->open();
    QSqlQuery query;
    query.prepare("UPDATE main SET lat="+QString::number(user->location[0])+",long="+QString::number(user->location[1])+" WHERE id="+QString::number(user->id));
    query.exec();
    base->sdb->close();
}

void OnlineScreen::on_pushButton_2_clicked()
{
    //up
    double point[2]={user->location[0],user->location[1]};
    //double deltaH=(user->radius/3)/(111300*cos(point[0]*3.14159265359/180));
    double deltaV=(user->radius/3)/111111.0;
    point[0]+=deltaV;
    if(point[0]>90){
        double pereval=point[0]-90;
        point[0]-=deltaV;
        point[1]*=-1;
        point[0]=90-pereval;
    }
    user->location[0]=point[0];
    user->location[1]=point[1];
    base->sdb->open();
    QSqlQuery query;
    query.prepare("UPDATE main SET lat="+QString::number(user->location[0])+",long="+QString::number(user->location[1])+" WHERE id="+QString::number(user->id));
    query.exec();
    base->sdb->close();
}

void OnlineScreen::on_pushButton_4_clicked()
{
    //right
    double point[2]={user->location[0],user->location[1]};
    double deltaH=(user->radius/3)/(111300*cos(point[0]*3.14159265359/180));
    //double deltaV=(user->radius/3)/111111.0;
    point[1]+=deltaH;
    if(point[1]>180){
        double pereval=point[1]-180;
        point[1]-=deltaH*(1/sqrt(2));
        point[1]*=-1;
        point[1]=-180+pereval;
    }
    user->location[0]=point[0];
    user->location[1]=point[1];
    base->sdb->open();
    QSqlQuery query;
    query.prepare("UPDATE main SET lat="+QString::number(user->location[0])+",long="+QString::number(user->location[1])+" WHERE id="+QString::number(user->id));
    query.exec();
    base->sdb->close();
}

void OnlineScreen::on_pushButton_3_clicked()
{
    //down
    double point[2]={user->location[0],user->location[1]};
    //double deltaH=(user->radius/3)/(111300*cos(point[0]*3.14159265359/180));
    double deltaV=(user->radius/3)/111111.0;
    point[0]-=deltaV;
    if(point[0]<-90){
        double pereval=-(point[0]+90);
        point[0]+=deltaV*(1/sqrt(2));
        point[1]*=-1;
        point[0]=-90+pereval;
    }
    user->location[0]=point[0];
    user->location[1]=point[1];
    base->sdb->open();
    QSqlQuery query;
    query.prepare("UPDATE main SET lat="+QString::number(user->location[0])+",long="+QString::number(user->location[1])+" WHERE id="+QString::number(user->id));
    query.exec();
    base->sdb->close();
}
