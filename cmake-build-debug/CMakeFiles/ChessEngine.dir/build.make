# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/124/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/124/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrian/CLionProjects/ChessEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrian/CLionProjects/ChessEngine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ChessEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChessEngine.dir/flags.make

CMakeFiles/ChessEngine.dir/sources/main.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/main.c.o: ../sources/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ChessEngine.dir/sources/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/main.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/main.c

CMakeFiles/ChessEngine.dir/sources/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/main.c > CMakeFiles/ChessEngine.dir/sources/main.c.i

CMakeFiles/ChessEngine.dir/sources/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/main.c -o CMakeFiles/ChessEngine.dir/sources/main.c.s

CMakeFiles/ChessEngine.dir/sources/data.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/data.c.o: ../sources/data.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ChessEngine.dir/sources/data.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/data.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/data.c

CMakeFiles/ChessEngine.dir/sources/data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/data.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/data.c > CMakeFiles/ChessEngine.dir/sources/data.c.i

CMakeFiles/ChessEngine.dir/sources/data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/data.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/data.c -o CMakeFiles/ChessEngine.dir/sources/data.c.s

CMakeFiles/ChessEngine.dir/sources/init.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/init.c.o: ../sources/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ChessEngine.dir/sources/init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/init.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/init.c

CMakeFiles/ChessEngine.dir/sources/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/init.c > CMakeFiles/ChessEngine.dir/sources/init.c.i

CMakeFiles/ChessEngine.dir/sources/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/init.c -o CMakeFiles/ChessEngine.dir/sources/init.c.s

CMakeFiles/ChessEngine.dir/sources/print.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/print.c.o: ../sources/print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ChessEngine.dir/sources/print.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/print.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/print.c

CMakeFiles/ChessEngine.dir/sources/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/print.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/print.c > CMakeFiles/ChessEngine.dir/sources/print.c.i

CMakeFiles/ChessEngine.dir/sources/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/print.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/print.c -o CMakeFiles/ChessEngine.dir/sources/print.c.s

CMakeFiles/ChessEngine.dir/sources/eval.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/eval.c.o: ../sources/eval.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ChessEngine.dir/sources/eval.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/eval.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/eval.c

CMakeFiles/ChessEngine.dir/sources/eval.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/eval.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/eval.c > CMakeFiles/ChessEngine.dir/sources/eval.c.i

CMakeFiles/ChessEngine.dir/sources/eval.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/eval.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/eval.c -o CMakeFiles/ChessEngine.dir/sources/eval.c.s

CMakeFiles/ChessEngine.dir/sources/board.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/board.c.o: ../sources/board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ChessEngine.dir/sources/board.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/board.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/board.c

CMakeFiles/ChessEngine.dir/sources/board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/board.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/board.c > CMakeFiles/ChessEngine.dir/sources/board.c.i

CMakeFiles/ChessEngine.dir/sources/board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/board.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/board.c -o CMakeFiles/ChessEngine.dir/sources/board.c.s

CMakeFiles/ChessEngine.dir/sources/test.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/test.c.o: ../sources/test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ChessEngine.dir/sources/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/test.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/test.c

CMakeFiles/ChessEngine.dir/sources/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/test.c > CMakeFiles/ChessEngine.dir/sources/test.c.i

CMakeFiles/ChessEngine.dir/sources/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/test.c -o CMakeFiles/ChessEngine.dir/sources/test.c.s

CMakeFiles/ChessEngine.dir/sources/move.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/move.c.o: ../sources/move.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ChessEngine.dir/sources/move.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/move.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/move.c

CMakeFiles/ChessEngine.dir/sources/move.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/move.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/move.c > CMakeFiles/ChessEngine.dir/sources/move.c.i

CMakeFiles/ChessEngine.dir/sources/move.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/move.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/move.c -o CMakeFiles/ChessEngine.dir/sources/move.c.s

CMakeFiles/ChessEngine.dir/sources/generator.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/generator.c.o: ../sources/generator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/ChessEngine.dir/sources/generator.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/generator.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/generator.c

CMakeFiles/ChessEngine.dir/sources/generator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/generator.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/generator.c > CMakeFiles/ChessEngine.dir/sources/generator.c.i

CMakeFiles/ChessEngine.dir/sources/generator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/generator.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/generator.c -o CMakeFiles/ChessEngine.dir/sources/generator.c.s

CMakeFiles/ChessEngine.dir/sources/search.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/search.c.o: ../sources/search.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/ChessEngine.dir/sources/search.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/search.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/search.c

CMakeFiles/ChessEngine.dir/sources/search.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/search.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/search.c > CMakeFiles/ChessEngine.dir/sources/search.c.i

CMakeFiles/ChessEngine.dir/sources/search.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/search.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/search.c -o CMakeFiles/ChessEngine.dir/sources/search.c.s

CMakeFiles/ChessEngine.dir/sources/pvTable.c.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/sources/pvTable.c.o: ../sources/pvTable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/ChessEngine.dir/sources/pvTable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ChessEngine.dir/sources/pvTable.c.o   -c /home/adrian/CLionProjects/ChessEngine/sources/pvTable.c

CMakeFiles/ChessEngine.dir/sources/pvTable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ChessEngine.dir/sources/pvTable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adrian/CLionProjects/ChessEngine/sources/pvTable.c > CMakeFiles/ChessEngine.dir/sources/pvTable.c.i

CMakeFiles/ChessEngine.dir/sources/pvTable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ChessEngine.dir/sources/pvTable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adrian/CLionProjects/ChessEngine/sources/pvTable.c -o CMakeFiles/ChessEngine.dir/sources/pvTable.c.s

# Object files for target ChessEngine
ChessEngine_OBJECTS = \
"CMakeFiles/ChessEngine.dir/sources/main.c.o" \
"CMakeFiles/ChessEngine.dir/sources/data.c.o" \
"CMakeFiles/ChessEngine.dir/sources/init.c.o" \
"CMakeFiles/ChessEngine.dir/sources/print.c.o" \
"CMakeFiles/ChessEngine.dir/sources/eval.c.o" \
"CMakeFiles/ChessEngine.dir/sources/board.c.o" \
"CMakeFiles/ChessEngine.dir/sources/test.c.o" \
"CMakeFiles/ChessEngine.dir/sources/move.c.o" \
"CMakeFiles/ChessEngine.dir/sources/generator.c.o" \
"CMakeFiles/ChessEngine.dir/sources/search.c.o" \
"CMakeFiles/ChessEngine.dir/sources/pvTable.c.o"

# External object files for target ChessEngine
ChessEngine_EXTERNAL_OBJECTS =

ChessEngine: CMakeFiles/ChessEngine.dir/sources/main.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/data.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/init.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/print.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/eval.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/board.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/test.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/move.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/generator.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/search.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/sources/pvTable.c.o
ChessEngine: CMakeFiles/ChessEngine.dir/build.make
ChessEngine: CMakeFiles/ChessEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable ChessEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChessEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChessEngine.dir/build: ChessEngine

.PHONY : CMakeFiles/ChessEngine.dir/build

CMakeFiles/ChessEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChessEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChessEngine.dir/clean

CMakeFiles/ChessEngine.dir/depend:
	cd /home/adrian/CLionProjects/ChessEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrian/CLionProjects/ChessEngine /home/adrian/CLionProjects/ChessEngine /home/adrian/CLionProjects/ChessEngine/cmake-build-debug /home/adrian/CLionProjects/ChessEngine/cmake-build-debug /home/adrian/CLionProjects/ChessEngine/cmake-build-debug/CMakeFiles/ChessEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ChessEngine.dir/depend

