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
    base->onlineUsers.push_back(new OnlineScreen(base,Qt::Window|Qt::WindowTitleHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint));
    base->onlineUsers.last()->show();
    this->close();
}
