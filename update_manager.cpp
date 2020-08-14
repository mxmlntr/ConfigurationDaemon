/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/update_manager.cpp
 *        \brief  update_manager method definition
 *
 *      \details The update_manager is derived from the process_manager, it is created to specifically configure the
 *               the update_manager process
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "update_manager.h"

/*!
* \brief Constructor which initializes all the update_manager-specific values
*
* This constructor creates all necessary objects for the configuration of the update manager
*
*/
update_manager::update_manager()
{
#ifdef TRACE
    tracepoint(tp_provider, time_tracepoint_daemon, 1);
#endif
    //! Create the messagequeue for synchronisation with the receiving process
    processMSGQUE.createQUEUE(filename);

    //! Receive the first meassage from the update manager process
    int tmpmsg = processMSGQUE.receive_msg(PRIORITY);

#ifdef TRACE
    tracepoint(tp_provider, time_tracepoint_daemon, 2);
#endif

    //! Check if the process calles "ready"
    if (tmpmsg == ProcessReady)
    {
        cout << "Process  UMGR called ready." << endl;
        /*!
         *  True if a new file is present or changed were made to that file
         *  False if the file isnt new and no changes were made it
         *  That means that the file has been already serialized with the current configuration
         *  and the update manager process is notified that it shall receive the configuration from
         *  the binary file
         */
        if (check_file_status())
        {

            //!Set the filename/s for file/s associated with this process
            file1.setfilename(filename);
            file1.callJSON();

            //!Dummy files
            //file2.setfilename("ANYFILENAME");
            //file2.callJSON();

            //!Notify the process that the data is ready in SHM
            processMSGQUE.send_msg(DataRdySHM, PRIORITY);
        }
        else
        {
            //!Send msg that file is already serialized in file
            processMSGQUE.send_msg(DataRdyFile, PRIORITY);
        }
        tmpmsg = processMSGQUE.receive_msg(PRIORITY);
    }
#ifdef TRACE
    tracepoint(tp_provider, time_tracepoint_daemon, 7);
#endif
    /*!
     *  Switch case which evaluates the answer from the update manager process
     */
    switch (tmpmsg)
    {
        case ProcessTimeout:
            cout << "Connection to Process UMGR timed out." << endl;
            break;
        case DataReceiveSuccess:
            cout << "UMGR Process called success." << endl;
            break;
        case ReceivingError:
            cout << "UMGR Process called error while receiving data." << endl;
            break;
        case DataErrorCRC:
            cout << "UMGR Process called CRC error." << endl;
            break;
        case DaemonTimeout:
            cout << "UMGR Process called Daemon Timeout." << endl;
            break;
        default:
            cout << "UMGR Process replied with unknown message:" << tmpmsg << endl;
            break;
    }

    //! There can be an implementation after the answer has been evaluated, otherwise destroy the message queue
    processMSGQUE.destroyQUEUE(filename);
};