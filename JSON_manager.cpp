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

        const Value &a = doc["log_mode"];
        assert(a.IsArray());
        for (Value::ConstValueIterator itr = a.Begin(); itr != a.End(); ++itr)
            data.log_mode = itr->GetString();

        data.log_level = doc["log_level"].GetString();
        data.log_dir_path = doc["log_dir_path"].GetString();
        data.ipc_port = doc["ipc_port"].GetUint();
        data.reconnection_retry_offset = doc["reconnection_retry_offset"].GetUint();
        data.msg_buf_size = doc["msg_buf_size"].GetUint();

        cout << "JSON-file transfered into struct." << endl;

#ifdef TRACENEWFILE
        tracepoint(tp_provider, time_tracepoint_daemon, 2);
#endif

        //!pass the config string, created from the struct to receive the checksum
        data.checksum = CRC.createCRC(&data);

#ifdef TRACENEWFILE
        tracepoint(tp_provider, time_tracepoint_daemon, 3);
#endif

        //!call the serialize and pass the struct to be serialized into SHM
        ser.serializeStructToSHM(data, filename);

#ifdef TRACENEWFILE
        tracepoint(tp_provider, time_tracepoint_daemon, 4);
#endif
        //!not usable see function for details
        //ser.copyStructToSHM(data,filename);

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