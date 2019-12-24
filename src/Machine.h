#ifndef MODBUS_SIMULATOR_CPP_MACHINE_H
#define MODBUS_SIMULATOR_CPP_MACHINE_H

#include "Component.h"
#include "logger/Logger.h"
#include "interfaces/ComponentMessageReceiver.h"
#include "interfaces/ExternalMachineStateReceiver.h"
#include "interfaces/ExternalMachineMessageReceiver.h"
#include "interfaces/MachineStateMessageReceiver.h"
#include "messages/ActionStatusMessage.h"
#include "messages/ComponentMessage.h"
#include "messages/MachineStateMessage.h"

#include <vector>

namespace simulator
{
    class Machine : public ComponentMessageReceiver
    {
    public:
        bool isRunning() const;

        const std::string& getName() const;

        std::vector<std::shared_ptr<ComponentMessage>>& getMessages();

        std::vector<std::shared_ptr<MachineStateMessageReceiver>>& getComponents();

        std::vector<std::shared_ptr<ExternalMachineMessageReceiver>>& getExternalMessageReceivers();

        std::vector<std::shared_ptr<ExternalMachineStateReceiver>>& getExternalMachineStateReceivers();

        Machine(const std::string& name);

        void addComponent(std::shared_ptr<MachineStateMessageReceiver>);

        ActionStatusMessage start();

        ActionStatusMessage stop();

        ActionStatusMessage checkForErrors(bool);

        void receiveMessages(std::shared_ptr<ComponentMessage> ptr) override;

    private:
        void EmitToComponents(MachineMessageType type, const std::string& content,
                              const std::function<void(std::shared_ptr<ComponentMessage>)>& callback);

        Logger m_logger;

        bool m_running;
        std::string m_name;
        std::vector<std::shared_ptr<ComponentMessage>> m_messages;
        std::vector<std::shared_ptr<MachineStateMessageReceiver>> m_components;
        std::vector<std::shared_ptr<ExternalMachineMessageReceiver>> m_externalMessageReceivers;
        std::vector<std::shared_ptr<ExternalMachineStateReceiver>> m_externalMachineStateReceivers;
    };
}

#endif //MODBUS_SIMULATOR_CPP_MACHINE_H