/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/includes/JSON_manager.h
 *        \brief  Header of JSON_manager for handling JSON data
 *
 *      \details The JSON_manager handels the interpretation and storage of the JSON data from
 *               the given file
 *
 *********************************************************************************************************************/
#ifndef CONFIGURATION_DAEMON_JSON_MANAGER_H
#define CONFIGURATION_DAEMON_JSON_MANAGER_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "rapidjson.h"
#include "reader.h"
#include "writer.h"
#include "document.h"
#include "stringbuffer.h"
#include "data_storage.h"
#include "serializer.h"
#include "checksum_manager.h"
#include "time-tp.h"

using namespace rapidjson;
using namespace std;
using namespace boost::interprocess;

/*!
 * \brief JSON manager class for reading and parsing JSON data
 */
class JSON_manager{
private:
    Document doc;
    serializer ser;
    checksum_manager CRC;
public:
    unsigned int read_file(string filename);
    string get_json_config_string();
    unsigned int parseToStructandSerialize(string filename);
};

#endif //CONFIGURATION_DAEMON_JSON_MANAGER_H
