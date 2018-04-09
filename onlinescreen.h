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
    MainScreen* base;
        Ui::OnlineScreen *ui;

    explicit OnlineScreen(QWidget *parent = 0, Qt::WindowFlags =0,OnlineUser* user=0);
    ~OnlineScreen();
    int sendMesg(Message*);
    void getMesg(Message*);
    bool send_button_clicked(QString message,int target);
private slots:
    void on_pushButton_clicked();
    void MaptimerEnd();
    void UitimerEnd();

    void on_OnlineScreen_destroyed();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    void closeEvent(QCloseEvent *bar);
    QList<MessageWidget*> messageWidgets;
    //Message* messages;
    MapWidget* map;
    //QString lb_messages;
    //QString cur_mess;
    QTimer *maptimer;
    QTimer *uitimer;
    ScrolableMessagesLayout* sml;
};

#endif // ONLINESCREEN_H
