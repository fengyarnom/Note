# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PostfixExpression.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PostfixExpression.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PostfixExpression.dir/flags.make

CMakeFiles/PostfixExpression.dir/main.c.o: CMakeFiles/PostfixExpression.dir/flags.make
CMakeFiles/PostfixExpression.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PostfixExpression.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PostfixExpression.dir/main.c.o -c /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/main.c

CMakeFiles/PostfixExpression.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PostfixExpression.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/main.c > CMakeFiles/PostfixExpression.dir/main.c.i

CMakeFiles/PostfixExpression.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PostfixExpression.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/main.c -o CMakeFiles/PostfixExpression.dir/main.c.s

# Object files for target PostfixExpression
PostfixExpression_OBJECTS = \
"CMakeFiles/PostfixExpression.dir/main.c.o"

# External object files for target PostfixExpression
PostfixExpression_EXTERNAL_OBJECTS =

PostfixExpression: CMakeFiles/PostfixExpression.dir/main.c.o
PostfixExpression: CMakeFiles/PostfixExpression.dir/build.make
PostfixExpression: CMakeFiles/PostfixExpression.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PostfixExpression"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PostfixExpression.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PostfixExpression.dir/build: PostfixExpression
.PHONY : CMakeFiles/PostfixExpression.dir/build

CMakeFiles/PostfixExpression.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PostfixExpression.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PostfixExpression.dir/clean

CMakeFiles/PostfixExpression.dir/depend:
	cd /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/cmake-build-debug /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/cmake-build-debug /home/yarnom/Area/Note/DataStructure/code/Stack/PostfixExpression/cmake-build-debug/CMakeFiles/PostfixExpression.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PostfixExpression.dir/depend

