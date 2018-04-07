#include "messagewidget.h"
#include "onlinescreen.h"
#include "ui_onlinescreen.h"
#include "ui_scrolablemessageslayout.h"

#include <QCloseEvent>

OnlineScreen::OnlineScreen(QWidget *parent, Qt::WindowFlags flags):
    QWidget(parent,flags),
    ui(new Ui::OnlineScreen)
{
    base=dynamic_cast<MainScreen*>(parent);
    map=new MapWidget(this);
    map->move(320,30);
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
    MessageWidget* widget;
    widget=new MessageWidget(this);
    messageWidgets.push_back(widget);
    sml->ui->verticalLayout->addWidget(widget);
    this->setWindowTitle("Shake-It - UserName - Online Screen");
}
OnlineScreen::~OnlineScreen()
{
    delete ui;

}

void OnlineScreen::send_button_clicked(QString message,int target)
{

}

void OnlineScreen::on_pushButton_clicked()
{
    MessageWidget* widget;
    for(int i=0;i<10;i++){
        widget=new MessageWidget(this);
        messageWidgets.push_back(widget);
        sml->ui->verticalLayout->addWidget(widget);
    }
    //QLabel* end_lb=new QLabel("");
    //ui->verticalLayout->addWidget(end_lb);
}

void OnlineScreen::MaptimerEnd()
{
    map->loadData(user->radius,user->location[0], user->location[1]);
    //map->loadData(500,56.284335, 44.080579);
    map->update();


}

void OnlineScreen::UitimerEnd()
{
    int vsize=0;
    for(int i=0;i<messageWidgets.size();i++){
        messageWidgets[i]->update();
        vsize+=messageWidgets[i]->height()+3;
    }
    //ui->verticalLayout->setGeometry(QRect(QPoint(0,0), QSize(250,vsize-3)));
    //sml->resize(250,vsize-3+16);
    sml->setMinimumSize(250,vsize-3+16);
    ui->scrollArea->setWidget(sml);
}

void OnlineScreen::on_OnlineScreen_destroyed()
{

}

void OnlineScreen::closeEvent(QCloseEvent *bar)
{
    base->sdb->open();
    QSqlQuery query;
    query.prepare("DROP TABLE mesg_"+QString::number(user->id)+"_temp");
    query.exec();
    base->sdb->close();
    delete user;
    delete map;
    delete sml;
    delete maptimer;
    delete uitimer;
    base->onlineUsers.removeOne(this);
    bar->accept();
}
