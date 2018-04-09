#include "adminscreen.h"
#include "ui_adminscreen.h"
#include "onlinescreen.h"

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
    base->sdb->setDatabaseName(base->basename);
}

void AdminScreen::on_pushButton_clicked()
{
    int id=ui->lineEdit_2->text().toInt();

    for(int i=0;i<base->onlineUsers.size();i++){
        if(base->onlineUsers[i]->user->id==id){
            base->onlineUsers[i]->close();
        }
    }
    base->sdb->open();
    QSqlQuery query;
    query.prepare("DELETE FROM main WHERE id="+QString::number(id));
    query.exec();
    query.prepare("DROP TABLE mesg_"+QString::number(id));
    query.exec();
    base->sdb->close();
}
