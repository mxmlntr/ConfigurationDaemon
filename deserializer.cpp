//
// Created by visxim on 7/9/20.
//

#include "deserializer.h"

deserializer::deserializer()
{

};

deserializer::deserializer(string name)
{
    filename = name;
};

void deserializer::setfilename(string name)
{
    filename = name;
};

void deserializer::deserializeStructFromFile(UMGR_s *Data_s)
{
    filename.erase(filename.end(),filename.end()-5);
    string SHMfilename = "serial"+filename;

    {
        // create and open an archive for input
        std::ifstream ifs(SHMfilename);
        boost::archive::binary_iarchive ia(ifs);
        // read class state from archive
        ia >> *Data_s;
        // archive and stream closed when destructors are called
        ifs.close();
    }
};

void deserializer::deserializeStructFromSHM(UMGR_s *Data_s)
{
    filename.erase(filename.length()-5 , 5);
    string SHMfilename = "shm"+filename;

    shared_memory_object shm(open_only, SHMfilename.c_str() , read_only);
    mapped_region region(shm, read_only);

    bufferstream bs(std::ios::in);
    bs.buffer(reinterpret_cast<char*>(region.get_address()), region.get_size());
    //std::istringstream bs;

    boost::archive::text_iarchive ia(bs);
    ia >> *Data_s;

};


