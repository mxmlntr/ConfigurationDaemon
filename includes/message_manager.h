//
// Created by visxim on 7/21/20.
//

#ifndef CONFIGURATION_DAEMON_MESSAGE_MANAGER_H
#define CONFIGURATION_DAEMON_MESSAGE_MANAGER_H

#include "boost/interprocess/ipc/message_queue.hpp"
#include "data_storage.h"

using namespace boost::interprocess;

class message_manager
{
private:

public:
    message_manager();
    void send_msg(string message);
    //message_queue umgr_queue(open_or_create_t, "UMGR_QUEUE", 20,sizeof(string));
};


#endif //CONFIGURATION_DAEMON_MESSAGE_QUEUE_H
