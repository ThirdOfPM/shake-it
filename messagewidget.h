#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include "onlinescreen.h"

#include <QWidget>

namespace Ui {
class MessageWidget;
}
/*!
 * Класс, отвечающий за виджет взаимодействия с другими пользователями
 */
class MessageWidget : public QWidget
{
    Q_OBJECT

public:
/*!
 * Конструктор по умолчанию
 */
    explicit MessageWidget(QWidget *parent = 0,int holded_id=0);
/*!
 * Деструктор по умолчанию
 */
    ~MessageWidget();
/*!
 * Обновляет виджет взаимодействия с другими пользователями
 */
    void update();
/*!
 * Хранит id пользователя, который использует виджет
 */
    int holded_id;
private slots:
    void on_pushButton_clicked(); ///< Кнопка отправки сообщения

    void on_pushButton_2_clicked(); ///< Открывает либо скрывает интерфейс сообщений

    void on_pushButton_4_clicked(); ///< Кнопка добавления в чёрный список

    void on_pushButton_3_clicked(); ///< Кнопка Shake/Добавить в друзья/Удалить из друзей

    void on_lineEdit_returnPressed(); ///< Отправка сообщений при помощи клавиши Enter

private:
/*!
 * Хранит информацию о том, открыт ли интерфейс сообщений
 */
    bool mess_opend=false;
/*!
 * Указатель на класс формы QtDesigner
 */
    Ui::MessageWidget *ui;
/*!
 * Указатель на экран пользователя
 */
    OnlineScreen* screen;
};

#endif // MESSAGEWIDGET_H
