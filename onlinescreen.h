#ifndef ONLINESCREEN_H
#define ONLINESCREEN_H

#include <QWidget>
#include "mainscreen.h"
#include "onlineuser.h"
#include "mapwidget.h"
#include "scrolablemessageslayout.h"

class MessageWidget;

namespace Ui {
class OnlineScreen;
}
/*!
 * Класс, отвечающий за пользовательский экран
 */
class OnlineScreen : public QWidget
{
    Q_OBJECT

public:
/*!
 * Хранит информацию о пользователе, которому принадлежит экран
 */
    OnlineUser* user;
/*!
 * Указатель на основное рабочее окно (Mainscreen)
 */
    MainScreen* base;
/*!
 * Указатель на класс формы QtDesigner
 */
    Ui::OnlineScreen *ui;
/*!
 * Конструктор (+ передача указателя на пользователя)
 */
    explicit OnlineScreen(QWidget *parent = 0, Qt::WindowFlags =0,OnlineUser* user=0);
/*!
 * Деструктор по умолчанию
 */
    ~OnlineScreen();
    int sendMesg(Message*); ///< Не используется
    void getMesg(Message*); ///< Не используется
/*!
 * Отвечает за отправку сообщений, вызывается из MessageWidget
 * \param message Текст сообщения
 * \param target id получателя
 */
    bool send_button_clicked(QString message,int target);
private slots:
    void on_pushButton_clicked(); ///< Кнопка  Shake
/*!
 * Слот, использующийся для обновления карты
 */
    void MaptimerEnd();
/*!
 * Слот, использующийся для обновления интерфейса
 */
    void UitimerEnd();
/*!
 * Не используется (но без нее не работает)
 */
    void on_OnlineScreen_destroyed();
/*!
 * Отвечает за изменение значения радиуса
 * \param arg1 Радиус
 */
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_5_clicked(); ///< Кнопка "Влево"

    void on_pushButton_2_clicked(); ///< Кнопка "Вверх"

    void on_pushButton_4_clicked(); ///< Кнопка "Направо"

    void on_pushButton_3_clicked(); ///< Кнопка "Вниз"

private:
/*!
 * Вызывается при закрытии текущего окна и удаляет пользователя из списка онлайн-рользователей
 * \param bar Содержит информацию о причине закрытя окна
 */
    void closeEvent(QCloseEvent *bar);
    QList<MessageWidget*> messageWidgets; ///< Список интерфейсов
    //Message* messages;
    MapWidget* map; ///< Виджет карты
    //QString lb_messages;
    //QString cur_mess;
    QTimer *maptimer; ///< Используется для обновления карты
    QTimer *uitimer; ///< Используется для обновления графического интерфейса
    ScrolableMessagesLayout* sml; ///< Виджет скролла
};

#endif // ONLINESCREEN_H
