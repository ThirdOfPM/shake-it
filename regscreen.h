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

private slots:
    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_2_selectionChanged();

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

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
