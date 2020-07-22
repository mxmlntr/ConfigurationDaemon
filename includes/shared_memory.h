//
// Created by visxim on 7/13/20.
//

#ifndef CONFIGURATION_DAEMON_SHARED_MEMORY_H
#define CONFIGURATION_DAEMON_SHARED_MEMORY_H

#include "data_storage.h"
#include <boost/interprocess/managed_shared_memory.hpp>

using namespace boost::interprocess;

class shared_memory {

private:

public:
    bufferstream createSHM(UMGR_s UnSerData, string filename);
};


#endif //CONFIGURATION_DAEMON_SHARED_MEMORY_H
