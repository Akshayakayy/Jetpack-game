# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/akshaya/Documents/iiith/ogl-master/a1_20171016

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/akshaya/Documents/iiith/ogl-master/a1_20171016

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/akshaya/Documents/iiith/ogl-master/a1_20171016/CMakeFiles /home/akshaya/Documents/iiith/ogl-master/a1_20171016/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/akshaya/Documents/iiith/ogl-master/a1_20171016/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named graphics_asgn1

# Build rule for target.
graphics_asgn1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 graphics_asgn1
.PHONY : graphics_asgn1

# fast build rule for target.
graphics_asgn1/fast:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/build
.PHONY : graphics_asgn1/fast

src/ball.o: src/ball.cpp.o

.PHONY : src/ball.o

# target to build an object file
src/ball.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o
.PHONY : src/ball.cpp.o

src/ball.i: src/ball.cpp.i

.PHONY : src/ball.i

# target to preprocess a source file
src/ball.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.i
.PHONY : src/ball.cpp.i

src/ball.s: src/ball.cpp.s

.PHONY : src/ball.s

# target to generate assembly for a file
src/ball.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.s
.PHONY : src/ball.cpp.s

src/color.o: src/color.cpp.o

.PHONY : src/color.o

# target to build an object file
src/color.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.o
.PHONY : src/color.cpp.o

src/color.i: src/color.cpp.i

.PHONY : src/color.i

# target to preprocess a source file
src/color.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.i
.PHONY : src/color.cpp.i

src/color.s: src/color.cpp.s

.PHONY : src/color.s

# target to generate assembly for a file
src/color.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.s
.PHONY : src/color.cpp.s

src/enemy.o: src/enemy.cpp.o

.PHONY : src/enemy.o

# target to build an object file
src/enemy.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy.cpp.o
.PHONY : src/enemy.cpp.o

src/enemy.i: src/enemy.cpp.i

.PHONY : src/enemy.i

# target to preprocess a source file
src/enemy.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy.cpp.i
.PHONY : src/enemy.cpp.i

src/enemy.s: src/enemy.cpp.s

.PHONY : src/enemy.s

# target to generate assembly for a file
src/enemy.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy.cpp.s
.PHONY : src/enemy.cpp.s

src/input.o: src/input.cpp.o

.PHONY : src/input.o

# target to build an object file
src/input.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.o
.PHONY : src/input.cpp.o

src/input.i: src/input.cpp.i

.PHONY : src/input.i

# target to preprocess a source file
src/input.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.i
.PHONY : src/input.cpp.i

src/input.s: src/input.cpp.s

.PHONY : src/input.s

# target to generate assembly for a file
src/input.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.s
.PHONY : src/input.cpp.s

src/magnet.o: src/magnet.cpp.o

.PHONY : src/magnet.o

# target to build an object file
src/magnet.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/magnet.cpp.o
.PHONY : src/magnet.cpp.o

src/magnet.i: src/magnet.cpp.i

.PHONY : src/magnet.i

# target to preprocess a source file
src/magnet.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/magnet.cpp.i
.PHONY : src/magnet.cpp.i

src/magnet.s: src/magnet.cpp.s

.PHONY : src/magnet.s

# target to generate assembly for a file
src/magnet.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/magnet.cpp.s
.PHONY : src/magnet.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/man.o: src/man.cpp.o

.PHONY : src/man.o

# target to build an object file
src/man.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/man.cpp.o
.PHONY : src/man.cpp.o

src/man.i: src/man.cpp.i

.PHONY : src/man.i

# target to preprocess a source file
src/man.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/man.cpp.i
.PHONY : src/man.cpp.i

src/man.s: src/man.cpp.s

.PHONY : src/man.s

# target to generate assembly for a file
src/man.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/man.cpp.s
.PHONY : src/man.cpp.s

src/nonedit.o: src/nonedit.cpp.o

.PHONY : src/nonedit.o

# target to build an object file
src/nonedit.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o
.PHONY : src/nonedit.cpp.o

src/nonedit.i: src/nonedit.cpp.i

.PHONY : src/nonedit.i

# target to preprocess a source file
src/nonedit.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.i
.PHONY : src/nonedit.cpp.i

src/nonedit.s: src/nonedit.cpp.s

.PHONY : src/nonedit.s

# target to generate assembly for a file
src/nonedit.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.s
.PHONY : src/nonedit.cpp.s

src/objects.o: src/objects.cpp.o

.PHONY : src/objects.o

# target to build an object file
src/objects.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/objects.cpp.o
.PHONY : src/objects.cpp.o

src/objects.i: src/objects.cpp.i

.PHONY : src/objects.i

# target to preprocess a source file
src/objects.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/objects.cpp.i
.PHONY : src/objects.cpp.i

src/objects.s: src/objects.cpp.s

.PHONY : src/objects.s

# target to generate assembly for a file
src/objects.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/objects.cpp.s
.PHONY : src/objects.cpp.s

src/other_handlers.o: src/other_handlers.cpp.o

.PHONY : src/other_handlers.o

# target to build an object file
src/other_handlers.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o
.PHONY : src/other_handlers.cpp.o

src/other_handlers.i: src/other_handlers.cpp.i

.PHONY : src/other_handlers.i

# target to preprocess a source file
src/other_handlers.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.i
.PHONY : src/other_handlers.cpp.i

src/other_handlers.s: src/other_handlers.cpp.s

.PHONY : src/other_handlers.s

# target to generate assembly for a file
src/other_handlers.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.s
.PHONY : src/other_handlers.cpp.s

src/scene.o: src/scene.cpp.o

.PHONY : src/scene.o

# target to build an object file
src/scene.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/scene.cpp.o
.PHONY : src/scene.cpp.o

src/scene.i: src/scene.cpp.i

.PHONY : src/scene.i

# target to preprocess a source file
src/scene.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/scene.cpp.i
.PHONY : src/scene.cpp.i

src/scene.s: src/scene.cpp.s

.PHONY : src/scene.s

# target to generate assembly for a file
src/scene.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/scene.cpp.s
.PHONY : src/scene.cpp.s

src/semic.o: src/semic.cpp.o

.PHONY : src/semic.o

# target to build an object file
src/semic.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/semic.cpp.o
.PHONY : src/semic.cpp.o

src/semic.i: src/semic.cpp.i

.PHONY : src/semic.i

# target to preprocess a source file
src/semic.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/semic.cpp.i
.PHONY : src/semic.cpp.i

src/semic.s: src/semic.cpp.s

.PHONY : src/semic.s

# target to generate assembly for a file
src/semic.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/semic.cpp.s
.PHONY : src/semic.cpp.s

src/timer.o: src/timer.cpp.o

.PHONY : src/timer.o

# target to build an object file
src/timer.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o
.PHONY : src/timer.cpp.o

src/timer.i: src/timer.cpp.i

.PHONY : src/timer.i

# target to preprocess a source file
src/timer.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.i
.PHONY : src/timer.cpp.i

src/timer.s: src/timer.cpp.s

.PHONY : src/timer.s

# target to generate assembly for a file
src/timer.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.s
.PHONY : src/timer.cpp.s

src/water.o: src/water.cpp.o

.PHONY : src/water.o

# target to build an object file
src/water.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/water.cpp.o
.PHONY : src/water.cpp.o

src/water.i: src/water.cpp.i

.PHONY : src/water.i

# target to preprocess a source file
src/water.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/water.cpp.i
.PHONY : src/water.cpp.i

src/water.s: src/water.cpp.s

.PHONY : src/water.s

# target to generate assembly for a file
src/water.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/water.cpp.s
.PHONY : src/water.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... graphics_asgn1"
	@echo "... src/ball.o"
	@echo "... src/ball.i"
	@echo "... src/ball.s"
	@echo "... src/color.o"
	@echo "... src/color.i"
	@echo "... src/color.s"
	@echo "... src/enemy.o"
	@echo "... src/enemy.i"
	@echo "... src/enemy.s"
	@echo "... src/input.o"
	@echo "... src/input.i"
	@echo "... src/input.s"
	@echo "... src/magnet.o"
	@echo "... src/magnet.i"
	@echo "... src/magnet.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/man.o"
	@echo "... src/man.i"
	@echo "... src/man.s"
	@echo "... src/nonedit.o"
	@echo "... src/nonedit.i"
	@echo "... src/nonedit.s"
	@echo "... src/objects.o"
	@echo "... src/objects.i"
	@echo "... src/objects.s"
	@echo "... src/other_handlers.o"
	@echo "... src/other_handlers.i"
	@echo "... src/other_handlers.s"
	@echo "... src/scene.o"
	@echo "... src/scene.i"
	@echo "... src/scene.s"
	@echo "... src/semic.o"
	@echo "... src/semic.i"
	@echo "... src/semic.s"
	@echo "... src/timer.o"
	@echo "... src/timer.i"
	@echo "... src/timer.s"
	@echo "... src/water.o"
	@echo "... src/water.i"
	@echo "... src/water.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
