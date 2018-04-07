#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "onlinescreen.h"
#include "logscreen.h"
#include "regscreen.h"
#include "adminlogdialog.h"

MainScreen::MainScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScreen)
{
    sdb = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    sdb->setDatabaseName(basename);
    ui->setupUi(this);
    uitimer = new QTimer(this);
    connect(uitimer, SIGNAL(timeout()), this, SLOT(UitimerEnd()));
    uitimer->start(500);
    sdb->open();
    QSqlQuery query;
    query.prepare("CREATE TABLE main ("
                  "id integer PRIMARY KEY NOT NULL, "
                  "login TEXT, "
                  "pass_hash TEXT,"
                  "lat TEXT,"
                  "long TEXT,"
                  "friend_list TEXT,"
                  "black_list TEXT"
                  ");");
    query.exec();
    sdb->close();
}

MainScreen::~MainScreen()
{
    delete ui;
}

double MainScreen::getDist(double point1[], double point2[])
{
    for(int i=0;i<2;i++){
        point1[i]=point1[i]*3.14159265359/180;
    }
    for(int i=0;i<2;i++){
        point2[i]=point2[i]*3.14159265359/180;
    }
    double c11,s11,c12,s12,delta,cdelta,sdelta;
    c11=cos(point1[0]);
    c12=cos(point2[0]);
    s11=sin(point1[0]);
    s12=sin(point2[0]);
    delta=point2[1]-point1[1];
    cdelta=cos(delta);
    sdelta=sin(delta);
    for(int i=0;i<2;i++){
        point1[i]=point1[i]/3.14159265359*180;
    }
    for(int i=0;i<2;i++){
        point2[i]=point2[i]/3.14159265359*180;
    }
    return (10690.5+6378160)*atan2(sqrt(pow(c12*sdelta,2)+pow(c11*s12-s11*c12*cdelta,2)),s11*s12+c11*c12*cdelta);
}

void MainScreen::on_pushButton_clicked()
{
    LogScreen* login=new LogScreen(this,Qt::Window|Qt::WindowTitleHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    login->show();
}

void MainScreen::on_pushButton_2_clicked()
{
    RegScreen* reg= new RegScreen(this,Qt::Window|Qt::WindowTitleHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    reg->show();
}

void MainScreen::on_pushButton_3_clicked()
{
    AdminLogDialog* dial= new AdminLogDialog(this,Qt::Window|Qt::WindowTitleHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    dial->show();
}

void MainScreen::on_MainScreen_destroyed()
{
}

void MainScreen::UitimerEnd()
{
    QString str("");
    if(onlineUsers.size()==0){
        str="No users.";
    }
    for(int i=0;i<onlineUsers.size();i++){
        str+=onlineUsers[i]->user->login+"\n";
        //str+="test\n";
    }
    ui->label_2->setText(str);
}
