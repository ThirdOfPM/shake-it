#include "adminlogdialog.h"
#include "ui_adminlogdialog.h"

AdminLogDialog::AdminLogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogDialog)
{
    ui->setupUi(this);
}

AdminLogDialog::~AdminLogDialog()
{
    delete ui;
}
