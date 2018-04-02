#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include "mainscreen.h"
#include <QWidget>

namespace Ui {
class AdminScreen;
}

class AdminScreen : public QWidget
{
    Q_OBJECT

public:
    explicit AdminScreen(QWidget *parent = 0, Qt::WindowFlags =0);
    ~AdminScreen();

private:
    Ui::AdminScreen *ui;
    MainScreen* base;
};

#endif // ADMINSCREEN_H
