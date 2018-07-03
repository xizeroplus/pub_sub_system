cmake_minimum_required(VERSION 3.5)
project(Siena)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/chrono_time.h
        include/Comm.h
        include/Comm.icc
        include/concurrentQueue.h
        include/data_structure.h
        include/EventServer.h
        include/generator.h
        include/IO.h
        include/IO.icc
        include/oldrein.h
        include/printer.h
        include/PThreads.h
        include/PThreads.icc
        include/rein.h
        include/SENP.h
        include/SENP.icc
        include/set_util.h
        include/Siena.h
        include/siena.h
        include/Siena.icc
        include/sienaconf.h
        include/SienaIO.h
        include/SimpleSiena.h
        include/threadPool.h
        include/util.h
        Comm.cc
        EventServer.cc
        generator.cc
        main.cc
        oldrein.cc
        printer.cc
        PThreads.cc
        rein.cc
        SENP.cc
        set_util.h
        Siena.cc
        SienaIO.cc
        sienaserverconf.h
        SimpleSiena.cc
        util.cc)

add_executable(Siena ${SOURCE_FILES})

find_package(Threads)

target_link_libraries(Siena ${CMAKE_THREAD_LIBS_INIT})