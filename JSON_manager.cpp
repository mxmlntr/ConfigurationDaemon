//
// Created by visxim on 7/17/20.
//

#include "JSON_manager.h"

uint8_t JSON_manager::read_file(string filename)
{
    string buf;
    string json;

    ifstream test (filename);
    if (test.is_open())
    {
        while ( getline (test,buf) )
        {
            json.append(buf);
        }
        test.close();
    }
    else cout << "Unable to open file\n";

    //convert the read string into const char* and parse to document
    const char* jsn = json.c_str();

    doc.Parse(jsn);

    cout << "JSON-file successfully parsed.\n";
    return 1;
};

string JSON_manager::get_json_config_string()
{
    //cout<<doc["log_mode"].GetType();
    StringBuffer output;
    Writer<StringBuffer> writer(output);
    doc.Accept(writer);
    return output.GetString();
};

//TODO: Create a virtual function to be implemented by the the object?
/*
 * Function for parsing the interpreted JSON data from the file into a predefinied struct (to find in data_storage.h)
 *
 * */
uint8_t JSON_manager::parseToStructandSerialize(string filename) {

    if (!filename.compare("UMGR.json")) {
        //create the matching struct
        static UMGR_s data;
        //parse all the data into this struct
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

        //pass the config string, created from the struct to receive the checksum
        data.checksum = crc.createCRC(get_json_config_string());

        //call the serialize and pass the struct to be serialized into a file
        ser.serializeStructToFileMemMap(data, filename);

        //call the serialize and pass the struct to be serialized into SHM
        ser.serializeStructToSHM(data, filename);
    } else {
        //default case
        cout << "No Matching struct found." << endl;
    }
    return 0;
};