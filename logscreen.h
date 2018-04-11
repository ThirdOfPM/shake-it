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
/*!
 * Конструктор по умолчанию
 */
    explicit LogScreen(QWidget *parent = 0, Qt::WindowFlags =0);
/*!
 * Деструктор по умолчанию
 */
    ~LogScreen();

private slots:
/*!
 * Отвечает за нажатие кнопки логина
 */
    void on_pushButton_clicked();
/*!
 * Не используется (но без нее не работает)
 */
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
    int id; ///< id пользователя
    QString password; ///< Пароль пользователя
    QString login; ///< Логин пользователя
    QString pass_hash; ///< Хэш пароля пользователя
    int radius; ///< Радиус видимости других пользователей
/*!
 * Указатель на основное рабочее окно (Mainscreen)
 */
    MainScreen* base;
/*!
 * Указатель на класс формы QtDesigner
 */
    Ui::LogScreen *ui;
};

#endif // LOGSCREEN_H
