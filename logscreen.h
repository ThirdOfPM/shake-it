#ifndef LOGSCREEN_H
#define LOGSCREEN_H

#include <QWidget>
#include "mainscreen.h"

namespace Ui {
class LogScreen;
}
/*!
 * Класс, отвечающий за взаимодействие с кнопкой логина
 */
class LogScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LogScreen(QWidget *parent = 0, Qt::WindowFlags =0);
    ~LogScreen();

private slots:
/*!
 * Отвечает за нажатие кнпки логина
 */
    void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);
/*!
 * Убирает текст предупреждения с экрана
 */
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);
/*!
 * Убирает текст предупреждения с экрана
 */

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

private:
 /*!
  * \brief Переменные id, password, login, pass_hash, radius
  *
  * Используются для входа пользователя в систему
  */
    int id;
    QString password;
    QString login;
    QString pass_hash;
    int radius;
    MainScreen* base;
    Ui::LogScreen *ui;
};

#endif // LOGSCREEN_H
