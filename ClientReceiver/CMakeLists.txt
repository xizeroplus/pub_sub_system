cmake_minimum_required(VERSION 3.5)
project(ClientReceiver)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    include/chrono_time.h
    include/Comm.h
    include/Comm.icc
    include/data_structure.h
    include/generator.h
    include/IO.h
    include/IO.icc
    include/printer.h
    include/PThreads.h
    include/PThreads.icc
    include/SENP.h
    include/Siena.h
    include/siena.h
    include/Siena.icc
    include/sienaconf.h
    include/SienaIO.h
    include/SimpleSiena.h
    include/util.h
    Comm.cc
    generator.cc
    printer.cc
    PThreads.cc
    SENP.cc
    set_util.h
    Siena.cc
    SienaIO.cc
    sienaserverconf.h
    SimpleSiena.cc
    Subscriber.cpp
    util.cc)

add_executable(ClientReceiver ${SOURCE_FILES})

find_package(Threads)

target_link_libraries(ClientReceiver ${CMAKE_THREAD_LIBS_INIT})