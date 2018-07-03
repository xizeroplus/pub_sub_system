cmake_minimum_required(VERSION 3.5)
project(EventSender)

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
        include/SENP.icc
        include/set_util.h
        include/Siena.h
        include/siena.h
        include/Siena.icc
        include/sienaconf.h
        include/SienaIO.h
        include/SimpleSiena.h
        include/util.h
        Comm.cc
        EventSender.cpp
        generator.cc
        printer.cc
        PThreads.cc
        SENP.cc
        set_util.h
        Siena.cc
        SienaIO.cc
        sienaserverconf.h
        SimpleSiena.cc
        util.cc)

add_executable(EventSender ${SOURCE_FILES})

find_package(Threads)

target_link_libraries(EventSender ${CMAKE_THREAD_LIBS_INIT})