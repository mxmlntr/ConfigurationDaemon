/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/includes/file.h
 *        \brief  Header of file methods for file handling
 *
 *      \details The file is for accessing the files with the configurations
 *
 *********************************************************************************************************************/
#ifndef CONFIGURATION_DAEMON_FILE_H
#define CONFIGURATION_DAEMON_FILE_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "JSON_manager.h"

using namespace std;

/*!
 * \brief File class for handling file access
 */
class file{
private:
    string filename;
public:
    JSON_manager fileJSONmng;
    void setfilename(string file);
    void callJSON();
};

#endif //CONFIGURATION_DAEMON_FILE_H
