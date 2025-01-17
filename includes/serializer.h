/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/includes/serializer.h
 *        \brief  Header of serializer for serializing the parsed configuration data
 *
 *      \details Serializer for serializing data to both shared memory and files
 *
 *
 *********************************************************************************************************************/
#ifndef CONFIGURATION_DAEMON_SERIALIZER_H
#define CONFIGURATION_DAEMON_SERIALIZER_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <iostream>
#include "data_storage.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/serialization/vector.hpp>

using namespace boost::interprocess;
using namespace boost::iostreams;

/*!
 * \brief Class of serializer for handling data serialization to files and shared memorys
 */
class serializer{
private:

public:

    //!This method is overlaoded for every struct in data_storage
    void serializeStructToFileMemMap(UMGR_s UnSerData, string filename);
    void serializeStructToFileMemMap(EXMPLE_s UnSerData, string filename);

    //!This method is overlaoded for every struct in data_storage
    void serializeStructToSHM(UMGR_s UnSerData, string filename);
    void serializeStructToSHM(EXMPLE_s UnSerData, string filename);

    //!Replaced by MemMap implementation
    void serializeStructToFile(UMGR_s UnSerData, string filename);

    //!unusable
    void copyStructToSHM(UMGR_s UnSerData, string filename);
};

#endif //CONFIGURATION_DAEMON_SERIALIZER_H
