//
// Created by visxim on 7/17/20.
//

#include "serializer.h"

void  serializer::serializeStructToFileMemMap(UMGR_s UnSerData, string filename)
{
    filename.erase(filename.length()-5 , 5);
    string binaryfilename = "serial"+filename;

    mapped_file_params params;
    params.path          = binaryfilename;
    params.new_file_size = sizeof(UnSerData);
    params.flags         = mapped_file::mapmode::readwrite;

    stream<mapped_file_sink> out(params);

    boost::archive::binary_oarchive oa(out);

    oa << UnSerData;
};
void  serializer::serializeStructToFile(UMGR_s UnSerData, string filename)
{
    filename.erase(filename.length()-5 , 5);
    string binaryfilename = "serial"+filename;

    /* DATA SERIALIZATION with standard file opening (ofstream) */
    // create and open a character archive for output
    std::ofstream ofs("serial"+filename);
    // save data to archive
    boost::archive::binary_oarchive oa(ofs);
    // write class instance to archive
    oa << UnSerData;
    // archive and stream closed when destructors are called
    ofs.close();
};

void serializer::serializeStructToSHM(UMGR_s UnSerData, string filename)
{
    /*
     * tried to outsource the code into a seperated class "shared_memory" but couldnt
     * */
    filename.erase(filename.length()-5 , 5);
    string SHMfilename = "shm"+filename;

    shared_memory_object::remove(SHMfilename.c_str());
    shared_memory_object shm(create_only, SHMfilename.c_str(), read_write);

    shm.truncate(sizeof(UnSerData)); // 10MiB
    mapped_region region(shm, read_write);

    bufferstream bs(std::ios::out);
    bs.buffer(reinterpret_cast<char*>(region.get_address()), region.get_size());
    //std::ostringstream bs;

    boost::archive::text_oarchive oa(bs);
    oa << UnSerData;
};