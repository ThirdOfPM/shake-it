#ifndef ONLINEUSER_H
#define ONLINEUSER_H

#include "message.h"
#include "user.h"

class OnlineUser : public User
{
public:
    int radius;
    std::vector<int> online_friends_list;
    bool shake;
    bool req_shake;
    std::vector<int> shaked_users;
    std::vector<int> incoming_shakes;
    OnlineUser();
};

#endif // ONLINEUSER_H
