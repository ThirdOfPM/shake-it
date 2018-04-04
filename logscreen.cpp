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

void LogScreen::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

void LogScreen::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit->setText("");
}

void LogScreen::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit_2->setText("");
}
