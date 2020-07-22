//
// Created by visxim on 7/15/20.
//
#include "process_manager_factory.h"



//TODO: change parameter to string instead of integer
/*
 * Factory Method which creates the process_manager object depending on the parameter
 * since a switch case can only utilize integer values it is neccessary to use an enum+integer instead
 * of a string variable as paramter
 * */
process_manager* process_manager_factory::create(int ProcessName)
{
    //create empty process_manager
    process_manager *process = NULL;
    switch(ProcessName) {
        //If UpdateManager is called, create the object
        case UpdateManager:{
            process = new update_manager;
            break;
        }
        case ExecutionManager:{
            //process = new process_manager("EXEC");
            break;
        }
        default:{
            return NULL;
        }
    }
    return process;
};