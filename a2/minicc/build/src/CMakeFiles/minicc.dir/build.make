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
include src/CMakeFiles/minicc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/minicc.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/minicc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/minicc.dir/flags.make

src/CMakeFiles/minicc.dir/main.cpp.o: src/CMakeFiles/minicc.dir/flags.make
src/CMakeFiles/minicc.dir/main.cpp.o: /home/tangzhen/csc488/a2/minicc/src/main.cpp
src/CMakeFiles/minicc.dir/main.cpp.o: src/CMakeFiles/minicc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tangzhen/csc488/a2/minicc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/minicc.dir/main.cpp.o"
	cd /home/tangzhen/csc488/a2/minicc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minicc.dir/main.cpp.o -MF CMakeFiles/minicc.dir/main.cpp.o.d -o CMakeFiles/minicc.dir/main.cpp.o -c /home/tangzhen/csc488/a2/minicc/src/main.cpp

src/CMakeFiles/minicc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minicc.dir/main.cpp.i"
	cd /home/tangzhen/csc488/a2/minicc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tangzhen/csc488/a2/minicc/src/main.cpp > CMakeFiles/minicc.dir/main.cpp.i

src/CMakeFiles/minicc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minicc.dir/main.cpp.s"
	cd /home/tangzhen/csc488/a2/minicc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tangzhen/csc488/a2/minicc/src/main.cpp -o CMakeFiles/minicc.dir/main.cpp.s

# Object files for target minicc
minicc_OBJECTS = \
"CMakeFiles/minicc.dir/main.cpp.o"

# External object files for target minicc
minicc_EXTERNAL_OBJECTS = \
"/home/tangzhen/csc488/a2/minicc/build/grammars/CMakeFiles/grammar.dir/MiniC/MiniCListener.cpp.o" \
"/home/tangzhen/csc488/a2/minicc/build/grammars/CMakeFiles/grammar.dir/MiniC/MiniCBaseListener.cpp.o" \
"/home/tangzhen/csc488/a2/minicc/build/grammars/CMakeFiles/grammar.dir/MiniC/MiniCBaseVisitor.cpp.o" \
"/home/tangzhen/csc488/a2/minicc/build/grammars/CMakeFiles/grammar.dir/MiniC/MiniCVisitor.cpp.o" \
"/home/tangzhen/csc488/a2/minicc/build/grammars/CMakeFiles/grammar.dir/MiniC/MiniCParser.cpp.o" \
"/home/tangzhen/csc488/a2/minicc/build/grammars/CMakeFiles/grammar.dir/MiniC/MiniCLexer.cpp.o"

src/minicc: src/CMakeFiles/minicc.dir/main.cpp.o
src/minicc: grammars/CMakeFiles/grammar.dir/MiniC/MiniCListener.cpp.o
src/minicc: grammars/CMakeFiles/grammar.dir/MiniC/MiniCBaseListener.cpp.o
src/minicc: grammars/CMakeFiles/grammar.dir/MiniC/MiniCBaseVisitor.cpp.o
src/minicc: grammars/CMakeFiles/grammar.dir/MiniC/MiniCVisitor.cpp.o
src/minicc: grammars/CMakeFiles/grammar.dir/MiniC/MiniCParser.cpp.o
src/minicc: grammars/CMakeFiles/grammar.dir/MiniC/MiniCLexer.cpp.o
src/minicc: src/CMakeFiles/minicc.dir/build.make
src/minicc: src/libirgen.a
src/minicc: src/libast.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMSupport.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMBitWriter.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMCore.a
src/minicc: /usr/local/lib/libantlr4-runtime.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMAnalysis.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMProfileData.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMSymbolize.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMDebugInfoPDB.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMDebugInfoMSF.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMDebugInfoDWARF.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMObject.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMBitReader.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMCore.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMRemarks.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMBitstreamReader.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMMCParser.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMMC.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMDebugInfoCodeView.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMTextAPI.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMBinaryFormat.a
src/minicc: /usr/lib/llvm-15/lib/libLLVMSupport.a
src/minicc: /usr/lib/x86_64-linux-gnu/libz.so
src/minicc: /usr/lib/x86_64-linux-gnu/libtinfo.so
src/minicc: /usr/lib/llvm-15/lib/libLLVMDemangle.a
src/minicc: src/CMakeFiles/minicc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tangzhen/csc488/a2/minicc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable minicc"
	cd /home/tangzhen/csc488/a2/minicc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minicc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/minicc.dir/build: src/minicc
.PHONY : src/CMakeFiles/minicc.dir/build

src/CMakeFiles/minicc.dir/clean:
	cd /home/tangzhen/csc488/a2/minicc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/minicc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/minicc.dir/clean

src/CMakeFiles/minicc.dir/depend:
	cd /home/tangzhen/csc488/a2/minicc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tangzhen/csc488/a2/minicc /home/tangzhen/csc488/a2/minicc/src /home/tangzhen/csc488/a2/minicc/build /home/tangzhen/csc488/a2/minicc/build/src /home/tangzhen/csc488/a2/minicc/build/src/CMakeFiles/minicc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/minicc.dir/depend
