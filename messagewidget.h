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
    explicit MessageWidget(QWidget *parent = 0);
    ~MessageWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MessageWidget *ui;
    OnlineScreen* screen;
};

#endif // MESSAGEWIDGET_H
