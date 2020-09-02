/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/JSON_manager.cpp
 *        \brief  JSON_manager for handling JSON data
 *
 *      \details The JSON_manager handels the interpretation and storage of the JSON data from
 *               the given file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "JSON_manager.h"

/*!
* \brief Function for reading the JSON file and parsing it into a document object
*
*/
unsigned int JSON_manager::read_file(string filename)
{
    string buf;
    string json;

    string binaryfilename = "/home/visxim/CLionProjects/ShareFolder/"+filename;

    //! Read the whole file line by line and store it into the "json" string
    ifstream fileInputStream (binaryfilename);
    if (fileInputStream.is_open())
    {
        while ( getline (fileInputStream,buf) )
        {
            json.append(buf);
        }
        fileInputStream.close();
    }
    else cout << "Unable to open file\n";

    //!convert the read string into const char* and parse to document
    const char* jsn = json.c_str();

    //! Parse the converted "json" string into a document object
    doc.Parse(jsn);

    cout << "JSON-file successfully parsed.\n";
    return 1;
};

/*!
* \brief Return the whole JSON data as a string from the document object
*
*/
string JSON_manager::get_json_config_string()
{
    StringBuffer output;
    Writer<StringBuffer> writer(output);
    doc.Accept(writer);
    return output.GetString();
};

//TODO: Create a virtual function to be implemented by the the object?
/*!
 * \brief Function for parsing the interpreted JSON data from the file into a predefinied struct (to find in data_storage.h)
 *
 * */
unsigned int JSON_manager::parseToStructandSerialize(string filename)
{
    //! compare the filename to find the right implementation
    if (!filename.compare("UMGR.json"))
    {
        //!create the matching struct
        UMGR_s data;
        //!parse all the data into this struct
        data.name = doc["name"].GetString();
        data.description = doc["description"].GetString();
        data.dlt_id = doc["dlt_id"].GetString();
        data.log_mode = doc["log_mode"].GetString();
        data.log_level = doc["log_level"].GetString();
        data.log_dir_path = doc["log_dir_path"].GetString();
        data.ipc_port = doc["ipc_port"].GetUint();
        data.reconnection_retry_offset = doc["reconnection_retry_offset"].GetUint();
        data.msg_buf_size = doc["msg_buf_size"].GetUint();

        cout << "JSON-file transfered into struct." << endl;

#ifdef TRACENEWFILE
        tracepoint(tp_provider, time_tracepoint_daemon_new, 2);
#endif

        //!pass the config string, created from the struct to receive the checksum
        data.checksum = CRC.createCRC(&data);

#ifdef TRACENEWFILE
        tracepoint(tp_provider, time_tracepoint_daemon_new, 3);
#endif

        //!call the serialize and pass the struct to be serialized into SHM
        ser.serializeStructToSHM(data, filename);

#ifdef TRACENEWFILE
        tracepoint(tp_provider, time_tracepoint_daemon_new, 4);
#endif
        //!not usable see function for details
        //ser.copyStructToSHM(data,filename);

        //!call the serialize and pass the struct to be serialized into a file
        ser.serializeStructToFileMemMap(data, filename);

    }
    //! compare the filename to find the right implementation
    else if (!filename.compare("dm_server_config_sample_cluster.json"))
    {

    }
    else if (!filename.compare("EXMPLE.json"))
    {
        //!create the matching struct
        EXMPLE_s data;
        //!parse all the data into this struct
        data.name0 = doc["name0"].GetString();
        data.description1 = doc["description1"].GetString();
        data.mode2 = doc["mode2"].GetString();
        data.version3 = doc["version3"].GetString();
        data.status4 = doc["status4"].GetString();
        data.path5 = doc["path5"].GetString();
        data.buffer_size6 = doc["buffer_size6"].GetInt();
        data.id7 = doc["id7"].GetInt();
        data.number8 = doc["number8"].GetInt();
        data.length9 = doc["length9"].GetInt();
        data.name10 = doc["name10"].GetString();
        data.description11 = doc["description11"].GetString();
        data.mode12 = doc["mode12"].GetString();
        data.version13 = doc["version13"].GetString();
        data.status14 = doc["status14"].GetString();
        data.path15 = doc["path15"].GetString();
        data.buffer_size16 = doc["buffer_size16"].GetInt();
        data.id17 = doc["id17"].GetInt();
        data.number18 = doc["number18"].GetInt();
        data.length19 = doc["length19"].GetInt();
        data.name20 = doc["name20"].GetString();
        data.description21 = doc["description21"].GetString();
        data.mode22 = doc["mode22"].GetString();
        data.version23 = doc["version23"].GetString();
        data.status24 = doc["status24"].GetString();
        data.path25 = doc["path25"].GetString();
        data.buffer_size26 = doc["buffer_size26"].GetInt();
        data.id27 = doc["id27"].GetInt();
        data.number28 = doc["number28"].GetInt();
        data.length29 = doc["length29"].GetInt();
        data.name30 = doc["name30"].GetString();
        data.description31 = doc["description31"].GetString();
        data.mode32 = doc["mode32"].GetString();
        data.version33 = doc["version33"].GetString();
        data.status34 = doc["status34"].GetString();
        data.path35 = doc["path35"].GetString();
        data.buffer_size36 = doc["buffer_size36"].GetInt();
        data.id37 = doc["id37"].GetInt();
        data.number38 = doc["number38"].GetInt();
        data.length39 = doc["length39"].GetInt();
        data.name40 = doc["name40"].GetString();
        data.description41 = doc["description41"].GetString();
        data.mode42 = doc["mode42"].GetString();
        data.version43 = doc["version43"].GetString();
        data.status44 = doc["status44"].GetString();
        data.path45 = doc["path45"].GetString();
        data.buffer_size46 = doc["buffer_size46"].GetInt();
        data.id47 = doc["id47"].GetInt();
        data.number48 = doc["number48"].GetInt();
        data.length49 = doc["length49"].GetInt();
        data.name50 = doc["name50"].GetString();
        data.description51 = doc["description51"].GetString();
        data.mode52 = doc["mode52"].GetString();
        data.version53 = doc["version53"].GetString();
        data.status54 = doc["status54"].GetString();
        data.path55 = doc["path55"].GetString();
        data.buffer_size56 = doc["buffer_size56"].GetInt();
        data.id57 = doc["id57"].GetInt();
        data.number58 = doc["number58"].GetInt();
        data.length59 = doc["length59"].GetInt();
        data.name60 = doc["name60"].GetString();
        data.description61 = doc["description61"].GetString();
        data.mode62 = doc["mode62"].GetString();
        data.version63 = doc["version63"].GetString();
        data.status64 = doc["status64"].GetString();
        data.path65 = doc["path65"].GetString();
        data.buffer_size66 = doc["buffer_size66"].GetInt();
        data.id67 = doc["id67"].GetInt();
        data.number68 = doc["number68"].GetInt();
        data.length69 = doc["length69"].GetInt();
        data.name70 = doc["name70"].GetString();
        data.description71 = doc["description71"].GetString();
        data.mode72 = doc["mode72"].GetString();
        data.version73 = doc["version73"].GetString();
        data.status74 = doc["status74"].GetString();
        data.path75 = doc["path75"].GetString();
        data.buffer_size76 = doc["buffer_size76"].GetInt();
        data.id77 = doc["id77"].GetInt();
        data.number78 = doc["number78"].GetInt();
        data.length79 = doc["length79"].GetInt();
        data.name80 = doc["name80"].GetString();
        data.description81 = doc["description81"].GetString();
        data.mode82 = doc["mode82"].GetString();
        data.version83 = doc["version83"].GetString();
        data.status84 = doc["status84"].GetString();
        data.path85 = doc["path85"].GetString();
        data.buffer_size86 = doc["buffer_size86"].GetInt();
        data.id87 = doc["id87"].GetInt();
        data.number88 = doc["number88"].GetInt();
        data.length89 = doc["length89"].GetInt();
        data.name90 = doc["name90"].GetString();
        data.description91 = doc["description91"].GetString();
        data.mode92 = doc["mode92"].GetString();
        data.version93 = doc["version93"].GetString();
        data.status94 = doc["status94"].GetString();
        data.path95 = doc["path95"].GetString();
        data.buffer_size96 = doc["buffer_size96"].GetInt();
        data.id97 = doc["id97"].GetInt();
        data.number98 = doc["number98"].GetInt();
        data.length99 = doc["length99"].GetInt();

        cout << "JSON-file transfered into struct." << endl;

#ifdef TRACENEWFILE
            tracepoint(tp_provider, time_tracepoint_daemon_new, 2);
#endif

            //!pass the config string, created from the struct to receive the checksum
            data.checksum = CRC.createCRC(&data);

#ifdef TRACENEWFILE
            tracepoint(tp_provider, time_tracepoint_daemon_new, 3);
#endif

            //!call the serialize and pass the struct to be serialized into SHM
            ser.serializeStructToSHM(data, filename);

#ifdef TRACENEWFILE
            tracepoint(tp_provider, time_tracepoint_daemon_new, 4);
#endif
            //!call the serialize and pass the struct to be serialized into a file
            ser.serializeStructToFileMemMap(data, filename);
    }
    else
    {
        //!default case
        cout << "No Matching struct found." << endl;
    }
    return 0;
};