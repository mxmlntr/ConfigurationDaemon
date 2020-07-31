//
// Created by visxim on 7/15/20.
//

#ifndef CONFIGURATION_DAEMON_UPDATE_MANAGER_H
#define CONFIGURATION_DAEMON_UPDATE_MANAGER_H

#include "process_manager.h"

#define PRIORITY 1

enum SyncMsg
{
    ProcessReady = 11,
    DataRdySHM = 22,
    DataRdyFile = 33,
    DataReceiveSuccess = 44,
    DataErrorCRC = 55,
    ReceivingError = 66
};

class update_manager:public process_manager {

private:
    string filename = "UMGR.json";
public:
    update_manager();
    file file1;
    //file file2;
};


#endif //CONFIGURATION_DAEMON_UPDATE_MANAGER_H
