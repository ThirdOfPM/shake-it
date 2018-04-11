#ifndef ONLINEUSER_H
#define ONLINEUSER_H

#include "message.h"
#include "user.h"

/*!
 * Класс - наследник класса  User. Отвечает за хранение информации о пользователе, находящемся онлайн
 */
class OnlineUser : public User
{
public:
    int radius; ///< Радиус
    //bool shake=false;
    //bool req_shake=false;
    QList<int> shaked_users; ///< "Шейкнутые" пользователи
    QList<int> incoming_shakes; ///< Входящие пожатия
    OnlineUser(); ///< Конструктор по умолчанию
};

#endif // ONLINEUSER_H
