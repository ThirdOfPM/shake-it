#include "logscreen.h"
#include "onlinescreen.h"
#include "ui_logscreen.h"



LogScreen::LogScreen(QWidget *parent, Qt::WindowFlags flags) :
    QWidget(parent,flags),
    ui(new Ui::LogScreen)
{
    base=dynamic_cast<MainScreen*>(parent);
    ui->setupUi(this);
}
LogScreen::~LogScreen()
{
    delete ui;
}

void LogScreen::on_pushButton_clicked()
{
    //FIXME login
    if(ui->lineEdit->text()==""||ui->lineEdit_2->text()==""){
        ui->label_2->setText("Заполните все поля!");
        return;
    }
    QString login=ui->lineEdit->text();
    base->sdb->open();
    QSqlQuery query;
    query.prepare("SELECT login FROM main");
    query.exec();
    QSqlRecord rec = query.record();
    bool exist=false;
    while (query.next()) {
        if(login==query.value(rec.indexOf("login")).toString())
            exist=true;
    }
    if(!exist){
        ui->label_2->setText("Такого пользователя не существует!");
        base->sdb->close();
        return;
    }
    int id=0;
    QString saved_pass_hash;
    double coords[2];
    QString friend_list_s;
    QString black_list_s;
    query.prepare("SELECT id,pass_hash,lat,long,friend_list,black_list FROM main WHERE login='"+login+"'");
    query.exec();
    rec = query.record();
    while (query.next()) {
        id=query.value(rec.indexOf("id")).toInt();
        saved_pass_hash=query.value(rec.indexOf("pass_hash")).toString();
        coords[0]=query.value(rec.indexOf("lat")).toDouble();
        coords[1]=query.value(rec.indexOf("long")).toDouble();
        friend_list_s=query.value(rec.indexOf("friend_list")).toString();
        black_list_s=query.value(rec.indexOf("black_list")).toString();
    }
    //base->sha->update(ui->lineEdit_2->text().toStdString());
    QString pass_hash=QString::fromUtf8(QCryptographicHash::hash(ui->lineEdit_2->text().toUtf8(),QCryptographicHash::Sha3_512));
    if(pass_hash!=saved_pass_hash){
        ui->label_2->setText("Неверный пароль!");
        base->sdb->close();
        return;
    }
    for(int i =0;i<base->onlineUsers.size();i++){
        if(base->onlineUsers[i]->user->login==login){
            ui->label_2->setText("Пользователь уже \nв сети!");
            base->sdb->close();
            return;
        }
    }
    base->onlineUsers.push_back(new OnlineScreen(base,Qt::Window|Qt::WindowTitleHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint));
    base->onlineUsers.last()->user=new OnlineUser();
    base->onlineUsers.last()->user->id=id;
    base->onlineUsers.last()->user->login=login;
    base->onlineUsers.last()->user->location[0]=coords[0];
    base->onlineUsers.last()->user->location[1]=coords[1];
    QStringList friend_list_sl=friend_list_s.split(" ");
    QStringList black_list_sl=black_list_s.split(" ");
    for(int i=0;i<friend_list_sl.size();i++){
        base->onlineUsers.last()->user->friends_list.push_back(friend_list_sl[i].toInt());
    }
    for(int i=0;i<black_list_sl.size();i++){
        base->onlineUsers.last()->user->black_list.push_back(black_list_sl[i].toInt());
    }
    base->onlineUsers.last()->user->radius=ui->spinBox->value();
    base->onlineUsers.last()->show();
    query.prepare("CREATE TABLE mesg_"+QString::number(id)+"_temp ("
                  "mesg TEXT,"
                  "data TEXT,"
                  "sender_id TEXT"
                  ");");
    query.exec();
    base->sdb->close();
    this->close();
}

void LogScreen::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

void LogScreen::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    ui->label_2->setText("");
}
void LogScreen::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{
    ui->label_2->setText("");
}
