# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /Users/zekunzhang/CLionProjects/Homework_7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zekunzhang/CLionProjects/Homework_7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/My_cpp_11st.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/My_cpp_11st.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/My_cpp_11st.dir/flags.make

CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.o: CMakeFiles/My_cpp_11st.dir/flags.make
CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.o: ../main_Zekun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zekunzhang/CLionProjects/Homework_7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.o -c /Users/zekunzhang/CLionProjects/Homework_7/main_Zekun.cpp

CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zekunzhang/CLionProjects/Homework_7/main_Zekun.cpp > CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.i

CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zekunzhang/CLionProjects/Homework_7/main_Zekun.cpp -o CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.s

CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.o: CMakeFiles/My_cpp_11st.dir/flags.make
CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.o: ../Polynomial_Zekun.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zekunzhang/CLionProjects/Homework_7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.o -c /Users/zekunzhang/CLionProjects/Homework_7/Polynomial_Zekun.cpp

CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zekunzhang/CLionProjects/Homework_7/Polynomial_Zekun.cpp > CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.i

CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zekunzhang/CLionProjects/Homework_7/Polynomial_Zekun.cpp -o CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.s

# Object files for target My_cpp_11st
My_cpp_11st_OBJECTS = \
"CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.o" \
"CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.o"

# External object files for target My_cpp_11st
My_cpp_11st_EXTERNAL_OBJECTS =

My_cpp_11st: CMakeFiles/My_cpp_11st.dir/main_Zekun.cpp.o
My_cpp_11st: CMakeFiles/My_cpp_11st.dir/Polynomial_Zekun.cpp.o
My_cpp_11st: CMakeFiles/My_cpp_11st.dir/build.make
My_cpp_11st: CMakeFiles/My_cpp_11st.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zekunzhang/CLionProjects/Homework_7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable My_cpp_11st"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/My_cpp_11st.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/My_cpp_11st.dir/build: My_cpp_11st

.PHONY : CMakeFiles/My_cpp_11st.dir/build

CMakeFiles/My_cpp_11st.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/My_cpp_11st.dir/cmake_clean.cmake
.PHONY : CMakeFiles/My_cpp_11st.dir/clean

CMakeFiles/My_cpp_11st.dir/depend:
	cd /Users/zekunzhang/CLionProjects/Homework_7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zekunzhang/CLionProjects/Homework_7 /Users/zekunzhang/CLionProjects/Homework_7 /Users/zekunzhang/CLionProjects/Homework_7/cmake-build-debug /Users/zekunzhang/CLionProjects/Homework_7/cmake-build-debug /Users/zekunzhang/CLionProjects/Homework_7/cmake-build-debug/CMakeFiles/My_cpp_11st.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/My_cpp_11st.dir/depend
