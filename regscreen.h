#ifndef REGSCREEN_H
#define REGSCREEN_H

#include "mainscreen.h"

#include <QWidget>

namespace Ui {
class RegScreen;
}

class RegScreen : public QWidget
{
    Q_OBJECT

public:
    explicit RegScreen(QWidget *parent = 0, Qt::WindowFlags =0);
    ~RegScreen();

private:
    int id;
    QString login;
    QString password;
    QString pass_hash;
    double location[2];
    Ui::RegScreen *ui;
    MainScreen* base;
};

#endif // REGSCREEN_H
