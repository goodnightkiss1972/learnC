# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /snap/cmake/1005/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1005/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake

# Utility rule file for ExperimentalUpdate.

# Include any custom commands dependencies for this target.
include CMakeFiles/ExperimentalUpdate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ExperimentalUpdate.dir/progress.make

CMakeFiles/ExperimentalUpdate:
	/snap/cmake/1005/bin/ctest -D ExperimentalUpdate

ExperimentalUpdate: CMakeFiles/ExperimentalUpdate
ExperimentalUpdate: CMakeFiles/ExperimentalUpdate.dir/build.make
.PHONY : ExperimentalUpdate

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalUpdate.dir/build: ExperimentalUpdate
.PHONY : CMakeFiles/ExperimentalUpdate.dir/build

CMakeFiles/ExperimentalUpdate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExperimentalUpdate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalUpdate.dir/clean

CMakeFiles/ExperimentalUpdate.dir/depend:
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5 /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5 /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/CMakeFiles/ExperimentalUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ExperimentalUpdate.dir/depend

