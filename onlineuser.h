#ifndef ONLINEUSER_H
#define ONLINEUSER_H

#include "message.h"
#include "user.h"

class OnlineUser : public User
{
public:
    int radius;
    //bool shake=false;
    //bool req_shake=false;
    QList<int> shaked_users;
    QList<int> incoming_shakes;
    OnlineUser();
};

#endif // ONLINEUSER_H
