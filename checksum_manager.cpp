//
// Created by visxim on 7/17/20.
//

#include "checksum_manager.h"

int checksum_manager::createCRC(UMGR_s *CRCdata)
{

    //unsigned char *p = (unsigned char *)CRCdata;
   // for (int i=0; i<sizeof(CRCdata); i++) {
   //     cout << p[i] << endl;
   // }
    return 1;


    //boost::crc_32_type result;
    //result.process_bytes(crcString.data(), crcString.length());
    //return result.checksum();

    /*
    boost::crc_32_type  result;

    for ( int i = 1 ; i < 100 ; ++i )
    {
        std::ifstream  ifs( filename, std::ios_base::binary );

        if ( ifs )
        {
            do
            {
                char  buffer[ buffer_size ];

                ifs.read( buffer, buffer_size );
                result.process_bytes( buffer, ifs.gcount() );
            } while ( ifs );
        }
        else
        {
            std::cerr << "Failed to open file '" << filename << "'."
                      << std::endl;
        }
    }
    //std::cout << std::hex << std::uppercase << result.checksum() << std::endl;
    return result;
     */
};