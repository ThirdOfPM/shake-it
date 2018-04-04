#ifndef ADMINLOGDIALOG_H
#define ADMINLOGDIALOG_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class AdminLogDialog;
}

class AdminLogDialog : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLogDialog(QWidget *parent = 0, Qt::WindowFlags =0);
    ~AdminLogDialog();

private slots:

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminLogDialog *ui;
    MainScreen* base;
};

#endif // ADMINLOGDIALOG_H
