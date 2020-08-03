/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/includes/checksum_manager.h
 *        \brief  Header of checksum_manager for checking the integrity of the data
 *
 *      \details The Checksum_manager creates and checks if the data is valid
 *
 *
 *********************************************************************************************************************/
#ifndef CONFIGURATION_DAEMON_CHECKSUM_MANAGER_H
#define CONFIGURATION_DAEMON_CHECKSUM_MANAGER_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "data_storage.h"
#include "boost/crc.hpp"
#include <iostream>

/*!
 * \brief Class of checksum manager for CRC managment
 */
class checksum_manager{

private:

public:
    int createCRC(UMGR_s *CRCdata);
    int checkCRC(UMGR_s *CRCdata);

};

#endif //CONFIGURATION_DAEMON_CHECKSUM_MANAGER_H
