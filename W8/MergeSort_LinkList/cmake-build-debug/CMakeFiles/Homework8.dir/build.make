# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\ruanjian\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\ruanjian\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Homework8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Homework8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Homework8.dir/flags.make

CMakeFiles/Homework8.dir/main.cpp.obj: CMakeFiles/Homework8.dir/flags.make
CMakeFiles/Homework8.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Homework8.dir/main.cpp.obj"
	F:\ruanjian\mingw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Homework8.dir\main.cpp.obj -c "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\main.cpp"

CMakeFiles/Homework8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework8.dir/main.cpp.i"
	F:\ruanjian\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\main.cpp" > CMakeFiles\Homework8.dir\main.cpp.i

CMakeFiles/Homework8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework8.dir/main.cpp.s"
	F:\ruanjian\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\main.cpp" -o CMakeFiles\Homework8.dir\main.cpp.s

CMakeFiles/Homework8.dir/Sort.cpp.obj: CMakeFiles/Homework8.dir/flags.make
CMakeFiles/Homework8.dir/Sort.cpp.obj: ../Sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Homework8.dir/Sort.cpp.obj"
	F:\ruanjian\mingw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Homework8.dir\Sort.cpp.obj -c "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\Sort.cpp"

CMakeFiles/Homework8.dir/Sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework8.dir/Sort.cpp.i"
	F:\ruanjian\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\Sort.cpp" > CMakeFiles\Homework8.dir\Sort.cpp.i

CMakeFiles/Homework8.dir/Sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework8.dir/Sort.cpp.s"
	F:\ruanjian\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\Sort.cpp" -o CMakeFiles\Homework8.dir\Sort.cpp.s

# Object files for target Homework8
Homework8_OBJECTS = \
"CMakeFiles/Homework8.dir/main.cpp.obj" \
"CMakeFiles/Homework8.dir/Sort.cpp.obj"

# External object files for target Homework8
Homework8_EXTERNAL_OBJECTS =

Homework8.exe: CMakeFiles/Homework8.dir/main.cpp.obj
Homework8.exe: CMakeFiles/Homework8.dir/Sort.cpp.obj
Homework8.exe: CMakeFiles/Homework8.dir/build.make
Homework8.exe: CMakeFiles/Homework8.dir/linklibs.rsp
Homework8.exe: CMakeFiles/Homework8.dir/objects1.rsp
Homework8.exe: CMakeFiles/Homework8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Homework8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Homework8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Homework8.dir/build: Homework8.exe

.PHONY : CMakeFiles/Homework8.dir/build

CMakeFiles/Homework8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Homework8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Homework8.dir/clean

CMakeFiles/Homework8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\cmake-build-debug" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\cmake-build-debug" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\W8\MergeSort_LinkList\cmake-build-debug\CMakeFiles\Homework8.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Homework8.dir/depend

