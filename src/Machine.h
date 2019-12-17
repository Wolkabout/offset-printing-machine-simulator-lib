#ifndef MODBUS_SIMULATOR_CPP_MACHINE_H
#define MODBUS_SIMULATOR_CPP_MACHINE_H

#include <vector>
#include "Component.h"
#include "Logger/Logger.h"
#include "Interfaces/ComponentMessageReceiver.h"
#include "Interfaces/ExternalMachineStateReceiver.h"
#include "Interfaces/ExternalMachineMessageReceiver.h"
#include "Interfaces/MachineStateMessageReceiver.h"
#include "Messages/ComponentMessage.h"
#include "Messages/ActionStatusMessage.h"
#include "Messages/MachineStateMessage.h"

class Machine : public ComponentMessageReceiver, std::enable_shared_from_this<Machine> {
private:
    bool m_running;
    std::string m_name;
    std::vector<std::shared_ptr<ComponentMessage>> m_messages;
    std::vector<std::shared_ptr<MachineStateMessageReceiver>> m_components;
    std::vector<std::shared_ptr<ExternalMachineMessageReceiver>> m_externalMessageReceivers;
    std::vector<std::shared_ptr<ExternalMachineStateReceiver>> m_externalMachineStateReceivers;
    Logger m_logger;
    void EmitToComponents(MachineMessageType type, const std::string &content,
            const std::function<void(std::shared_ptr<ComponentMessage>)> &callback);
public:
    bool isRunning() const;

    const std::string &getName() const;

    std::vector<std::shared_ptr<ComponentMessage>> &getMessages();

    std::vector<std::shared_ptr<MachineStateMessageReceiver>> &getComponents();

    std::vector<std::shared_ptr<ExternalMachineMessageReceiver>> &getExternalMessageReceivers();

    std::vector<std::shared_ptr<ExternalMachineStateReceiver>> &getExternalMachineStateReceivers();

    Machine(const std::string &name);

    void addComponent(std::shared_ptr<MachineStateMessageReceiver>);

    ActionStatusMessage start();

    ActionStatusMessage stop();

    ActionStatusMessage checkForErrors(bool);

    void receiveMessages(std::shared_ptr<ComponentMessage> ptr) override;
};

#endif //MODBUS_SIMULATOR_CPP_MACHINE_H