# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zekunzhang/CLionProjects/Homework_11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zekunzhang/CLionProjects/Homework_11/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Homework_11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Homework_11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Homework_11.dir/flags.make

CMakeFiles/Homework_11.dir/Main_Zekun.cpp.o: CMakeFiles/Homework_11.dir/flags.make
CMakeFiles/Homework_11.dir/Main_Zekun.cpp.o: ../Main_Zekun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zekunzhang/CLionProjects/Homework_11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Homework_11.dir/Main_Zekun.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework_11.dir/Main_Zekun.cpp.o -c /Users/zekunzhang/CLionProjects/Homework_11/Main_Zekun.cpp

CMakeFiles/Homework_11.dir/Main_Zekun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework_11.dir/Main_Zekun.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zekunzhang/CLionProjects/Homework_11/Main_Zekun.cpp > CMakeFiles/Homework_11.dir/Main_Zekun.cpp.i

CMakeFiles/Homework_11.dir/Main_Zekun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework_11.dir/Main_Zekun.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zekunzhang/CLionProjects/Homework_11/Main_Zekun.cpp -o CMakeFiles/Homework_11.dir/Main_Zekun.cpp.s

CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.o: CMakeFiles/Homework_11.dir/flags.make
CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.o: ../Booklist_Zekun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zekunzhang/CLionProjects/Homework_11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.o -c /Users/zekunzhang/CLionProjects/Homework_11/Booklist_Zekun.cpp

CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zekunzhang/CLionProjects/Homework_11/Booklist_Zekun.cpp > CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.i

CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zekunzhang/CLionProjects/Homework_11/Booklist_Zekun.cpp -o CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.s

# Object files for target Homework_11
Homework_11_OBJECTS = \
"CMakeFiles/Homework_11.dir/Main_Zekun.cpp.o" \
"CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.o"

# External object files for target Homework_11
Homework_11_EXTERNAL_OBJECTS =

Homework_11: CMakeFiles/Homework_11.dir/Main_Zekun.cpp.o
Homework_11: CMakeFiles/Homework_11.dir/Booklist_Zekun.cpp.o
Homework_11: CMakeFiles/Homework_11.dir/build.make
Homework_11: CMakeFiles/Homework_11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zekunzhang/CLionProjects/Homework_11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Homework_11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Homework_11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Homework_11.dir/build: Homework_11

.PHONY : CMakeFiles/Homework_11.dir/build

CMakeFiles/Homework_11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Homework_11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Homework_11.dir/clean

CMakeFiles/Homework_11.dir/depend:
	cd /Users/zekunzhang/CLionProjects/Homework_11/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zekunzhang/CLionProjects/Homework_11 /Users/zekunzhang/CLionProjects/Homework_11 /Users/zekunzhang/CLionProjects/Homework_11/cmake-build-debug /Users/zekunzhang/CLionProjects/Homework_11/cmake-build-debug /Users/zekunzhang/CLionProjects/Homework_11/cmake-build-debug/CMakeFiles/Homework_11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Homework_11.dir/depend

