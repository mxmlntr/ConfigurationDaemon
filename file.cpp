/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/file.cpp
 *        \brief  file methods for file handling
 *
 *      \details The file is for accessing the files with the configurations
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "file.h"

/*!
* \brief Function for setting the filename of the configuration file for this file-object
*
*/
void file::setfilename(string file)
{
    filename = file;
};

/*!
 * \brief Function for retreiving the JSON information from the file
 *
 * */
void file::callJSON()
{
    fileJSONmng.read_file(filename);
    fileJSONmng.parseToStructandSerialize(filename);
};