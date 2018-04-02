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

private:
    Ui::MainScreen *ui;
    double getDist(double point1[2],double point2[2]);
};

#endif // MAINSCREEN_H
