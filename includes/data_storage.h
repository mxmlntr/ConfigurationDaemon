/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/includes/data_storage.h
 *        \brief  Header of checksum_manager for checking the integrity of the data
 *
 *      \details The Checksum_manager creates and checks if the data is valid
 *
 *
 *********************************************************************************************************************/
#ifndef CONFIGURATION_DAEMON_DATA_STORAGE_H
#define CONFIGURATION_DAEMON_DATA_STORAGE_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <fstream>
#include <string>
#include <stdint.h>
#include "boost/crc.hpp"

using namespace std;

/*!
 * \brief Struct which is specified to hold the values of the UpdateManager UMGR
 */
typedef struct {
    string name;
    string description;
    string dlt_id;
    string log_mode;
    string log_level;
    string log_dir_path;
    unsigned int ipc_port;
    unsigned int reconnection_retry_offset;
    unsigned int msg_buf_size;
    int checksum;

    //!function for serializing the struct
    template <typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & name;
        ar & description;
        ar & dlt_id;
        ar & log_mode;
        ar & log_level;
        ar & log_dir_path;
        ar & ipc_port;
        ar & reconnection_retry_offset;
        ar & msg_buf_size;
        ar & checksum;
    }
} UMGR_s;

#endif //CONFIGURATION_DAEMON_DATA_STORAGE_H
