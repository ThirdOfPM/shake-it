#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QtSql>

class OnlineScreen;
namespace Ui {
class MainScreen;
}

class MainScreen : public QWidget
{
    Q_OBJECT

public:

    QList<OnlineScreen*> onlineUsers;
    QSqlDatabase* sdb;
    QString basename="base.sqlite";

    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_MainScreen_destroyed();

    void UitimerEnd();

private:
    Ui::MainScreen *ui;
    QTimer* uitimer;
    double getDist(double point1[2],double point2[2]);
};

#endif // MAINSCREEN_H
