# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/damaris/OOP/Table

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/damaris/OOP/Table/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Table.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Table.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Table.dir/flags.make

CMakeFiles/Table.dir/main.cpp.o: CMakeFiles/Table.dir/flags.make
CMakeFiles/Table.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/damaris/OOP/Table/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Table.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Table.dir/main.cpp.o -c /Users/damaris/OOP/Table/main.cpp

CMakeFiles/Table.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Table.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/damaris/OOP/Table/main.cpp > CMakeFiles/Table.dir/main.cpp.i

CMakeFiles/Table.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Table.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/damaris/OOP/Table/main.cpp -o CMakeFiles/Table.dir/main.cpp.s

CMakeFiles/Table.dir/Tests/table.cpp.o: CMakeFiles/Table.dir/flags.make
CMakeFiles/Table.dir/Tests/table.cpp.o: ../Tests/table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/damaris/OOP/Table/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Table.dir/Tests/table.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Table.dir/Tests/table.cpp.o -c /Users/damaris/OOP/Table/Tests/table.cpp

CMakeFiles/Table.dir/Tests/table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Table.dir/Tests/table.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/damaris/OOP/Table/Tests/table.cpp > CMakeFiles/Table.dir/Tests/table.cpp.i

CMakeFiles/Table.dir/Tests/table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Table.dir/Tests/table.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/damaris/OOP/Table/Tests/table.cpp -o CMakeFiles/Table.dir/Tests/table.cpp.s

CMakeFiles/Table.dir/Tests/test.cpp.o: CMakeFiles/Table.dir/flags.make
CMakeFiles/Table.dir/Tests/test.cpp.o: ../Tests/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/damaris/OOP/Table/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Table.dir/Tests/test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Table.dir/Tests/test.cpp.o -c /Users/damaris/OOP/Table/Tests/test.cpp

CMakeFiles/Table.dir/Tests/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Table.dir/Tests/test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/damaris/OOP/Table/Tests/test.cpp > CMakeFiles/Table.dir/Tests/test.cpp.i

CMakeFiles/Table.dir/Tests/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Table.dir/Tests/test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/damaris/OOP/Table/Tests/test.cpp -o CMakeFiles/Table.dir/Tests/test.cpp.s

# Object files for target Table
Table_OBJECTS = \
"CMakeFiles/Table.dir/main.cpp.o" \
"CMakeFiles/Table.dir/Tests/table.cpp.o" \
"CMakeFiles/Table.dir/Tests/test.cpp.o"

# External object files for target Table
Table_EXTERNAL_OBJECTS =

Table: CMakeFiles/Table.dir/main.cpp.o
Table: CMakeFiles/Table.dir/Tests/table.cpp.o
Table: CMakeFiles/Table.dir/Tests/test.cpp.o
Table: CMakeFiles/Table.dir/build.make
Table: lib/libgtestd.a
Table: lib/libgtest_maind.a
Table: lib/libgtestd.a
Table: CMakeFiles/Table.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/damaris/OOP/Table/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Table"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Table.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Table.dir/build: Table

.PHONY : CMakeFiles/Table.dir/build

CMakeFiles/Table.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Table.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Table.dir/clean

CMakeFiles/Table.dir/depend:
	cd /Users/damaris/OOP/Table/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/damaris/OOP/Table /Users/damaris/OOP/Table /Users/damaris/OOP/Table/cmake-build-debug /Users/damaris/OOP/Table/cmake-build-debug /Users/damaris/OOP/Table/cmake-build-debug/CMakeFiles/Table.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Table.dir/depend
