/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  /home/visxim/CLionProjects/Configuration_daemon/serializer.cpp
 *        \brief  Serializer for serializing the parsed configuration data
 *
 *      \details Serializer for serializing data to both shared memory and files
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "serializer.h"

/*!
* \brief Function for serializing the struct into a file using memory mapping
*
*/
void  serializer::serializeStructToFileMemMap(UMGR_s UnSerData, string filename)
{
    //! Erase the ".json" ending and add the "serial" tag
    filename.erase(filename.length()-5 , 5);
    string binaryfilename = "/home/visxim/CLionProjects/ShareFolder/serial"+filename;

    //! Set the mapped file parameters
    mapped_file_params params;
    params.path          = binaryfilename;
    params.new_file_size = sizeof(UnSerData);
    params.flags         = mapped_file::mapmode::readwrite;

    //! Create a stream with the parameters
    stream<mapped_file_sink> out(params);

    //! Create the output archive
    boost::archive::binary_oarchive oa(out);

    //! Serialize the data to the file
    oa << UnSerData;
};

/*!
* \brief Function for serializing the struct into a file using memory mapping
*
*/
void  serializer::serializeStructToFileMemMap(EXMPLE_s UnSerData, string filename)
{
    //! Erase the ".json" ending and add the "serial" tag
    filename.erase(filename.length()-5 , 5);
    string binaryfilename = "/home/visxim/CLionProjects/ShareFolder/serial"+filename;

    //! Set the mapped file parameters
    mapped_file_params params;
    params.path          = binaryfilename;
    params.new_file_size = sizeof(UnSerData);
    params.flags         = mapped_file::mapmode::readwrite;

    //! Create a stream with the parameters
    stream<mapped_file_sink> out(params);

    //! Create the output archive
    boost::archive::binary_oarchive oa(out);

    //! Serialize the data to the file
    oa << UnSerData;
};

/*!
* \brief Function for serializing the struct to a shared memory segment
*
* \details This function needs to be overloaded for different configration files
*/
void serializer::serializeStructToSHM(UMGR_s UnSerData, string filename)
{
    /*!
     * tried to outsource the code into a seperated class "shared_memory" but couldnt
     * */
    //! Erase the ".json" ending and add the "shm" tag
    filename.erase(filename.length()-5 , 5);
    string SHMfilename = "shm"+filename;

    //! Remove the shared memory object if it is still present
    shared_memory_object::remove(SHMfilename.c_str());
    //! create the shared memory object
    shared_memory_object shm(open_or_create, SHMfilename.c_str(), read_write);

    //! Setting the size of the SHM
    shm.truncate(sizeof(UnSerData));
    //! Map the shared memory into the address space
    mapped_region region(shm, read_write);

    //! create the output stream
    bufferstream bs(std::ios::out);
    bs.buffer(reinterpret_cast<char*>(region.get_address()), region.get_size());

    //! create the output archive
    boost::archive::text_oarchive oa(bs);

    //! Serialize the data to the file
    oa << UnSerData;
};

/*!
* \brief Function for serializing the struct to a shared memory segment
*
* \details This function needs to be overloaded for different configration files
*/
void serializer::serializeStructToSHM(EXMPLE_s UnSerData, string filename)
{
    /*!
     * tried to outsource the code into a seperated class "shared_memory" but couldnt
     * */
    //! Erase the ".json" ending and add the "shm" tag
    filename.erase(filename.length()-5 , 5);
    string SHMfilename = "shm"+filename;

    //! Remove the shared memory object if it is still present
    shared_memory_object::remove(SHMfilename.c_str());
    //! create the shared memory object
    shared_memory_object shm(open_or_create, SHMfilename.c_str(), read_write);

    //! Setting the size of the SHM
    shm.truncate(sizeof(UnSerData));
    //! Map the shared memory into the address space
    mapped_region region(shm, read_write);

    //! create the output stream
    bufferstream bs(std::ios::out);
    bs.buffer(reinterpret_cast<char*>(region.get_address()), region.get_size());

    //! create the output archive
    boost::archive::text_oarchive oa(bs);

    //! Serialize the data to the file
    oa << UnSerData;
};

/*!
* \brief Function for serializing the struct into a file using iostream
*
*/
void  serializer::serializeStructToFile(UMGR_s UnSerData, string filename)
{
    //! Erase the ".json" ending and add the "serial" tag
    filename.erase(filename.length()-5 , 5);
    string binaryfilename = "/home/visxim/CLionProjects/ShareFolder/serial"+filename;

    //! Open an output filestream
    std::ofstream ofs("serial"+filename);

    //! Create the output archive
    boost::archive::binary_oarchive oa(ofs);

    //! Serialize the data to the file
    oa << UnSerData;

    //! Close output stream
    ofs.close();
};

/*!
 * \brief Not usable because memcpy does only work for POD and string is not a POD type
 *
 * */
void serializer::copyStructToSHM(UMGR_s UnSerData, string filename)
{
    filename.erase(filename.length()-5 , 5);
    string SHMfilename = "shm"+filename;

    shared_memory_object::remove(SHMfilename.c_str());
    shared_memory_object shm(create_only, SHMfilename.c_str(), read_write);

    shm.truncate(sizeof(UnSerData));
    mapped_region region(shm, read_write);

    memcpy(region.get_address(),&UnSerData,sizeof(UnSerData));
    cout << "Data copied to SHM." << endl;
};