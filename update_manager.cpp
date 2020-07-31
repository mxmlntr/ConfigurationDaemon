//
// Created by visxim on 7/15/20.
//

#include "update_manager.h"

//Constructor which initializes all the update_manager-specific values
update_manager::update_manager()
{
    //create the messagequeue for synchronisation with the receiving process
    processMSGQUE.createQUEUE(filename);

    //receive inital call from process if its already ready
    int tmpmsg = processMSGQUE.receive_msg(PRIORITY);

    if(tmpmsg == ProcessReady)
    {
        cout << "Process  UMGR called ready." << endl;
        //True if a new file is present or changed were made to that file
        if (check_file_status())
        {
            //Set the filename/s for file/s associated with this process
            file1.setfilename(filename);
            file1.callJSON();
            //file2.setfilename("ANYFILENAME");
            //file2.callJSON();

            //Notify the process that the data is ready in SHM
            processMSGQUE.send_msg(DataRdySHM,PRIORITY);
        }
        else
        {
            //Send msg that file is already serialized in file
            processMSGQUE.send_msg(DataRdyFile,PRIORITY);
        }
    }
    else
    {
        cout << "Connection to Process UMGR timed out." << endl;
    }

    tmpmsg = processMSGQUE.receive_msg(PRIORITY);
    switch(tmpmsg)
        {
            case DataReceiveSuccess:
                cout << "UMGR Process called success." << endl;
                break;
            case ReceivingError:
                cout << "UMGR Process called error while receiving data." << endl;
                break;
            case DataErrorCRC:
                cout << "UMGR Process called CRC error." << endl;
                break;
            default:
                cout << "UMGR Process replied with unknown message." << endl;
                break;
        }
    processMSGQUE.destroyQUEUE(filename);
};