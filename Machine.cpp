#include <iostream>
#include "Machine.h"
#include "Messages/MachineStateMessage.h"

bool Machine::isRunning() const {
    return running;
}

const std::string &Machine::getName() const {
    return name;
}

const std::vector<std::shared_ptr<ComponentMessage>> &Machine::getMessages() const {
    return messages;
}

std::vector<std::shared_ptr<MachineStateMessageReceiver>> &Machine::getComponents() {
    return components;
}

const std::vector<std::shared_ptr<ExternalMessageReceiver>> &Machine::getExternalMessageReceivers() const {
    return externalMessageReceivers;
}

const std::vector<std::shared_ptr<ExternalMachineStateReceiver>> &Machine::getExternalMachineStateReceivers() const {
    return externalMachineStateReceivers;
}

Machine::Machine(const std::string &name) : name(name), logger(name) {
    this->running = false;
    this->name = name;
}

void Machine::EmitToComponents(MachineMessageType type, const std::string& content, const std::function<void(std::shared_ptr<ComponentMessage>)>& callback) {
    std::shared_ptr<MachineStateMessage> message = std::make_shared<MachineStateMessage>(type, content, callback);
    for (std::shared_ptr<MachineStateMessageReceiver> component: components) {
        component->ReceiveMachineStateMessage(message);
    }
}

void Machine::addComponent(std::shared_ptr<MachineStateMessageReceiver> component) {
    components.push_back(component);
}

ActionStatusMessage Machine::start() {
    if (running) {
        return {message, "Machine is already running."};
    }

    ActionStatusMessage result = checkForErrors(true);
    if (result.getType() == good) {
        // Notify all the components that we are starting
        this->EmitToComponents(Starting, "", nullptr);

        running = true;

        // Notify all the external listeners that we are starting up
        for (auto &externalMachineStateReceiver : externalMachineStateReceivers) {
            externalMachineStateReceiver->ReceiveMachineState(true);
        }

        return {good, ""};
    }

    // If there was an error, return it
    return result;
}

ActionStatusMessage Machine::stop() {
    if (!running) {
        return {message, "Machine is already stopped."};
    }

    // Notify all the components that we are shutting down
    this->EmitToComponents(Stopping, "", nullptr);

    running = false;

    // Notify all the external listeners that we are shutting down
    for (auto &externalMachineStateReceiver : externalMachineStateReceivers) {
        externalMachineStateReceiver->ReceiveMachineState(true);
    }

    return {good, ""};
}

ActionStatusMessage Machine::checkForErrors(bool starting = false) {
    if (running) {
        return {message, "Machine is already running."};
    }

    try {
        // Check all components if they're working
        for (auto &component : components) {
            // Generate the callback for component reply
            auto callback = [&](const std::shared_ptr<ComponentMessage> &message) {
                // If it's notification worthy
                if (message->getType() != Neutral && starting) {
                    for (auto &externalMessageReceiver : externalMessageReceivers) {
                        externalMessageReceiver->ReceiveMessage(message);
                    }
                }

                // If it's breaking
                if (message->getType() == Severe) {
                    throw std::runtime_error(message->getContent());
                }
            };

            // Send the message to each component
            this->EmitToComponents(MachineMessageType::CheckForErrors, "", callback);
        }

        return {good, ""};
    }
    catch (const std::exception &e) {
        logger.Log("Machine detected an error.");
        logger.Log(const_cast<char *>(e.what()));
        return {bad, const_cast<char *>(e.what())};
    }
}

void Machine::receiveMessages(std::shared_ptr<ComponentMessage> ptr) {
    // Write it to console
    logger.Log(ptr->getContent());
    // Add to the vector of messages
    messages.push_back(ptr);
    // Notify all the external listeners
    for (auto &externalMessageReceiver : externalMessageReceivers) {
        externalMessageReceiver->ReceiveMessage(ptr);
    }
    // stop the machine if necessary
    if (ptr->getType() == Severe) {
        stop();
    }
}
