//
// Created by visxim on 7/15/20.
//
#ifndef CONFIGURATION_DAEMON_PROCESS_MANAGER_FACTORY_H
#define CONFIGURATION_DAEMON_PROCESS_MANAGER_FACTORY_H

#include "process_manager.h"
#include "update_manager.h"

enum availableProcesses{UpdateManager = 1, ExecutionManager};

class process_manager_factory {

public:
    //factory Method
    static process_manager* create(int ProcessName);

};


#endif //CONFIGURATION_DAEMON_PROCESS_MANAGER_FACTORY_H
