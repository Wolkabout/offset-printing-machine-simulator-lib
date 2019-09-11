//
// Created by nvuletic on 11.9.19..
//

#ifndef MODBUS_SIMULATOR_CPP_SIMPLECOMPONENT_H
#define MODBUS_SIMULATOR_CPP_SIMPLECOMPONENT_H


#include "../Component.h"

class SimpleComponent : public Component {
public:
    SimpleComponent(const std::string &name, ComponentMessageReceiver& machine);

    void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> ptr) override;
};


#endif //MODBUS_SIMULATOR_CPP_SIMPLECOMPONENT_H
