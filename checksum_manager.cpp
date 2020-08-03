/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/checksum_manager.cpp
 *        \brief  Checksum_manager for checking the integrity of the data
 *
 *      \details The Checksum_manager creates and checks if the data is valid
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "checksum_manager.h"

/*!
 * \brief Function for creating the checksum
 *
 * Needs to be overloaded for different data structures
 * */
int checksum_manager::createCRC(UMGR_s *CRCdata)
{
    boost::crc_32_type result;

    result.process_block(CRCdata, CRCdata + 1);

    cout << result.checksum() << endl;

    return result.checksum();
};

/*!
 * \brief Function for checking the checksum
 *
 * Needs to be overloaded for different data structures
 * */
int checksum_manager::checkCRC(UMGR_s *CRCdata)
{

};