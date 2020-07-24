//
// Created by visxim on 7/21/20.
//

#ifndef CONFIGURATION_DAEMON_MESSAGE_MANAGER_H
#define CONFIGURATION_DAEMON_MESSAGE_MANAGER_H

#include <iostream>
#include "boost/interprocess/ipc/message_queue.hpp"
#include "boost/scoped_ptr.hpp"
#include "data_storage.h"

using namespace boost::interprocess;

class message_manager
{
private:
    std::unique_ptr<message_queue> msgque;
public:
    message_manager();
    void send_msg(int message, unsigned int priority);
    int receive_msg(unsigned int priority);
    int createQUEUE(string filename);
    int destroyQUEUE(string filename);
};


#endif //CONFIGURATION_DAEMON_MESSAGE_QUEUE_H
