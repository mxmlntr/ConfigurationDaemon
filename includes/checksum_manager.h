//
// Created by visxim on 7/17/20.
//

#ifndef CONFIGURATION_DAEMON_CHECKSUM_MANAGER_H
#define CONFIGURATION_DAEMON_CHECKSUM_MANAGER_H

#include "data_storage.h"
#include "boost/crc.hpp"
#include <iostream>

// Redefine this to change to processing buffer size
#define PRIVATE_BUFFER_SIZE  1024
// Global objects
std::streamsize const  buffer_size = PRIVATE_BUFFER_SIZE;

class checksum_manager{

private:

public:
    int createCRC(UMGR_s *CRCData);

};

#endif //CONFIGURATION_DAEMON_CHECKSUM_MANAGER_H
