#include "messagewidget.h"
#include "ui_messagewidget.h"

MessageWidget::MessageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageWidget)
{
    screen=dynamic_cast<OnlineScreen*>(parent);
    ui->setupUi(this);
}

MessageWidget::~MessageWidget()
{
    delete ui;
}

void MessageWidget::on_pushButton_clicked()
{
    screen->send_button_clicked(ui->lineEdit->text());
}
