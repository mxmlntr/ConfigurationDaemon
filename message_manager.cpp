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

    msgque.reset(new message_queue(open_or_create, QUEUEfilename.c_str(), 10, sizeof(int)));

    cout << "Created queue named:" << QUEUEfilename << endl;

    return 1;
};

int message_manager::destroyQUEUE(string filename)
{
    filename.erase(filename.length()-5 , 5);
    string QUEUEfilename = filename+"QUEUE";
    if (msgque->remove(QUEUEfilename.c_str()))
    {
        cout << "Destroyed queue named:" << QUEUEfilename << endl;
        return 1;
    }
    else
    {
        cout << "Could not destroy queue named:" << QUEUEfilename << endl;
        return 0;
    }

};

void message_manager::send_msg(int message,unsigned int priority)
{
    msgque->send(&message,sizeof(int),priority);
};

int message_manager::receive_msg(unsigned int priority)
{
    int message;
    size_t recvd_size;
    msgque->receive((void*) &message,sizeof(int),recvd_size,priority);
    return message;
};

