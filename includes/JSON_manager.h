//
// Created by visxim on 7/17/20.
//

#ifndef CONFIGURATION_DAEMON_JSON_MANAGER_H
#define CONFIGURATION_DAEMON_JSON_MANAGER_H

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

using namespace rapidjson;
using namespace std;
using namespace boost::interprocess;

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
