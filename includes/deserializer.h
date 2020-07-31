//
// Created by visxim on 7/9/20.
//

#ifndef CONFIGURATION_DAEMON_DESERIALIZER_H
#define CONFIGURATION_DAEMON_DESERIALIZER_H

#include "data_storage.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/iostreams/device//mapped_file.hpp>
#include <boost/iostreams/stream.hpp>

using namespace boost::interprocess;
using namespace boost::iostreams;

class deserializer{
private:
    string filename;
public:
    deserializer();
    deserializer(string name);
    void setfilename(string name);
    void deserializeStructFromFile(UMGR_s *Data_s);
    void deserializeStructFromSHM(UMGR_s *Data_s);
    void deserializeStructFromFileMemMap(UMGR_s *Data_s);
    void copyStructFromSHM(UMGR_s *Data_s);
};

#endif //CONFIGURATION_DAEMON_DESERIALIZER_H
