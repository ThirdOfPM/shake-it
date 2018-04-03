#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include "onlinescreen.h"

#include <QWidget>

namespace Ui {
class MessageWidget;
}

class MessageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MessageWidget(QWidget *parent = 0,int holded_id=0);
    ~MessageWidget();
    void update();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    bool mess_opend=false;
    int holded_id;
    Ui::MessageWidget *ui;
    OnlineScreen* screen;
};

#endif // MESSAGEWIDGET_H
