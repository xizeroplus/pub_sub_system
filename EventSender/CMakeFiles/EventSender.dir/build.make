# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/mg2015started/下载/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/mg2015started/下载/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mg2015started/modifiedsiena/5-14/EventSender

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mg2015started/modifiedsiena/5-14/EventSender

# Include any dependencies generated for this target.
include CMakeFiles/EventSender.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EventSender.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EventSender.dir/flags.make

CMakeFiles/EventSender.dir/Comm.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/Comm.cc.o: Comm.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EventSender.dir/Comm.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/Comm.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/Comm.cc

CMakeFiles/EventSender.dir/Comm.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/Comm.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/Comm.cc > CMakeFiles/EventSender.dir/Comm.cc.i

CMakeFiles/EventSender.dir/Comm.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/Comm.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/Comm.cc -o CMakeFiles/EventSender.dir/Comm.cc.s

CMakeFiles/EventSender.dir/Comm.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/Comm.cc.o.requires

CMakeFiles/EventSender.dir/Comm.cc.o.provides: CMakeFiles/EventSender.dir/Comm.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/Comm.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/Comm.cc.o.provides

CMakeFiles/EventSender.dir/Comm.cc.o.provides.build: CMakeFiles/EventSender.dir/Comm.cc.o


CMakeFiles/EventSender.dir/EventSender.cpp.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/EventSender.cpp.o: EventSender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EventSender.dir/EventSender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/EventSender.cpp.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/EventSender.cpp

CMakeFiles/EventSender.dir/EventSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/EventSender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/EventSender.cpp > CMakeFiles/EventSender.dir/EventSender.cpp.i

CMakeFiles/EventSender.dir/EventSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/EventSender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/EventSender.cpp -o CMakeFiles/EventSender.dir/EventSender.cpp.s

CMakeFiles/EventSender.dir/EventSender.cpp.o.requires:

.PHONY : CMakeFiles/EventSender.dir/EventSender.cpp.o.requires

CMakeFiles/EventSender.dir/EventSender.cpp.o.provides: CMakeFiles/EventSender.dir/EventSender.cpp.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/EventSender.cpp.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/EventSender.cpp.o.provides

CMakeFiles/EventSender.dir/EventSender.cpp.o.provides.build: CMakeFiles/EventSender.dir/EventSender.cpp.o


CMakeFiles/EventSender.dir/generator.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/generator.cc.o: generator.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EventSender.dir/generator.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/generator.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/generator.cc

CMakeFiles/EventSender.dir/generator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/generator.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/generator.cc > CMakeFiles/EventSender.dir/generator.cc.i

CMakeFiles/EventSender.dir/generator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/generator.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/generator.cc -o CMakeFiles/EventSender.dir/generator.cc.s

CMakeFiles/EventSender.dir/generator.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/generator.cc.o.requires

CMakeFiles/EventSender.dir/generator.cc.o.provides: CMakeFiles/EventSender.dir/generator.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/generator.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/generator.cc.o.provides

CMakeFiles/EventSender.dir/generator.cc.o.provides.build: CMakeFiles/EventSender.dir/generator.cc.o


CMakeFiles/EventSender.dir/printer.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/printer.cc.o: printer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/EventSender.dir/printer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/printer.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/printer.cc

CMakeFiles/EventSender.dir/printer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/printer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/printer.cc > CMakeFiles/EventSender.dir/printer.cc.i

CMakeFiles/EventSender.dir/printer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/printer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/printer.cc -o CMakeFiles/EventSender.dir/printer.cc.s

CMakeFiles/EventSender.dir/printer.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/printer.cc.o.requires

CMakeFiles/EventSender.dir/printer.cc.o.provides: CMakeFiles/EventSender.dir/printer.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/printer.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/printer.cc.o.provides

CMakeFiles/EventSender.dir/printer.cc.o.provides.build: CMakeFiles/EventSender.dir/printer.cc.o


CMakeFiles/EventSender.dir/PThreads.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/PThreads.cc.o: PThreads.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/EventSender.dir/PThreads.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/PThreads.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/PThreads.cc

CMakeFiles/EventSender.dir/PThreads.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/PThreads.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/PThreads.cc > CMakeFiles/EventSender.dir/PThreads.cc.i

CMakeFiles/EventSender.dir/PThreads.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/PThreads.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/PThreads.cc -o CMakeFiles/EventSender.dir/PThreads.cc.s

CMakeFiles/EventSender.dir/PThreads.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/PThreads.cc.o.requires

CMakeFiles/EventSender.dir/PThreads.cc.o.provides: CMakeFiles/EventSender.dir/PThreads.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/PThreads.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/PThreads.cc.o.provides

CMakeFiles/EventSender.dir/PThreads.cc.o.provides.build: CMakeFiles/EventSender.dir/PThreads.cc.o


CMakeFiles/EventSender.dir/SENP.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/SENP.cc.o: SENP.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/EventSender.dir/SENP.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/SENP.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/SENP.cc

CMakeFiles/EventSender.dir/SENP.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/SENP.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/SENP.cc > CMakeFiles/EventSender.dir/SENP.cc.i

CMakeFiles/EventSender.dir/SENP.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/SENP.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/SENP.cc -o CMakeFiles/EventSender.dir/SENP.cc.s

CMakeFiles/EventSender.dir/SENP.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/SENP.cc.o.requires

CMakeFiles/EventSender.dir/SENP.cc.o.provides: CMakeFiles/EventSender.dir/SENP.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/SENP.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/SENP.cc.o.provides

CMakeFiles/EventSender.dir/SENP.cc.o.provides.build: CMakeFiles/EventSender.dir/SENP.cc.o


CMakeFiles/EventSender.dir/Siena.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/Siena.cc.o: Siena.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/EventSender.dir/Siena.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/Siena.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/Siena.cc

CMakeFiles/EventSender.dir/Siena.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/Siena.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/Siena.cc > CMakeFiles/EventSender.dir/Siena.cc.i

CMakeFiles/EventSender.dir/Siena.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/Siena.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/Siena.cc -o CMakeFiles/EventSender.dir/Siena.cc.s

CMakeFiles/EventSender.dir/Siena.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/Siena.cc.o.requires

CMakeFiles/EventSender.dir/Siena.cc.o.provides: CMakeFiles/EventSender.dir/Siena.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/Siena.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/Siena.cc.o.provides

CMakeFiles/EventSender.dir/Siena.cc.o.provides.build: CMakeFiles/EventSender.dir/Siena.cc.o


CMakeFiles/EventSender.dir/SienaIO.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/SienaIO.cc.o: SienaIO.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/EventSender.dir/SienaIO.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/SienaIO.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/SienaIO.cc

CMakeFiles/EventSender.dir/SienaIO.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/SienaIO.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/SienaIO.cc > CMakeFiles/EventSender.dir/SienaIO.cc.i

CMakeFiles/EventSender.dir/SienaIO.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/SienaIO.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/SienaIO.cc -o CMakeFiles/EventSender.dir/SienaIO.cc.s

CMakeFiles/EventSender.dir/SienaIO.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/SienaIO.cc.o.requires

CMakeFiles/EventSender.dir/SienaIO.cc.o.provides: CMakeFiles/EventSender.dir/SienaIO.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/SienaIO.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/SienaIO.cc.o.provides

CMakeFiles/EventSender.dir/SienaIO.cc.o.provides.build: CMakeFiles/EventSender.dir/SienaIO.cc.o


CMakeFiles/EventSender.dir/SimpleSiena.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/SimpleSiena.cc.o: SimpleSiena.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/EventSender.dir/SimpleSiena.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/SimpleSiena.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/SimpleSiena.cc

CMakeFiles/EventSender.dir/SimpleSiena.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/SimpleSiena.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/SimpleSiena.cc > CMakeFiles/EventSender.dir/SimpleSiena.cc.i

CMakeFiles/EventSender.dir/SimpleSiena.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/SimpleSiena.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/SimpleSiena.cc -o CMakeFiles/EventSender.dir/SimpleSiena.cc.s

CMakeFiles/EventSender.dir/SimpleSiena.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/SimpleSiena.cc.o.requires

CMakeFiles/EventSender.dir/SimpleSiena.cc.o.provides: CMakeFiles/EventSender.dir/SimpleSiena.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/SimpleSiena.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/SimpleSiena.cc.o.provides

CMakeFiles/EventSender.dir/SimpleSiena.cc.o.provides.build: CMakeFiles/EventSender.dir/SimpleSiena.cc.o


CMakeFiles/EventSender.dir/util.cc.o: CMakeFiles/EventSender.dir/flags.make
CMakeFiles/EventSender.dir/util.cc.o: util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/EventSender.dir/util.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EventSender.dir/util.cc.o -c /home/mg2015started/modifiedsiena/5-14/EventSender/util.cc

CMakeFiles/EventSender.dir/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EventSender.dir/util.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mg2015started/modifiedsiena/5-14/EventSender/util.cc > CMakeFiles/EventSender.dir/util.cc.i

CMakeFiles/EventSender.dir/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EventSender.dir/util.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mg2015started/modifiedsiena/5-14/EventSender/util.cc -o CMakeFiles/EventSender.dir/util.cc.s

CMakeFiles/EventSender.dir/util.cc.o.requires:

.PHONY : CMakeFiles/EventSender.dir/util.cc.o.requires

CMakeFiles/EventSender.dir/util.cc.o.provides: CMakeFiles/EventSender.dir/util.cc.o.requires
	$(MAKE) -f CMakeFiles/EventSender.dir/build.make CMakeFiles/EventSender.dir/util.cc.o.provides.build
.PHONY : CMakeFiles/EventSender.dir/util.cc.o.provides

CMakeFiles/EventSender.dir/util.cc.o.provides.build: CMakeFiles/EventSender.dir/util.cc.o


# Object files for target EventSender
EventSender_OBJECTS = \
"CMakeFiles/EventSender.dir/Comm.cc.o" \
"CMakeFiles/EventSender.dir/EventSender.cpp.o" \
"CMakeFiles/EventSender.dir/generator.cc.o" \
"CMakeFiles/EventSender.dir/printer.cc.o" \
"CMakeFiles/EventSender.dir/PThreads.cc.o" \
"CMakeFiles/EventSender.dir/SENP.cc.o" \
"CMakeFiles/EventSender.dir/Siena.cc.o" \
"CMakeFiles/EventSender.dir/SienaIO.cc.o" \
"CMakeFiles/EventSender.dir/SimpleSiena.cc.o" \
"CMakeFiles/EventSender.dir/util.cc.o"

# External object files for target EventSender
EventSender_EXTERNAL_OBJECTS =

EventSender: CMakeFiles/EventSender.dir/Comm.cc.o
EventSender: CMakeFiles/EventSender.dir/EventSender.cpp.o
EventSender: CMakeFiles/EventSender.dir/generator.cc.o
EventSender: CMakeFiles/EventSender.dir/printer.cc.o
EventSender: CMakeFiles/EventSender.dir/PThreads.cc.o
EventSender: CMakeFiles/EventSender.dir/SENP.cc.o
EventSender: CMakeFiles/EventSender.dir/Siena.cc.o
EventSender: CMakeFiles/EventSender.dir/SienaIO.cc.o
EventSender: CMakeFiles/EventSender.dir/SimpleSiena.cc.o
EventSender: CMakeFiles/EventSender.dir/util.cc.o
EventSender: CMakeFiles/EventSender.dir/build.make
EventSender: CMakeFiles/EventSender.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable EventSender"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EventSender.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EventSender.dir/build: EventSender

.PHONY : CMakeFiles/EventSender.dir/build

CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/Comm.cc.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/EventSender.cpp.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/generator.cc.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/printer.cc.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/PThreads.cc.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/SENP.cc.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/Siena.cc.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/SienaIO.cc.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/SimpleSiena.cc.o.requires
CMakeFiles/EventSender.dir/requires: CMakeFiles/EventSender.dir/util.cc.o.requires

.PHONY : CMakeFiles/EventSender.dir/requires

CMakeFiles/EventSender.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EventSender.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EventSender.dir/clean

CMakeFiles/EventSender.dir/depend:
	cd /home/mg2015started/modifiedsiena/5-14/EventSender && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mg2015started/modifiedsiena/5-14/EventSender /home/mg2015started/modifiedsiena/5-14/EventSender /home/mg2015started/modifiedsiena/5-14/EventSender /home/mg2015started/modifiedsiena/5-14/EventSender /home/mg2015started/modifiedsiena/5-14/EventSender/CMakeFiles/EventSender.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EventSender.dir/depend

