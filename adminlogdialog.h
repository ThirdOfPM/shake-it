#ifndef ADMINLOGDIALOG_H
#define ADMINLOGDIALOG_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class AdminLogDialog;
}

/*!
 * Класс, отвечающий за интерфейс доступа к окну администратора
 */
class AdminLogDialog : public QWidget
{
/*!
 * Макрос, который указывает Qmake, что необходимо добавить к классу метаданные
 */
    Q_OBJECT

public:
/*!
 * Конструктор по умолчанию
 */
    explicit AdminLogDialog(QWidget *parent = 0, Qt::WindowFlags =0);
/*!
 * Деструктор по умолчанию
 */
    ~AdminLogDialog();

private slots:
/*!
 * Используется для обнуления текста предупреждений
 */

    void on_lineEdit_textEdited(const QString &arg1);
/*!
 * Осуществляет проверку пароля админа и вход в систему, закрывая при этом окно пароля
 */

    void on_lineEdit_returnPressed();
/*!
 * Осуществляет проверку пароля админа и вход в систему, закрывая при этом окно пароля
 */

    void on_pushButton_clicked();
/*!
 * Закрывает окно логина администратора
 */

    void on_pushButton_2_clicked();

private:
/*!
 * Указатель на класс формы QtDesigner
 */
    Ui::AdminLogDialog *ui;
/*!
 * Указатель на основное рабочее окно (Mainscreen)
 */
    MainScreen* base;
};

#endif // ADMINLOGDIALOG_H
