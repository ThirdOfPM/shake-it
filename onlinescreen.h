#ifndef ONLINESCREEN_H
#define ONLINESCREEN_H

#include <QWidget>
#include "mainscreen.h"
#include "onlineuser.h"
#include "mapwidget.h"

namespace Ui {
class OnlineScreen;
}

class OnlineScreen : public QWidget
{
    Q_OBJECT

public:
    explicit OnlineScreen(QWidget *parent = 0, Qt::WindowFlags =0);
    ~OnlineScreen();
    int sendMesg(Message*);
    void getMesg(Message*);
    void send_button_clicked(QString message);
private slots:
    void on_pushButton_clicked();
    void timerEnd();

private:
    Message* messages;
    MapWidget* map;
    MainScreen* base;
    OnlineUser* user;
    QString lb_messages;
    QString cur_mess;
    Ui::OnlineScreen *ui;
    QTimer *timer;

};

#endif // ONLINESCREEN_H
