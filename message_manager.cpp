//
// Created by visxim on 7/21/20.
//

#include "message_manager.h"

message_manager::message_manager()
{

};

int message_manager::createQUEUE(string filename)
{
    filename.erase(filename.length()-5 , 5);
    string QUEUEfilename = filename+"QUEUE";

    mq.reset(new message_queue(open_or_create, QUEUEfilename.c_str(), 100, sizeof(char)));

    cout << "Created queue named:" << QUEUEfilename << endl;

    return 1;
};

int message_manager::destroyQUEUE(string filename)
{
    filename.erase(filename.length()-5 , 5);
    string QUEUEfilename = filename+"QUEUE";
    mq->remove(QUEUEfilename.c_str());

    cout << "Destroyed queue named:" << QUEUEfilename << endl;

    return 1;
};

void message_manager::send_msg(char message,unsigned int priority)
{
    mq->send(&message,sizeof(char),priority);
};

char message_manager::receive_msg(unsigned int priority)
{
    char message;
    size_t recvd_size;
    mq->receive((void*) &message,sizeof(char),recvd_size,priority);
    return message;
};

