#ifndef USER_H
#define USER_H

#include <QString>



class User
{
public:
    int id;
    QString login;
    std::vector<int> friends_list;
    double location[2];
    std::vector<int> black_list;
    User();
};

#endif // USER_H
