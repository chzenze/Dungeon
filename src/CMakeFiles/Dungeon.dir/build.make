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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hanzech/CLionProjects/coms327-s19-dungeon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hanzech/CLionProjects/coms327-s19-dungeon

# Include any dependencies generated for this target.
include src/CMakeFiles/Dungeon.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Dungeon.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Dungeon.dir/flags.make

src/CMakeFiles/Dungeon.dir/main.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/Dungeon.dir/main.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/main.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/main.c

src/CMakeFiles/Dungeon.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/main.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/main.c > CMakeFiles/Dungeon.dir/main.c.i

src/CMakeFiles/Dungeon.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/main.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/main.c -o CMakeFiles/Dungeon.dir/main.c.s

src/CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.o: src/utils/dungeon_gen_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_gen_map.c

src/CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_gen_map.c > CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.i

src/CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_gen_map.c -o CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.s

src/CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.o: src/utils/dungeon_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_utils.c

src/CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_utils.c > CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.i

src/CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/dungeon_utils.c -o CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.s

src/CMakeFiles/Dungeon.dir/characters/MonsterController.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/characters/MonsterController.c.o: src/characters/MonsterController.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/Dungeon.dir/characters/MonsterController.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/characters/MonsterController.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/MonsterController.c

src/CMakeFiles/Dungeon.dir/characters/MonsterController.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/characters/MonsterController.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/MonsterController.c > CMakeFiles/Dungeon.dir/characters/MonsterController.c.i

src/CMakeFiles/Dungeon.dir/characters/MonsterController.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/characters/MonsterController.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/MonsterController.c -o CMakeFiles/Dungeon.dir/characters/MonsterController.c.s

src/CMakeFiles/Dungeon.dir/characters/monster.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/characters/monster.c.o: src/characters/monster.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/Dungeon.dir/characters/monster.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/characters/monster.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/monster.c

src/CMakeFiles/Dungeon.dir/characters/monster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/characters/monster.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/monster.c > CMakeFiles/Dungeon.dir/characters/monster.c.i

src/CMakeFiles/Dungeon.dir/characters/monster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/characters/monster.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/monster.c -o CMakeFiles/Dungeon.dir/characters/monster.c.s

src/CMakeFiles/Dungeon.dir/characters/pc.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/characters/pc.c.o: src/characters/pc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/Dungeon.dir/characters/pc.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/characters/pc.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/pc.c

src/CMakeFiles/Dungeon.dir/characters/pc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/characters/pc.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/pc.c > CMakeFiles/Dungeon.dir/characters/pc.c.i

src/CMakeFiles/Dungeon.dir/characters/pc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/characters/pc.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/characters/pc.c -o CMakeFiles/Dungeon.dir/characters/pc.c.s

src/CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.o: src/utils/data_stucture/heap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/data_stucture/heap.c

src/CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/data_stucture/heap.c > CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.i

src/CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/utils/data_stucture/heap.c -o CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.s

src/CMakeFiles/Dungeon.dir/KeyBindMap.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/KeyBindMap.c.o: src/KeyBindMap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/CMakeFiles/Dungeon.dir/KeyBindMap.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/KeyBindMap.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/KeyBindMap.c

src/CMakeFiles/Dungeon.dir/KeyBindMap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/KeyBindMap.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/KeyBindMap.c > CMakeFiles/Dungeon.dir/KeyBindMap.c.i

src/CMakeFiles/Dungeon.dir/KeyBindMap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/KeyBindMap.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/KeyBindMap.c -o CMakeFiles/Dungeon.dir/KeyBindMap.c.s

src/CMakeFiles/Dungeon.dir/game.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/game.c.o: src/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/CMakeFiles/Dungeon.dir/game.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/game.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/game.c

src/CMakeFiles/Dungeon.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/game.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/game.c > CMakeFiles/Dungeon.dir/game.c.i

src/CMakeFiles/Dungeon.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/game.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/game.c -o CMakeFiles/Dungeon.dir/game.c.s

src/CMakeFiles/Dungeon.dir/io_file_c.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/io_file_c.c.o: src/io_file_c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/CMakeFiles/Dungeon.dir/io_file_c.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/io_file_c.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_file_c.c

src/CMakeFiles/Dungeon.dir/io_file_c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/io_file_c.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_file_c.c > CMakeFiles/Dungeon.dir/io_file_c.c.i

src/CMakeFiles/Dungeon.dir/io_file_c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/io_file_c.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/io_file_c.c -o CMakeFiles/Dungeon.dir/io_file_c.c.s

src/CMakeFiles/Dungeon.dir/status_message.c.o: src/CMakeFiles/Dungeon.dir/flags.make
src/CMakeFiles/Dungeon.dir/status_message.c.o: src/status_message.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/CMakeFiles/Dungeon.dir/status_message.c.o"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Dungeon.dir/status_message.c.o   -c /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/status_message.c

src/CMakeFiles/Dungeon.dir/status_message.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Dungeon.dir/status_message.c.i"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/status_message.c > CMakeFiles/Dungeon.dir/status_message.c.i

src/CMakeFiles/Dungeon.dir/status_message.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Dungeon.dir/status_message.c.s"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/status_message.c -o CMakeFiles/Dungeon.dir/status_message.c.s

# Object files for target Dungeon
Dungeon_OBJECTS = \
"CMakeFiles/Dungeon.dir/main.c.o" \
"CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.o" \
"CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.o" \
"CMakeFiles/Dungeon.dir/characters/MonsterController.c.o" \
"CMakeFiles/Dungeon.dir/characters/monster.c.o" \
"CMakeFiles/Dungeon.dir/characters/pc.c.o" \
"CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.o" \
"CMakeFiles/Dungeon.dir/KeyBindMap.c.o" \
"CMakeFiles/Dungeon.dir/game.c.o" \
"CMakeFiles/Dungeon.dir/io_file_c.c.o" \
"CMakeFiles/Dungeon.dir/status_message.c.o"

# External object files for target Dungeon
Dungeon_EXTERNAL_OBJECTS =

src/Dungeon: src/CMakeFiles/Dungeon.dir/main.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/utils/dungeon_gen_map.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/utils/dungeon_utils.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/characters/MonsterController.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/characters/monster.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/characters/pc.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/utils/data_stucture/heap.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/KeyBindMap.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/game.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/io_file_c.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/status_message.c.o
src/Dungeon: src/CMakeFiles/Dungeon.dir/build.make
src/Dungeon: lib/libDisplayLib.0.9.dylib
src/Dungeon: /usr/lib/libcurses.dylib
src/Dungeon: /usr/lib/libform.dylib
src/Dungeon: src/CMakeFiles/Dungeon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hanzech/CLionProjects/coms327-s19-dungeon/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable Dungeon"
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dungeon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Dungeon.dir/build: src/Dungeon

.PHONY : src/CMakeFiles/Dungeon.dir/build

src/CMakeFiles/Dungeon.dir/clean:
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon/src && $(CMAKE_COMMAND) -P CMakeFiles/Dungeon.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Dungeon.dir/clean

src/CMakeFiles/Dungeon.dir/depend:
	cd /Users/hanzech/CLionProjects/coms327-s19-dungeon && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hanzech/CLionProjects/coms327-s19-dungeon /Users/hanzech/CLionProjects/coms327-s19-dungeon/src /Users/hanzech/CLionProjects/coms327-s19-dungeon /Users/hanzech/CLionProjects/coms327-s19-dungeon/src /Users/hanzech/CLionProjects/coms327-s19-dungeon/src/CMakeFiles/Dungeon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Dungeon.dir/depend

