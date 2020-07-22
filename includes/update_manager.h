//
// Created by visxim on 7/15/20.
//

#ifndef CONFIGURATION_DAEMON_UPDATE_MANAGER_H
#define CONFIGURATION_DAEMON_UPDATE_MANAGER_H

#include "process_manager.h"

class update_manager:public process_manager {

private:

public:
    update_manager();
    file file1;
    file file2;
};


#endif //CONFIGURATION_DAEMON_UPDATE_MANAGER_H
