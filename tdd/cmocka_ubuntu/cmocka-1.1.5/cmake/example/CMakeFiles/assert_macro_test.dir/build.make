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

# Include any dependencies generated for this target.
include example/CMakeFiles/assert_macro_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include example/CMakeFiles/assert_macro_test.dir/compiler_depend.make

# Include the progress variables for this target.
include example/CMakeFiles/assert_macro_test.dir/progress.make

# Include the compile flags for this target's objects.
include example/CMakeFiles/assert_macro_test.dir/flags.make

example/CMakeFiles/assert_macro_test.dir/assert_macro.c.o: example/CMakeFiles/assert_macro_test.dir/flags.make
example/CMakeFiles/assert_macro_test.dir/assert_macro.c.o: ../example/assert_macro.c
example/CMakeFiles/assert_macro_test.dir/assert_macro.c.o: example/CMakeFiles/assert_macro_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object example/CMakeFiles/assert_macro_test.dir/assert_macro.c.o"
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT example/CMakeFiles/assert_macro_test.dir/assert_macro.c.o -MF CMakeFiles/assert_macro_test.dir/assert_macro.c.o.d -o CMakeFiles/assert_macro_test.dir/assert_macro.c.o -c /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/example/assert_macro.c

example/CMakeFiles/assert_macro_test.dir/assert_macro.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assert_macro_test.dir/assert_macro.c.i"
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/example/assert_macro.c > CMakeFiles/assert_macro_test.dir/assert_macro.c.i

example/CMakeFiles/assert_macro_test.dir/assert_macro.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assert_macro_test.dir/assert_macro.c.s"
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/example/assert_macro.c -o CMakeFiles/assert_macro_test.dir/assert_macro.c.s

example/CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o: example/CMakeFiles/assert_macro_test.dir/flags.make
example/CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o: ../example/assert_macro_test.c
example/CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o: example/CMakeFiles/assert_macro_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object example/CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o"
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT example/CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o -MF CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o.d -o CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o -c /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/example/assert_macro_test.c

example/CMakeFiles/assert_macro_test.dir/assert_macro_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assert_macro_test.dir/assert_macro_test.c.i"
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/example/assert_macro_test.c > CMakeFiles/assert_macro_test.dir/assert_macro_test.c.i

example/CMakeFiles/assert_macro_test.dir/assert_macro_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assert_macro_test.dir/assert_macro_test.c.s"
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/example/assert_macro_test.c -o CMakeFiles/assert_macro_test.dir/assert_macro_test.c.s

# Object files for target assert_macro_test
assert_macro_test_OBJECTS = \
"CMakeFiles/assert_macro_test.dir/assert_macro.c.o" \
"CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o"

# External object files for target assert_macro_test
assert_macro_test_EXTERNAL_OBJECTS =

example/assert_macro_test: example/CMakeFiles/assert_macro_test.dir/assert_macro.c.o
example/assert_macro_test: example/CMakeFiles/assert_macro_test.dir/assert_macro_test.c.o
example/assert_macro_test: example/CMakeFiles/assert_macro_test.dir/build.make
example/assert_macro_test: src/libcmocka.so.0.7.0
example/assert_macro_test: /usr/lib/x86_64-linux-gnu/librt.so
example/assert_macro_test: example/CMakeFiles/assert_macro_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable assert_macro_test"
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assert_macro_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/CMakeFiles/assert_macro_test.dir/build: example/assert_macro_test
.PHONY : example/CMakeFiles/assert_macro_test.dir/build

example/CMakeFiles/assert_macro_test.dir/clean:
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example && $(CMAKE_COMMAND) -P CMakeFiles/assert_macro_test.dir/cmake_clean.cmake
.PHONY : example/CMakeFiles/assert_macro_test.dir/clean

example/CMakeFiles/assert_macro_test.dir/depend:
	cd /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5 /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/example /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example/CMakeFiles/assert_macro_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/CMakeFiles/assert_macro_test.dir/depend

