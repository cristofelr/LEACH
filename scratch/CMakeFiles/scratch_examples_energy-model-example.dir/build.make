# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.31.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.31.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43

# Include any dependencies generated for this target.
include scratch/CMakeFiles/scratch_examples_energy-model-example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include scratch/CMakeFiles/scratch_examples_energy-model-example.dir/compiler_depend.make

# Include the progress variables for this target.
include scratch/CMakeFiles/scratch_examples_energy-model-example.dir/progress.make

# Include the compile flags for this target's objects.
include scratch/CMakeFiles/scratch_examples_energy-model-example.dir/flags.make

scratch/CMakeFiles/scratch_examples_energy-model-example.dir/codegen:
.PHONY : scratch/CMakeFiles/scratch_examples_energy-model-example.dir/codegen

scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o: scratch/CMakeFiles/scratch_examples_energy-model-example.dir/flags.make
scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o: scratch/examples/energy-model-example.cc
scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o: CMakeFiles/stdlib_pch_exec.dir/cmake_pch.hxx
scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o: CMakeFiles/stdlib_pch_exec.dir/cmake_pch.hxx.pch
scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o: scratch/CMakeFiles/scratch_examples_energy-model-example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o"
	cd /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch && /opt/homebrew/bin/ccache /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/CMakeFiles/stdlib_pch_exec.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/CMakeFiles/stdlib_pch_exec.dir/cmake_pch.hxx -MD -MT scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o -MF CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o.d -o CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o -c /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch/examples/energy-model-example.cc

scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.i"
	cd /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/CMakeFiles/stdlib_pch_exec.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/CMakeFiles/stdlib_pch_exec.dir/cmake_pch.hxx -E /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch/examples/energy-model-example.cc > CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.i

scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.s"
	cd /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/CMakeFiles/stdlib_pch_exec.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/CMakeFiles/stdlib_pch_exec.dir/cmake_pch.hxx -S /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch/examples/energy-model-example.cc -o CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.s

# Object files for target scratch_examples_energy-model-example
scratch_examples_energy__model__example_OBJECTS = \
"CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o"

# External object files for target scratch_examples_energy-model-example
scratch_examples_energy__model__example_EXTERNAL_OBJECTS =

build/scratch/examples/ns3.43-energy-model-example-default: scratch/CMakeFiles/scratch_examples_energy-model-example.dir/examples/energy-model-example.cc.o
build/scratch/examples/ns3.43-energy-model-example-default: scratch/CMakeFiles/scratch_examples_energy-model-example.dir/build.make
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/Cellar/libxml2/2.13.4_4/lib/libxml2.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libfreetype.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libglib-2.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libgthread-2.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libgobject-2.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libgio-2.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libgdk_pixbuf-2.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libgdk-3.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libgtk-3.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libcairo.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libpango-1.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/lib/libatk-1.0.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/Cellar/gsl/2.8/lib/libgsl.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /opt/homebrew/Cellar/gsl/2.8/lib/libgslcblas.dylib
build/scratch/examples/ns3.43-energy-model-example-default: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.1.sdk/usr/lib/libsqlite3.tbd
build/scratch/examples/ns3.43-energy-model-example-default: scratch/CMakeFiles/scratch_examples_energy-model-example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../build/scratch/examples/ns3.43-energy-model-example-default"
	cd /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scratch_examples_energy-model-example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
scratch/CMakeFiles/scratch_examples_energy-model-example.dir/build: build/scratch/examples/ns3.43-energy-model-example-default
.PHONY : scratch/CMakeFiles/scratch_examples_energy-model-example.dir/build

scratch/CMakeFiles/scratch_examples_energy-model-example.dir/clean:
	cd /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch && $(CMAKE_COMMAND) -P CMakeFiles/scratch_examples_energy-model-example.dir/cmake_clean.cmake
.PHONY : scratch/CMakeFiles/scratch_examples_energy-model-example.dir/clean

scratch/CMakeFiles/scratch_examples_energy-model-example.dir/depend:
	cd /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43 /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43 /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch /Users/cristoferocha/Documents/ns-allinone-3.43/ns-3.43/scratch/CMakeFiles/scratch_examples_energy-model-example.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : scratch/CMakeFiles/scratch_examples_energy-model-example.dir/depend

