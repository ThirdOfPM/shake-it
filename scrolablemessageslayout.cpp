#include "scrolablemessageslayout.h"
#include "ui_scrolablemessageslayout.h"

ScrolableMessagesLayout::ScrolableMessagesLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrolableMessagesLayout)
{
    ui->setupUi(this);
}

ScrolableMessagesLayout::~ScrolableMessagesLayout()
{
    delete ui;
}
