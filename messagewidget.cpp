#include "messagewidget.h"
#include "ui_messagewidget.h"

MessageWidget::MessageWidget(QWidget *parent,int cholded_id) :
    QWidget(parent),
    ui(new Ui::MessageWidget)
{
    holded_id=cholded_id;
    screen=dynamic_cast<OnlineScreen*>(parent);
    ui->setupUi(this);
    setMaximumHeight(25);
    setMinimumHeight(25);
    show();
}

MessageWidget::~MessageWidget()
{
    delete ui;
}

void MessageWidget::update()
{
    if(mess_opend){
        setMaximumHeight(140);
        setMinimumHeight(140);
    }else{
        setMaximumHeight(25);
        setMinimumHeight(25);
    }
}

void MessageWidget::on_pushButton_clicked()
{
    screen->send_button_clicked(ui->lineEdit->text(), holded_id);
}

void MessageWidget::on_pushButton_2_clicked()
{
    mess_opend=!mess_opend;
}
