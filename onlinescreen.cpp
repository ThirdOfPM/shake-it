#include "messagewidget.h"
#include "onlinescreen.h"
#include "ui_onlinescreen.h"

OnlineScreen::OnlineScreen(QWidget *parent, Qt::WindowFlags flags):
    QWidget(parent,flags),
    ui(new Ui::OnlineScreen)
{
    base=dynamic_cast<MainScreen*>(parent);
    map=new MapWidget(this);
    map->move(290,30);
    map->resize(450,450);
    map->show();
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerEnd()));
    timer->start(1000);
}
OnlineScreen::~OnlineScreen()
{
    delete ui;
}

void OnlineScreen::send_button_clicked(QString message)
{

}

void OnlineScreen::on_pushButton_clicked()
{
    QLabel* lb=new QLabel(" Name");
    lb->setMaximumSize(250,25);
    ui->verticalLayout->addWidget(lb);
    QLabel* messlb=new QLabel(" No Messages");
    messlb->setMaximumSize(250,75);
    messlb->setAlignment(Qt::AlignTop);
    ui->verticalLayout->addWidget(messlb);
    MessageWidget* mw=new MessageWidget(this);
    mw->setMaximumSize(250,25);
    ui->verticalLayout->addWidget(mw);
    QLabel* lb2=new QLabel(" Name 2");
    lb2->setMaximumSize(250,25);
    ui->verticalLayout->addWidget(lb2);
    QLabel* endlb=new QLabel("");
    ui->verticalLayout->addWidget(endlb);
}

void OnlineScreen::timerEnd()
{
   // map->loadData(user->radius,user->location[0], user->location[1]);
    map->loadData(500,56.284335, 44.080579);
    map->update();
}
