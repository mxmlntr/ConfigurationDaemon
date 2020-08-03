//
// Created by visxim on 7/8/20.
//

#ifndef CONFIGURATION_DAEMON_DATA_STORAGE_H
#define CONFIGURATION_DAEMON_DATA_STORAGE_H

#include <fstream>
#include <string>
#include <stdint.h>

using namespace std;

/*
 * Struct which is specified to hold the values of the UpdateManager UMGR
 */
typedef struct{
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
    //char test0[20] = {"Hallo12345"};
    //string test1 = "Hallo1234";

    //function for serializing the struct
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
        //ar & test0;
        //ar & test1;
    }
} UMGR_s;

#endif //CONFIGURATION_DAEMON_DATA_STORAGE_H
