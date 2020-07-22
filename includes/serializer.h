//
// Created by visxim on 7/17/20.
//

#ifndef CONFIGURATION_DAEMON_SERIALIZER_H
#define CONFIGURATION_DAEMON_SERIALIZER_H

#include "data_storage.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>

using namespace boost::interprocess;

class serializer{
private:

public:
    void serializeStructToFile(UMGR_s UnSerData, string filename);
    void serializeStructToSHM(UMGR_s UnSerData, string filename);
};

#endif //CONFIGURATION_DAEMON_SERIALIZER_H
