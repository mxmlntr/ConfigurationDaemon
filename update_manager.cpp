//
// Created by visxim on 7/15/20.
//

#include "update_manager.h"

//Constructor which initializes all the update_manager-specific values
update_manager::update_manager()
{
    //create the messagequeue for synchronisation with the receiving process
    processMSGQUE.createQUEUE(filename);

    //Set the filename for the deserializer
    processDES.setfilename(filename);

    //Set the filenames for files associated with this process
    file1.setfilename(filename);
    file1.callJSON();
    //file2.setfilename("ANYFILENAME");
    //file2.callJSON();

    processMSGQUE.send_msg('a',1);
    cout << "Message receives:" << processMSGQUE.receive_msg(1) << endl;

    processMSGQUE.destroyQUEUE(filename);
};