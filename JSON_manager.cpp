//
// Created by visxim on 7/17/20.
//

#include "JSON_manager.h"

unsigned int JSON_manager::read_file(string filename)
{
    string buf;
    string json;

    string binaryfilename = "/home/visxim/CLionProjects/ShareFolder/"+filename;

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

    //convert the read string into const char* and parse to document
    const char* jsn = json.c_str();

    doc.Parse(jsn);

    cout << "JSON-file successfully parsed.\n";
    return 1;
};

string JSON_manager::get_json_config_string()
{
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
unsigned int JSON_manager::parseToStructandSerialize(string filename)
{

    if (!filename.compare("UMGR.json"))
    {
        //create the matching struct
        UMGR_s data;
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

        cout << "JSON-file transfered into struct." << endl;

        //pass the config string, created from the struct to receive the checksum
        data.checksum = CRC.createCRC(&data);

        //call the serialize and pass the struct to be serialized into SHM
        ser.serializeStructToSHM(data, filename);

        //not usable
        //ser.copyStructToSHM(data,filename);

        //call the serialize and pass the struct to be serialized into a file
        ser.serializeStructToFileMemMap(data, filename);

    }
    else
    {
        //default case
        cout << "No Matching struct found." << endl;
    }
    return 0;
};