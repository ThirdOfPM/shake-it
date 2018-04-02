#ifndef ADMINLOGDIALOG_H
#define ADMINLOGDIALOG_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class AdminLogDialog;
}

class AdminLogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogDialog(QWidget *parent = 0);
    ~AdminLogDialog();

private:
    Ui::AdminLogDialog *ui;
    MainScreen* base;
};

#endif // ADMINLOGDIALOG_H
