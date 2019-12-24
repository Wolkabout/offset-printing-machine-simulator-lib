//
// Created by nvuletic on 11.9.19..
//

#ifndef MODBUS_SIMULATOR_CPP_COMPONENT_H
#define MODBUS_SIMULATOR_CPP_COMPONENT_H

#include "logger/Logger.h"
#include "interfaces/MachineStateMessageReceiver.h"
#include "interfaces/ComponentMessageReceiver.h"
#include "Machine.h"

namespace simulator
{
    class Component : public MachineStateMessageReceiver
    {
    public:
        const std::string& getName() const;

        Component(const std::string& name, ComponentMessageReceiver& machine);

        void Emit(ComponentMessageType type, const std::string& content);

        virtual void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage>) = 0;

    protected:
        std::string m_name;
        ComponentMessageReceiver& m_machine;
        Logger m_logger;
    };
}

#endif //MODBUS_SIMULATOR_CPP_COMPONENT_H
