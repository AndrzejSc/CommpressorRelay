# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Milenka\CLionProjects\CommpressorRelay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Milenka\CLionProjects\CommpressorRelay\cmake-build-miniatmega328

# Utility rule file for PLATFORMIO_BUILD.

# Include the progress variables for this target.
include CMakeFiles/PLATFORMIO_BUILD.dir/progress.make

CMakeFiles/PLATFORMIO_BUILD:
	cd /d C:\Users\Milenka\CLionProjects\CommpressorRelay && "C:\Program Files (x86)\Python38-32\Scripts\platformio.exe" -f -c clion run -eminiatmega328

PLATFORMIO_BUILD: CMakeFiles/PLATFORMIO_BUILD
PLATFORMIO_BUILD: CMakeFiles/PLATFORMIO_BUILD.dir/build.make

.PHONY : PLATFORMIO_BUILD

# Rule to build all files generated by this target.
CMakeFiles/PLATFORMIO_BUILD.dir/build: PLATFORMIO_BUILD

.PHONY : CMakeFiles/PLATFORMIO_BUILD.dir/build

CMakeFiles/PLATFORMIO_BUILD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PLATFORMIO_BUILD.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PLATFORMIO_BUILD.dir/clean

CMakeFiles/PLATFORMIO_BUILD.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Milenka\CLionProjects\CommpressorRelay C:\Users\Milenka\CLionProjects\CommpressorRelay C:\Users\Milenka\CLionProjects\CommpressorRelay\cmake-build-miniatmega328 C:\Users\Milenka\CLionProjects\CommpressorRelay\cmake-build-miniatmega328 C:\Users\Milenka\CLionProjects\CommpressorRelay\cmake-build-miniatmega328\CMakeFiles\PLATFORMIO_BUILD.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PLATFORMIO_BUILD.dir/depend

