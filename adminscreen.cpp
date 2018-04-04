#include "adminscreen.h"
#include "ui_adminscreen.h"

AdminScreen::AdminScreen(QWidget *parent, Qt::WindowFlags flags) :
    QWidget(parent,flags),
    ui(new Ui::AdminScreen)
{
    base=dynamic_cast<MainScreen*>(parent);
    ui->setupUi(this);
}

AdminScreen::~AdminScreen()
{
    delete ui;
}

void AdminScreen::on_pushButton_2_clicked()
{
    base->basename=ui->lineEdit->text();
}

void AdminScreen::on_pushButton_clicked()
{
    int id=ui->lineEdit_2->text().toInt();
    //FIXME delete this user
}
