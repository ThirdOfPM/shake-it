#ifndef USER_H
#define USER_H

#include <QList>
#include <QString>


/*!
 * Класс, отвечающий за хранение сохраняющейся информации о пользователе
 */
class User
{
public:
    int id; ///< id пользователя
    QString login; ///< Логин пользователя
    QList<int> friends_list; ///< Список друзей польлзователя
    double location[2]; ///< Местоположение пользователя
    QList<int> black_list; ///< Черный список
/*!
 * Конструктор по умолчанию
 */
    User();
};

#endif // USER_H
