#include "onlinescreen.h"
#include "ui_onlinescreen.h"

OnlineScreen::OnlineScreen(QWidget *parent, Qt::WindowFlags flags):
    QWidget(parent,flags),
    ui(new Ui::OnlineScreen)
{
    base=dynamic_cast<MainScreen*>(parent);
    map=new MapWidget(this);
    map->move(270,30);
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

void OnlineScreen::on_pushButton_clicked()
{

}

void OnlineScreen::timerEnd()
{
   // map->loadData(user->radius,user->location[0], user->location[1]);
    map->loadData(500,56.284335, 44.080579);
    map->update();
}
