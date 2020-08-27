/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/includes/EXMPLE.h
 *        \brief  Header of EXMPLE method definition
 *
 *      \details The update_manager is derived from the process_manager, it is created to specifically configure the
 *               the update_manager process
 *
 *********************************************************************************************************************/
#ifndef CONFIGURATION_DAEMON_EXMPLE_H
#define CONFIGURATION_DAEMON_EXMPLE_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "process_manager.h"
#include "time-tp.h"

/*!
 * \brief Derived class process manager
 */
class EXMPLE:public process_manager {

private:
    string filename = "EXMPLE.json";
public:
    EXMPLE();
    file file1;
};

#endif //CONFIGURATION_DAEMON_UPDATE_MANAGER_H
