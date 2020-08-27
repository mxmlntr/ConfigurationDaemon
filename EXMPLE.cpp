/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/EXMPLE.cpp
 *        \brief  EXMPLE method definition
 *
 *      \details The update_manager is derived from the process_manager, it is created to specifically configure the
 *               the update_manager process
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EXMPLE.h"

/*!
* \brief Constructor which initializes all the update_manager-specific values
*
* This constructor creates all necessary objects for the configuration of the update manager
*
*/
EXMPLE::EXMPLE()
{
    //! Create the messagequeue for synchronisation with the receiving process
    processMSGQUE.createQUEUE(filename);

    //! Receive the first meassage from the update manager process
    int tmpmsg = processMSGQUE.receive_msg(PRIORITY);

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
#if defined(TRACENEWFILE)
            tracepoint(tp_provider, time_tracepoint_daemon_new, 1);
#endif
            //!Set the filename/s for file/s associated with this process
            file1.setfilename(filename);
            file1.callJSON();

#ifdef TRACENEWFILE
            tracepoint(tp_provider, time_tracepoint_daemon_new, 5);
#endif
            //!Notify the process that the data is ready in SHM
            processMSGQUE.send_msg(DataRdySHM, PRIORITY);
        }
        else
        {
#ifdef TRACEOLDFILE
            tracepoint(tp_provider, time_tracepoint_daemon_old, 1);
#endif
            //!Send msg that file is already serialized in file
            processMSGQUE.send_msg(DataRdyFile, PRIORITY);
        }
        tmpmsg = processMSGQUE.receive_msg(PRIORITY);
    }
#ifdef TRACENEWFILE
    tracepoint(tp_provider, time_tracepoint_daemon_new, 9);
#endif
#ifdef TRACEOLDFILE
    tracepoint(tp_provider, time_tracepoint_daemon_old, 5);
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

#ifdef TRACENEWFILE
    tracepoint(tp_provider, time_tracepoint_daemon_new, 10);
#endif
#ifdef TRACEOLDFILE
    tracepoint(tp_provider, time_tracepoint_daemon_old, 6);
#endif

    //! There can be an implementation after the answer has been evaluated, otherwise destroy the message queue
    processMSGQUE.destroyQUEUE(filename);
};