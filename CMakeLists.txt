cmake_minimum_required(VERSION 3.16)
project(Configuration_daemon)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
SET(PLATFORM_SPECIFIC_LIBS "-lpthread")

#organize all sourcefiles in a variable
set(SOURCE_FILES main.cpp
        JSON_manager.cpp includes/JSON_manager.h includes/data_storage.h includes/deserializer.h deserializer.cpp file.cpp includes/file.h shared_memory.cpp includes/shared_memory.h process_manager.cpp includes/process_manager.h process_manager_factory.cpp includes/process_manager_factory.h update_manager.cpp includes/update_manager.h checksum_manager.cpp includes/checksum_manager.h serializer.cpp includes/serializer.h message_manager.cpp includes/message_manager.h)

add_executable(Configuration_daemon ${SOURCE_FILES})

include_directories(~/CLionProjects/Configuration_daemon/includes/
        ~/CLionProjects/Configuration_daemon/includes/rapidjson
        ~/CLionProjects/Configuration_daemon/
        ~/home/visxim/boost_1_73_0/)

find_library(LIB_RT rt)

target_link_libraries(${PROJECT_NAME} libboost_serialization.a libboost_iostreams.a
        ${LIB_RT})