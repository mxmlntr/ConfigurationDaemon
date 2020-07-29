//
// Created by visxim on 7/15/20.
//

#include "process_manager.h"

int process_manager::check_file_status()
{
    #ifdef NEWFILE
    return 1;
    #else
    return 0;
    #endif
};

