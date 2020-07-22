//
// Created by visxim on 7/15/20.
//

#ifndef CONFIGURATION_DAEMON_PROCESS_MANAGER_H
#define CONFIGURATION_DAEMON_PROCESS_MANAGER_H

#include "deserializer.h"
#include "file.h"
#include "message_manager.h"

class process_manager {

private:

public:
    message_manager processMSGQUE;
    deserializer processDES;
};

#endif //CONFIGURATION_DAEMON_PROCESS_MANAGER_H
