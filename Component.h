//
// Created by nvuletic on 11.9.19..
//

#ifndef MODBUS_SIMULATOR_CPP_COMPONENT_H
#define MODBUS_SIMULATOR_CPP_COMPONENT_H

#include "Logger/Logger.h"
#include "Machine.h"
#include "Interfaces/MachineStateMessageReceiver.h"
#include "Interfaces/ComponentMessageReceiver.h"

class Component : public MachineStateMessageReceiver {
protected:
    std::string name;
    std::shared_ptr<ComponentMessageReceiver> machine;
    Logger logger;
public:
    Component(const std::string &name, std::shared_ptr<ComponentMessageReceiver> machine);

    const std::string &getName() const;

    void Emit(ComponentMessageType type, std::string content);

    virtual void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage>) = 0;
};


#endif //MODBUS_SIMULATOR_CPP_COMPONENT_H
