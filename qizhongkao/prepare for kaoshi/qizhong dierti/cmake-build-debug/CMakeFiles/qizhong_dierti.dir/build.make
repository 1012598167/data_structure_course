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
CMAKE_SOURCE_DIR = "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/qizhong_dierti.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/qizhong_dierti.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qizhong_dierti.dir/flags.make

CMakeFiles/qizhong_dierti.dir/main.cpp.obj: CMakeFiles/qizhong_dierti.dir/flags.make
CMakeFiles/qizhong_dierti.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/qizhong_dierti.dir/main.cpp.obj"
	F:\ruanjian\mingw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\qizhong_dierti.dir\main.cpp.obj -c "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\main.cpp"

CMakeFiles/qizhong_dierti.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qizhong_dierti.dir/main.cpp.i"
	F:\ruanjian\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\main.cpp" > CMakeFiles\qizhong_dierti.dir\main.cpp.i

CMakeFiles/qizhong_dierti.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qizhong_dierti.dir/main.cpp.s"
	F:\ruanjian\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\main.cpp" -o CMakeFiles\qizhong_dierti.dir\main.cpp.s

# Object files for target qizhong_dierti
qizhong_dierti_OBJECTS = \
"CMakeFiles/qizhong_dierti.dir/main.cpp.obj"

# External object files for target qizhong_dierti
qizhong_dierti_EXTERNAL_OBJECTS =

qizhong_dierti.exe: CMakeFiles/qizhong_dierti.dir/main.cpp.obj
qizhong_dierti.exe: CMakeFiles/qizhong_dierti.dir/build.make
qizhong_dierti.exe: CMakeFiles/qizhong_dierti.dir/linklibs.rsp
qizhong_dierti.exe: CMakeFiles/qizhong_dierti.dir/objects1.rsp
qizhong_dierti.exe: CMakeFiles/qizhong_dierti.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable qizhong_dierti.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\qizhong_dierti.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qizhong_dierti.dir/build: qizhong_dierti.exe

.PHONY : CMakeFiles/qizhong_dierti.dir/build

CMakeFiles/qizhong_dierti.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\qizhong_dierti.dir\cmake_clean.cmake
.PHONY : CMakeFiles/qizhong_dierti.dir/clean

CMakeFiles/qizhong_dierti.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\cmake-build-debug" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\cmake-build-debug" "C:\Users\mathskiller\Desktop\20181003kaishiyong epan xuexi\c++ shujujiegou\qizhong dierti\cmake-build-debug\CMakeFiles\qizhong_dierti.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/qizhong_dierti.dir/depend

