#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include "mainscreen.h"
#include <QWidget>

namespace Ui {
class AdminScreen;
}
/*!
 * Класс, отвечающий за показ окна администратора
 */
class AdminScreen : public QWidget
{
    Q_OBJECT

public:
/*!
 * Конструктор по умолчанию
 */
    explicit AdminScreen(QWidget *parent = 0, Qt::WindowFlags =0);
/*!
 * Деструктор по умолчанию
 */
    ~AdminScreen();

private slots:
/*!
 * Отвечает за изменение имени файла с базой данных
 */
    void on_pushButton_2_clicked();
/*!
 * Удаляет пользоватея с указанным id
 */
    void on_pushButton_clicked();

private:
/*!
 * Указатель на класс формы QtDesigner
 */
    Ui::AdminScreen *ui;
/*!
 * Указатель на основное рабочее окно (Mainscreen)
 */
    MainScreen* base;
};

#endif // ADMINSCREEN_H
