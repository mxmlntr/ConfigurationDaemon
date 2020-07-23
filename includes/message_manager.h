//
// Created by visxim on 7/21/20.
//

#ifndef CONFIGURATION_DAEMON_MESSAGE_MANAGER_H
#define CONFIGURATION_DAEMON_MESSAGE_MANAGER_H

#include "boost/interprocess/ipc/message_queue.hpp"
#include "boost/scoped_ptr.hpp"
#include "data_storage.h"

using namespace boost::interprocess;

class message_manager
{
private:
    boost::scoped_ptr<message_queue> mq;
public:
    message_manager();
    void send_msg(char message, unsigned int priority);
    char receive_msg(unsigned int priority);
    int createQUEUE(string filename);
    int destroyQUEUE(string filename);
};


#endif //CONFIGURATION_DAEMON_MESSAGE_QUEUE_H
