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
CMAKE_SOURCE_DIR = /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build

# Include any dependencies generated for this target.
include CMakeFiles/dessin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dessin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dessin.dir/flags.make

parser.cpp: ../parser/parser.yy
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][parser] Building parser with bison 3.5.1"
	cd /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin && /usr/bin/bison -d --verbose -o /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp parser/parser.yy

parser.output: parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate parser.output

parser.hpp: parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate parser.hpp

automate.txt: parser.output
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[BISON][parser] Copying bison verbose table to /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/automate.txt"
	cd /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin && /usr/bin/cmake -E copy /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.output /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/automate.txt

scanner.cpp: ../parser/scanner.ll
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "[FLEX][scanner] Building scanner with flex 2.6.4"
	cd /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin && /usr/bin/flex -o/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/scanner.cpp parser/scanner.ll

CMakeFiles/dessin.dir/parser/main.cc.o: CMakeFiles/dessin.dir/flags.make
CMakeFiles/dessin.dir/parser/main.cc.o: ../parser/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/dessin.dir/parser/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dessin.dir/parser/main.cc.o -c /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/parser/main.cc

CMakeFiles/dessin.dir/parser/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dessin.dir/parser/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/parser/main.cc > CMakeFiles/dessin.dir/parser/main.cc.i

CMakeFiles/dessin.dir/parser/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dessin.dir/parser/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/parser/main.cc -o CMakeFiles/dessin.dir/parser/main.cc.s

CMakeFiles/dessin.dir/parser/driver.cc.o: CMakeFiles/dessin.dir/flags.make
CMakeFiles/dessin.dir/parser/driver.cc.o: ../parser/driver.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/dessin.dir/parser/driver.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dessin.dir/parser/driver.cc.o -c /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/parser/driver.cc

CMakeFiles/dessin.dir/parser/driver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dessin.dir/parser/driver.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/parser/driver.cc > CMakeFiles/dessin.dir/parser/driver.cc.i

CMakeFiles/dessin.dir/parser/driver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dessin.dir/parser/driver.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/parser/driver.cc -o CMakeFiles/dessin.dir/parser/driver.cc.s

CMakeFiles/dessin.dir/parser.cpp.o: CMakeFiles/dessin.dir/flags.make
CMakeFiles/dessin.dir/parser.cpp.o: parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/dessin.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dessin.dir/parser.cpp.o -c /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp

CMakeFiles/dessin.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dessin.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp > CMakeFiles/dessin.dir/parser.cpp.i

CMakeFiles/dessin.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dessin.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/parser.cpp -o CMakeFiles/dessin.dir/parser.cpp.s

CMakeFiles/dessin.dir/scanner.cpp.o: CMakeFiles/dessin.dir/flags.make
CMakeFiles/dessin.dir/scanner.cpp.o: scanner.cpp
CMakeFiles/dessin.dir/scanner.cpp.o: parser.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/dessin.dir/scanner.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dessin.dir/scanner.cpp.o -c /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/scanner.cpp

CMakeFiles/dessin.dir/scanner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dessin.dir/scanner.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/scanner.cpp > CMakeFiles/dessin.dir/scanner.cpp.i

CMakeFiles/dessin.dir/scanner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dessin.dir/scanner.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/scanner.cpp -o CMakeFiles/dessin.dir/scanner.cpp.s

# Object files for target dessin
dessin_OBJECTS = \
"CMakeFiles/dessin.dir/parser/main.cc.o" \
"CMakeFiles/dessin.dir/parser/driver.cc.o" \
"CMakeFiles/dessin.dir/parser.cpp.o" \
"CMakeFiles/dessin.dir/scanner.cpp.o"

# External object files for target dessin
dessin_EXTERNAL_OBJECTS =

dessin: CMakeFiles/dessin.dir/parser/main.cc.o
dessin: CMakeFiles/dessin.dir/parser/driver.cc.o
dessin: CMakeFiles/dessin.dir/parser.cpp.o
dessin: CMakeFiles/dessin.dir/scanner.cpp.o
dessin: CMakeFiles/dessin.dir/build.make
dessin: libexpressions.a
dessin: CMakeFiles/dessin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable dessin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dessin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dessin.dir/build: dessin

.PHONY : CMakeFiles/dessin.dir/build

CMakeFiles/dessin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dessin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dessin.dir/clean

CMakeFiles/dessin.dir/depend: parser.cpp
CMakeFiles/dessin.dir/depend: parser.output
CMakeFiles/dessin.dir/depend: parser.hpp
CMakeFiles/dessin.dir/depend: automate.txt
CMakeFiles/dessin.dir/depend: scanner.cpp
	cd /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build /mnt/c/Users/paull/Onedrive/Bureau/Compilateur/dessin/build/CMakeFiles/dessin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dessin.dir/depend

