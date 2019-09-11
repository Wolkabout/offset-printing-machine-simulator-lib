//
// Created by nvuletic on 11.9.19..
//

#ifndef MODBUS_SIMULATOR_CPP_COMPONENT_H
#define MODBUS_SIMULATOR_CPP_COMPONENT_H

#include "Interfaces/MachineStateMessageReceiver.h"
#include "Interfaces/ComponentMessageReceiver.h"
#include "Logger/Logger.h"

class Component : public MachineStateMessageReceiver {
protected:
    std::string name;
    ComponentMessageReceiver& machine;
    Logger logger;
public:
    Component(const std::string &name, ComponentMessageReceiver& machine);

    const std::string &getName() const;

    void Emit(ComponentMessageType type, std::string content);
};


#endif //MODBUS_SIMULATOR_CPP_COMPONENT_H
