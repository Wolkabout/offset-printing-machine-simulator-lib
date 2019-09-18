cmake_minimum_required(VERSION 3.14)
project(modbus_simulator_cpp)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME}
        Machine.cpp
        Machine.h
        Component.cpp
        Component.h
        Logger/Logger.cpp
        Logger/Logger.h
        Interfaces/ComponentMessageReceiver.h
        Interfaces/ConveyorRateMessageReceiver.h
        Interfaces/CountMessageReceiver.h
        Interfaces/ExternalMachineStateReceiver.h
        Interfaces/ExternalMachineMessageReceiver.h
        Interfaces/MachineStateMessageReceiver.h
        Messages/ComponentMessage.cpp
        Messages/ComponentMessage.h
        Messages/ActionStatusMessage.cpp
        Messages/ActionStatusMessage.h
        Messages/ComponentMessage.cpp
        Messages/ComponentMessage.h
        Messages/ConveyorRateMessage.cpp
        Messages/ConveyorRateMessage.h
        Messages/CountMessage.cpp
        Messages/CountMessage.h
        Messages/MachineStateMessage.cpp
        Messages/MachineStateMessage.h
        Messages/StateChangeMessage.cpp
        Messages/StateChangeMessage.h
        Components/Conveyor.cpp
        Components/Conveyor.h
        Components/Delivery.cpp
        Components/Delivery.h
        Components/Feeder.cpp
        Components/Feeder.h
        Components/PaintStation.cpp
        Components/PaintStation.h
        Components/TempoComponent.h)
target_link_libraries(${PROJECT_NAME} pthread)

add_executable(modbus_simulator_testing Test/main.cpp)
target_link_libraries(modbus_simulator_testing ${PROJECT_NAME})