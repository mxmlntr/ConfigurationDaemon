//
// Created by visxim on 7/15/20.
//

#include "update_manager.h"

//Constructor which initializes all the update_manager-specific values
update_manager::update_manager()
{
    processDES.setfilename("UMGR.json");

    file1.setfilename("UMGR.json");
    file2.setfilename("ANYFILENAME");

    file1.callJSON();
    //file2.callJSON();
};