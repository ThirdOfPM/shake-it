#ifndef ONLINESCREEN_H
#define ONLINESCREEN_H

#include <QWidget>
#include "mainscreen.h"
#include "onlineuser.h"
#include "mapwidget.h"
#include "scrolablemessageslayout.h"

class MessageWidget;

namespace Ui {
class OnlineScreen;
}

class OnlineScreen : public QWidget
{
    Q_OBJECT

public:
    OnlineUser* user;

    explicit OnlineScreen(QWidget *parent = 0, Qt::WindowFlags =0);
    ~OnlineScreen();
    int sendMesg(Message*);
    void getMesg(Message*);
    void send_button_clicked(QString message,int sender);
private slots:
    void on_pushButton_clicked();
    void MaptimerEnd();
    void UitimerEnd();

    void on_OnlineScreen_destroyed();

private:
    void closeEvent(QCloseEvent *bar);
    QList<MessageWidget*> messageWidgets;
    //Message* messages;
    MapWidget* map;
    MainScreen* base;
    //QString lb_messages;
    //QString cur_mess;
    Ui::OnlineScreen *ui;
    QTimer *maptimer;
    QTimer *uitimer;
    ScrolableMessagesLayout* sml;
};

#endif // ONLINESCREEN_H
