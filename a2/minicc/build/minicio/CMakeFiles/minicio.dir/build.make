# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tangzhen/csc488/a2/minicc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tangzhen/csc488/a2/minicc/build

# Include any dependencies generated for this target.
include minicio/CMakeFiles/minicio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include minicio/CMakeFiles/minicio.dir/compiler_depend.make

# Include the progress variables for this target.
include minicio/CMakeFiles/minicio.dir/progress.make

# Include the compile flags for this target's objects.
include minicio/CMakeFiles/minicio.dir/flags.make

minicio/CMakeFiles/minicio.dir/minicio.c.o: minicio/CMakeFiles/minicio.dir/flags.make
minicio/CMakeFiles/minicio.dir/minicio.c.o: /home/tangzhen/csc488/a2/minicc/minicio/minicio.c
minicio/CMakeFiles/minicio.dir/minicio.c.o: minicio/CMakeFiles/minicio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tangzhen/csc488/a2/minicc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object minicio/CMakeFiles/minicio.dir/minicio.c.o"
	cd /home/tangzhen/csc488/a2/minicc/build/minicio && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT minicio/CMakeFiles/minicio.dir/minicio.c.o -MF CMakeFiles/minicio.dir/minicio.c.o.d -o CMakeFiles/minicio.dir/minicio.c.o -c /home/tangzhen/csc488/a2/minicc/minicio/minicio.c

minicio/CMakeFiles/minicio.dir/minicio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minicio.dir/minicio.c.i"
	cd /home/tangzhen/csc488/a2/minicc/build/minicio && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tangzhen/csc488/a2/minicc/minicio/minicio.c > CMakeFiles/minicio.dir/minicio.c.i

minicio/CMakeFiles/minicio.dir/minicio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minicio.dir/minicio.c.s"
	cd /home/tangzhen/csc488/a2/minicc/build/minicio && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tangzhen/csc488/a2/minicc/minicio/minicio.c -o CMakeFiles/minicio.dir/minicio.c.s

# Object files for target minicio
minicio_OBJECTS = \
"CMakeFiles/minicio.dir/minicio.c.o"

# External object files for target minicio
minicio_EXTERNAL_OBJECTS =

minicio/libminicio.a: minicio/CMakeFiles/minicio.dir/minicio.c.o
minicio/libminicio.a: minicio/CMakeFiles/minicio.dir/build.make
minicio/libminicio.a: minicio/CMakeFiles/minicio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tangzhen/csc488/a2/minicc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libminicio.a"
	cd /home/tangzhen/csc488/a2/minicc/build/minicio && $(CMAKE_COMMAND) -P CMakeFiles/minicio.dir/cmake_clean_target.cmake
	cd /home/tangzhen/csc488/a2/minicc/build/minicio && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minicio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
minicio/CMakeFiles/minicio.dir/build: minicio/libminicio.a
.PHONY : minicio/CMakeFiles/minicio.dir/build

minicio/CMakeFiles/minicio.dir/clean:
	cd /home/tangzhen/csc488/a2/minicc/build/minicio && $(CMAKE_COMMAND) -P CMakeFiles/minicio.dir/cmake_clean.cmake
.PHONY : minicio/CMakeFiles/minicio.dir/clean

minicio/CMakeFiles/minicio.dir/depend:
	cd /home/tangzhen/csc488/a2/minicc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tangzhen/csc488/a2/minicc /home/tangzhen/csc488/a2/minicc/minicio /home/tangzhen/csc488/a2/minicc/build /home/tangzhen/csc488/a2/minicc/build/minicio /home/tangzhen/csc488/a2/minicc/build/minicio/CMakeFiles/minicio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : minicio/CMakeFiles/minicio.dir/depend

