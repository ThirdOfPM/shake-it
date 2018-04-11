#ifndef REGSCREEN_H
#define REGSCREEN_H

#include "mainscreen.h"

#include <QWidget>

namespace Ui {
class RegScreen;
}
/*!
 * Класс, отвечающий за регистрацию пользователей
 */
class RegScreen : public QWidget
{
    Q_OBJECT

public:
/*!
 * Конструктор по умолчанию
 */
    explicit RegScreen(QWidget *parent = 0, Qt::WindowFlags =0);
/*!
 * Деструктор по умолчанию
 */
    ~RegScreen();

private slots:
    void on_lineEdit_2_textChanged(const QString &arg1); ///< Не используется

    void on_lineEdit_3_textChanged(const QString &arg1); ///< Не используется

    void on_lineEdit_2_selectionChanged(); ///< Не используется

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2); ///< Убирает текст предупреждения

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2); ///< Убирает текст предупреждения

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2); ///< Убирает текст предупреждения

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2); ///< Убирает текст предупреждения

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2); ///< Убирает текст предупреждения

    void on_pushButton_clicked(); ///< Кнопка регистрации

private:
    int id; ///< id пользователя
    QString login; ///< Логин пользователя
    QString password; ///< Пароль пользователя
    QString pass_hash; ///< Хэш пароля пользователя
    double location[2]; ///< Местоположение пользователя
/*!
 * Указатель на класс формы QtDesigner
 */
    Ui::RegScreen *ui;
/*!
 * Указатель на основное рабочее окно (Mainscreen)
 */
    MainScreen* base;
};

#endif // REGSCREEN_H
