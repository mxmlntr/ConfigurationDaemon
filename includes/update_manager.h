/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/includes/update_manager.h
 *        \brief  Header of update_manager method definition
 *
 *      \details The update_manager is derived from the process_manager, it is created to specifically configure the
 *               the update_manager process
 *
 *********************************************************************************************************************/
#ifndef CONFIGURATION_DAEMON_UPDATE_MANAGER_H
#define CONFIGURATION_DAEMON_UPDATE_MANAGER_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "process_manager.h"
#include "time-tp.h"

//! Defines the priority of the messages in the message queues
#define PRIORITY 1

//! Enum for synchronization via message queue
enum SyncMsg
{
    ProcessTimeout = 00,
    ProcessReady = 11,
    DataRdySHM = 22,
    DataRdyFile = 33,
    DataReceiveSuccess = 44,
    DataErrorCRC = 55,
    ReceivingError = 66,
    DaemonTimeout = 77
};

/*!
 * \brief Derived class process manager
 */
class update_manager:public process_manager {

private:
    string filename = "UMGR.json";
public:
    update_manager();
    file file1;
    //file file2;
};

#endif //CONFIGURATION_DAEMON_UPDATE_MANAGER_H
