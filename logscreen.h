#ifndef LOGSCREEN_H
#define LOGSCREEN_H

#include <QWidget>
#include "mainscreen.h"

namespace Ui {
class LogScreen;
}

class LogScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LogScreen(QWidget *parent = 0, Qt::WindowFlags =0);
    ~LogScreen();

private slots:
    void on_pushButton_clicked();

private:
    int id;
    QString password;
    QString login;
    QString pass_hash;
    int radius;
    MainScreen* base;
    Ui::LogScreen *ui;
};

#endif // LOGSCREEN_H
