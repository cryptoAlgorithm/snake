# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wos/WOS23/src/snake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wos/WOS23/src/snake/build

# Include any dependencies generated for this target.
include CMakeFiles/snake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/snake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snake.dir/flags.make

CMakeFiles/snake.dir/snake.c.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/snake.c.o: ../snake.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wos/WOS23/src/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/snake.dir/snake.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/snake.dir/snake.c.o   -c /home/wos/WOS23/src/snake/snake.c

CMakeFiles/snake.dir/snake.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snake.dir/snake.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wos/WOS23/src/snake/snake.c > CMakeFiles/snake.dir/snake.c.i

CMakeFiles/snake.dir/snake.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snake.dir/snake.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wos/WOS23/src/snake/snake.c -o CMakeFiles/snake.dir/snake.c.s

CMakeFiles/snake.dir/map.c.o: CMakeFiles/snake.dir/flags.make
CMakeFiles/snake.dir/map.c.o: ../map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wos/WOS23/src/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/snake.dir/map.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/snake.dir/map.c.o   -c /home/wos/WOS23/src/snake/map.c

CMakeFiles/snake.dir/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snake.dir/map.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wos/WOS23/src/snake/map.c > CMakeFiles/snake.dir/map.c.i

CMakeFiles/snake.dir/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snake.dir/map.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wos/WOS23/src/snake/map.c -o CMakeFiles/snake.dir/map.c.s

# Object files for target snake
snake_OBJECTS = \
"CMakeFiles/snake.dir/snake.c.o" \
"CMakeFiles/snake.dir/map.c.o"

# External object files for target snake
snake_EXTERNAL_OBJECTS =

snake: CMakeFiles/snake.dir/snake.c.o
snake: CMakeFiles/snake.dir/map.c.o
snake: CMakeFiles/snake.dir/build.make
snake: /usr/lib/x86_64-linux-gnu/libcurses.so
snake: /usr/lib/x86_64-linux-gnu/libform.so
snake: CMakeFiles/snake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wos/WOS23/src/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable snake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snake.dir/build: snake

.PHONY : CMakeFiles/snake.dir/build

CMakeFiles/snake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snake.dir/clean

CMakeFiles/snake.dir/depend:
	cd /home/wos/WOS23/src/snake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wos/WOS23/src/snake /home/wos/WOS23/src/snake /home/wos/WOS23/src/snake/build /home/wos/WOS23/src/snake/build /home/wos/WOS23/src/snake/build/CMakeFiles/snake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snake.dir/depend

