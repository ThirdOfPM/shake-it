#ifndef USER_H
#define USER_H

#include <QList>
#include <QString>



class User
{
public:
    int id;
    QString login;
    QList<int> friends_list;
    double location[2];
    QList<int> black_list;
    User();
};

#endif // USER_H
