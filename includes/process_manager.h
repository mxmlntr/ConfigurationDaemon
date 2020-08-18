/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/includes/process_manager.h
 *        \brief  Header of process_manager method definition
 *
 *      \details process_manager shall be used to create derived classes from it, it contains all the basic functions
 *               which every derived class should have
 *
 *********************************************************************************************************************/
#ifndef CONFIGURATION_DAEMON_PROCESS_MANAGER_H
#define CONFIGURATION_DAEMON_PROCESS_MANAGER_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "deserializer.h"
#include "file.h"
#include "message_manager.h"

//! Defines if a new file is present (also see check_file_status())
//#define NEWFILE

//! Defines the priority of the messages in the message queues
#define PRIORITY 1

/*!
 * \brief Class for all basic members needed in the derived classes
 */
class process_manager {

private:

public:
    message_manager processMSGQUE;
    deserializer processDES;
    int check_file_status();
};

#endif //CONFIGURATION_DAEMON_PROCESS_MANAGER_H
