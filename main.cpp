//
// Created by visxim on 7/15/20.
//

#include <iostream>
#include "update_manager.h"
#include "deserializer.h"

update_manager UMGR_object;

int main(int argc, char **argv)
{
    //deserializer des("UMGR.json");
    //UMGR_s data;
    //des.deserializeStructFromSHM(&data);
    if (fork() == 0)
    {
        //only for checking
        std::ofstream ofs("childCall");
        ofs << "child process calling in" <<  endl;

        update_manager UMGR_object;

        string output = UMGR_object.file1.fileJSONmng.get_json_config_string();
        ofs << "created" << output << endl;

        ofs.close();
    }
    else
    {
        cout << "parent process calling in"<< endl;

        //Deserialize from SHM
        deserializer UMGRdes("UMGR.json");
        UMGR_s deserializedStruct;
        UMGRdes.deserializeStructFromSHM(&deserializedStruct);

        cout << "received:" << deserializedStruct.description << endl;
    }

    return 0;
}

