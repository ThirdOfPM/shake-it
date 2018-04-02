#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>



class Message
{
    QString text;
    int from_id;
    int to_id;
    QString data;
public:
    Message();
};

#endif // MESSAGE_H
