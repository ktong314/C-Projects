# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Problem_B.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Problem_B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Problem_B.dir/flags.make

CMakeFiles/Problem_B.dir/anagrams_starter.c.obj: CMakeFiles/Problem_B.dir/flags.make
CMakeFiles/Problem_B.dir/anagrams_starter.c.obj: ../anagrams_starter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Problem_B.dir/anagrams_starter.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Problem_B.dir\anagrams_starter.c.obj -c "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\anagrams_starter.c"

CMakeFiles/Problem_B.dir/anagrams_starter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Problem_B.dir/anagrams_starter.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\anagrams_starter.c" > CMakeFiles\Problem_B.dir\anagrams_starter.c.i

CMakeFiles/Problem_B.dir/anagrams_starter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Problem_B.dir/anagrams_starter.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\anagrams_starter.c" -o CMakeFiles\Problem_B.dir\anagrams_starter.c.s

# Object files for target Problem_B
Problem_B_OBJECTS = \
"CMakeFiles/Problem_B.dir/anagrams_starter.c.obj"

# External object files for target Problem_B
Problem_B_EXTERNAL_OBJECTS =

Problem_B.exe: CMakeFiles/Problem_B.dir/anagrams_starter.c.obj
Problem_B.exe: CMakeFiles/Problem_B.dir/build.make
Problem_B.exe: CMakeFiles/Problem_B.dir/linklibs.rsp
Problem_B.exe: CMakeFiles/Problem_B.dir/objects1.rsp
Problem_B.exe: CMakeFiles/Problem_B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Problem_B.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Problem_B.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Problem_B.dir/build: Problem_B.exe
.PHONY : CMakeFiles/Problem_B.dir/build

CMakeFiles/Problem_B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Problem_B.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Problem_B.dir/clean

CMakeFiles/Problem_B.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B" "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B" "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\cmake-build-debug" "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\cmake-build-debug" "C:\Users\ktong\Desktop\ECE\EE312\Projects\Project0\Problem B\cmake-build-debug\CMakeFiles\Problem_B.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Problem_B.dir/depend

