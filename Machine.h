#ifndef MODBUS_SIMULATOR_CPP_MACHINE_H
#define MODBUS_SIMULATOR_CPP_MACHINE_H

#include <vector>
#include "Messages/ComponentMessage.h"
#include "Logger/Logger.h"
#include "Interfaces/ComponentMessageReceiver.h"
#include "Interfaces/MachineStateMessageReceiver.h"
#include "Interfaces/ExternalMessageReceiver.h"
#include "Interfaces/ExternalMachineStateReceiver.h"
#include "Messages/ActionStatusMessage.h"

class Machine : public ComponentMessageReceiver {
private:
    bool running;
    std::string name;
    std::vector<std::shared_ptr<ComponentMessage>> messages;
    std::vector<MachineStateMessageReceiver *> components;
    std::vector<ExternalMessageReceiver *> externalMessageReceivers;
    std::vector<ExternalMachineStateReceiver *> externalMachineStateReceivers;
    Logger logger;
    void Emit(MachineMessageType, const std::string&, const std::function<void(std::shared_ptr<ComponentMessage>)>&);
public:
    explicit Machine(const std::string &name);

    bool isRunning() const;

    const std::string &getName() const;

    const std::vector<std::shared_ptr<ComponentMessage>> &getMessages() const;

    const std::vector<MachineStateMessageReceiver *> &getComponents() const;

    const std::vector<ExternalMessageReceiver *> &getExternalMessageReceivers() const;

    const std::vector<ExternalMachineStateReceiver *> &getExternalMachineStateReceivers() const;

    ActionStatusMessage Start();

    ActionStatusMessage Stop();

    ActionStatusMessage CheckForErrors(bool);

    void ReceiveMessage(std::shared_ptr<ComponentMessage> ptr) override;
};

#endif //MODBUS_SIMULATOR_CPP_MACHINE_H