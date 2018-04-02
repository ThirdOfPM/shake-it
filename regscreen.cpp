#include "regscreen.h"
#include "ui_regscreen.h"



RegScreen::RegScreen(QWidget *parent, Qt::WindowFlags):
    QWidget(parent),
    ui(new Ui::RegScreen)
{
    ui->setupUi(this);
}

RegScreen::~RegScreen()
{
    delete ui;
}
