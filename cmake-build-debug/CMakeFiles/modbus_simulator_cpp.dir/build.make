# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/82/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/82/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nvuletic/git-nexylmao/modbus-simulator-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/modbus_simulator_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/modbus_simulator_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/modbus_simulator_cpp.dir/flags.make

CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.o: ../Machine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Machine.cpp

CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Machine.cpp > CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Machine.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.o: ../Component.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Component.cpp

CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Component.cpp > CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Component.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.o: ../Logger/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Logger/Logger.cpp

CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Logger/Logger.cpp > CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Logger/Logger.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.o: ../Messages/ComponentMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ComponentMessage.cpp

CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ComponentMessage.cpp > CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ComponentMessage.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.o: ../Messages/ActionStatusMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ActionStatusMessage.cpp

CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ActionStatusMessage.cpp > CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ActionStatusMessage.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.o: ../Messages/ConveyorRateMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ConveyorRateMessage.cpp

CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ConveyorRateMessage.cpp > CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/ConveyorRateMessage.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.o: ../Messages/CountMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/CountMessage.cpp

CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/CountMessage.cpp > CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/CountMessage.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.o: ../Messages/MachineStateMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/MachineStateMessage.cpp

CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/MachineStateMessage.cpp > CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/MachineStateMessage.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.o: ../Messages/StateChangeMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/StateChangeMessage.cpp

CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/StateChangeMessage.cpp > CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Messages/StateChangeMessage.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.o: ../Components/Conveyor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Conveyor.cpp

CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Conveyor.cpp > CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Conveyor.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.o: ../Components/Delivery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Delivery.cpp

CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Delivery.cpp > CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Delivery.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.o: ../Components/Feeder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Feeder.cpp

CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Feeder.cpp > CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/Feeder.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.s

CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.o: CMakeFiles/modbus_simulator_cpp.dir/flags.make
CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.o: ../Components/PaintStation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.o -c /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/PaintStation.cpp

CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/PaintStation.cpp > CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.i

CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nvuletic/git-nexylmao/modbus-simulator-cpp/Components/PaintStation.cpp -o CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.s

# Object files for target modbus_simulator_cpp
modbus_simulator_cpp_OBJECTS = \
"CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.o" \
"CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.o"

# External object files for target modbus_simulator_cpp
modbus_simulator_cpp_EXTERNAL_OBJECTS =

libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Machine.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Component.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Logger/Logger.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Messages/ComponentMessage.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Messages/ActionStatusMessage.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Messages/ConveyorRateMessage.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Messages/CountMessage.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Messages/MachineStateMessage.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Messages/StateChangeMessage.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Components/Conveyor.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Components/Delivery.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Components/Feeder.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/Components/PaintStation.cpp.o
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/build.make
libmodbus_simulator_cpp.a: CMakeFiles/modbus_simulator_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX static library libmodbus_simulator_cpp.a"
	$(CMAKE_COMMAND) -P CMakeFiles/modbus_simulator_cpp.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modbus_simulator_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/modbus_simulator_cpp.dir/build: libmodbus_simulator_cpp.a

.PHONY : CMakeFiles/modbus_simulator_cpp.dir/build

CMakeFiles/modbus_simulator_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/modbus_simulator_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/modbus_simulator_cpp.dir/clean

CMakeFiles/modbus_simulator_cpp.dir/depend:
	cd /home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nvuletic/git-nexylmao/modbus-simulator-cpp /home/nvuletic/git-nexylmao/modbus-simulator-cpp /home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug /home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug /home/nvuletic/git-nexylmao/modbus-simulator-cpp/cmake-build-debug/CMakeFiles/modbus_simulator_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/modbus_simulator_cpp.dir/depend

