//
// Created by visxim on 7/10/20.
//

#ifndef CONFIGURATION_DAEMON_FILE_H
#define CONFIGURATION_DAEMON_FILE_H

#include "JSON_manager.h"

using namespace std;

class file
{
private:
    string filename;
public:
    JSON_manager fileJSONmng;
    void setfilename(string file);
    void callJSON();


};


#endif //CONFIGURATION_DAEMON_FILE_H
