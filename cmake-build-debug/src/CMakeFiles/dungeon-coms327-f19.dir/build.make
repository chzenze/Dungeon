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
CMAKE_SOURCE_DIR = /Users/hanzech/CLionProjects/coms327-s19-dungeon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/dungeon-coms327-f19.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/dungeon-coms327-f19.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/dungeon-coms327-f19.dir/flags.make

src/CMakeFiles/dungeon-coms327-f19.dir/game.o: src/CMakeFiles/dungeon-coms327-f19.dir/flags.make
src/CMakeFiles/dungeon-coms327-f19.dir/game.o: ../src/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/dungeon-coms327-f19.dir/game.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dungeon-coms327-f19.dir/game.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/game.c

src/CMakeFiles/dungeon-coms327-f19.dir/game.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dungeon-coms327-f19.dir/game.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/game.c > CMakeFiles/dungeon-coms327-f19.dir/game.i

src/CMakeFiles/dungeon-coms327-f19.dir/game.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dungeon-coms327-f19.dir/game.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/game.c -o CMakeFiles/dungeon-coms327-f19.dir/game.s

src/CMakeFiles/dungeon-coms327-f19.dir/io_file.o: src/CMakeFiles/dungeon-coms327-f19.dir/flags.make
src/CMakeFiles/dungeon-coms327-f19.dir/io_file.o: ../src/io_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/dungeon-coms327-f19.dir/io_file.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dungeon-coms327-f19.dir/io_file.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_file.c

src/CMakeFiles/dungeon-coms327-f19.dir/io_file.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dungeon-coms327-f19.dir/io_file.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_file.c > CMakeFiles/dungeon-coms327-f19.dir/io_file.i

src/CMakeFiles/dungeon-coms327-f19.dir/io_file.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dungeon-coms327-f19.dir/io_file.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_file.c -o CMakeFiles/dungeon-coms327-f19.dir/io_file.s

src/CMakeFiles/dungeon-coms327-f19.dir/main.o: src/CMakeFiles/dungeon-coms327-f19.dir/flags.make
src/CMakeFiles/dungeon-coms327-f19.dir/main.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/dungeon-coms327-f19.dir/main.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dungeon-coms327-f19.dir/main.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/main.c

src/CMakeFiles/dungeon-coms327-f19.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dungeon-coms327-f19.dir/main.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/main.c > CMakeFiles/dungeon-coms327-f19.dir/main.i

src/CMakeFiles/dungeon-coms327-f19.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dungeon-coms327-f19.dir/main.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/main.c -o CMakeFiles/dungeon-coms327-f19.dir/main.s

src/CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.o: src/CMakeFiles/dungeon-coms327-f19.dir/flags.make
src/CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.o: ../src/utils/display_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/display_utils.c

src/CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/display_utils.c > CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.i

src/CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/display_utils.c -o CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.s

src/CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.o: src/CMakeFiles/dungeon-coms327-f19.dir/flags.make
src/CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.o: ../src/io_display/window/windos_dungeon.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_display/window/windos_dungeon.c

src/CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_display/window/windos_dungeon.c > CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.i

src/CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_display/window/windos_dungeon.c -o CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.s

src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.o: src/CMakeFiles/dungeon-coms327-f19.dir/flags.make
src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.o: ../src/utils/dungeon_map_generate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_map_generate.c

src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_map_generate.c > CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.i

src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_map_generate.c -o CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.s

src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.o: src/CMakeFiles/dungeon-coms327-f19.dir/flags.make
src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.o: ../src/utils/dungeon_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_utils.c

src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_utils.c > CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.i

src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_utils.c -o CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.s

# Object files for target dungeon-coms327-f19
dungeon__coms327__f19_OBJECTS = \
"CMakeFiles/dungeon-coms327-f19.dir/game.o" \
"CMakeFiles/dungeon-coms327-f19.dir/io_file.o" \
"CMakeFiles/dungeon-coms327-f19.dir/main.o" \
"CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.o" \
"CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.o" \
"CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.o" \
"CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.o"

# External object files for target dungeon-coms327-f19
dungeon__coms327__f19_EXTERNAL_OBJECTS =

src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/game.o
src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/io_file.o
src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/main.o
src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/utils/display_utils.o
src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/io_display/window/windos_dungeon.o
src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_map_generate.o
src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/utils/dungeon_utils.o
src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/build.make
src/dungeon-coms327-f19: /usr/lib/libcurses.dylib
src/dungeon-coms327-f19: /usr/lib/libform.dylib
src/dungeon-coms327-f19: src/CMakeFiles/dungeon-coms327-f19.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable dungeon-coms327-f19"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dungeon-coms327-f19.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/dungeon-coms327-f19.dir/build: src/dungeon-coms327-f19

.PHONY : src/CMakeFiles/dungeon-coms327-f19.dir/build

src/CMakeFiles/dungeon-coms327-f19.dir/clean:
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/dungeon-coms327-f19.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/dungeon-coms327-f19.dir/clean

src/CMakeFiles/dungeon-coms327-f19.dir/depend:
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hanzech/CLionProjects/coms327-s19-dungeon /Users/hanzech/CLionProjects/coms327-s19-dungeon/src /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src /Users/hanzech/CLionProjects/coms327-s19-dungeon/cmake-build-debug/src/CMakeFiles/dungeon-coms327-f19.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/dungeon-coms327-f19.dir/depend

