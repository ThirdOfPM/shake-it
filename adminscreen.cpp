#include "adminscreen.h"
#include "ui_adminscreen.h"

AdminScreen::AdminScreen(QWidget *parent, Qt::WindowFlags flags) :
    QWidget(parent,flags),
    ui(new Ui::AdminScreen)
{
    ui->setupUi(this);
}

AdminScreen::~AdminScreen()
{
    delete ui;
}
