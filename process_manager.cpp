/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/process_manager.cpp
 *        \brief  process_manager method definition
 *
 *      \details process_manager shall be used to create derived classes from it, it contains all the basic functions
 *               which every derived class should have
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "process_manager.h"

/*!
* \brief function which simulates the check of a file status
*
* This function is unsed to simulate if the current configuration file is either new or has changed since
* last time this function was called
*/
int process_manager::check_file_status()
{
    #ifdef NEWFILE
    return 1;
    #else
    return 0;
    #endif
};

