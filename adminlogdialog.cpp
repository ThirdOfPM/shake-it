#include "adminlogdialog.h"
#include "adminscreen.h"
#include "ui_adminlogdialog.h"



AdminLogDialog::AdminLogDialog(QWidget *parent, Qt::WindowFlags flags):
    QWidget(parent,flags),
    ui(new Ui::AdminLogDialog)
{
    base=dynamic_cast<MainScreen*>(parent);
    ui->setupUi(this);
}

AdminLogDialog::~AdminLogDialog()
{
    this->close();
}


void AdminLogDialog::on_lineEdit_textEdited(const QString &arg1)
{
     ui->label_2->setText("");
}

void AdminLogDialog::on_lineEdit_returnPressed()
{
    if(ui->lineEdit->text()=="kpd200081"){
        AdminScreen* ascreen=new AdminScreen(base,Qt::Window|Qt::WindowTitleHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
        ascreen->show();
        this->close();
    }else{
        ui->label_2->setText("Неверный пароль!\n Повторите попытку.");
    }
}

void AdminLogDialog::on_pushButton_clicked()
{
     delete this;
}

void AdminLogDialog::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()=="kpd200081"){
        AdminScreen* ascreen=new AdminScreen(base,Qt::Window|Qt::WindowTitleHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
        ascreen->show();
        this->close();
    }else{
        ui->label_2->setText("Неверный пароль!\n Повторите попытку.");

    }
}
