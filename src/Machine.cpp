#include <iostream>
#include "Machine.h"
#include "Messages/MachineStateMessage.h"

bool Machine::isRunning() const {
    return m_running;
}

const std::string &Machine::getName() const {
    return m_name;
}

std::vector<std::shared_ptr<ComponentMessage>> &Machine::getMessages() {
    return m_messages;
}

std::vector<std::shared_ptr<MachineStateMessageReceiver>> &Machine::getComponents() {
    return m_components;
}

std::vector<std::shared_ptr<ExternalMachineMessageReceiver>> &Machine::getExternalMessageReceivers() {
    return m_externalMessageReceivers;
}

std::vector<std::shared_ptr<ExternalMachineStateReceiver>> &Machine::getExternalMachineStateReceivers() {
    return m_externalMachineStateReceivers;
}

Machine::Machine(const std::string &name) : m_name(name), m_logger(name) {
    this->m_running = false;
    this->m_name = name;
}

void Machine::EmitToComponents(MachineMessageType type, const std::string& content, const std::function<void(std::shared_ptr<ComponentMessage>)>& callback) {
    std::shared_ptr<MachineStateMessage> message = std::make_shared<MachineStateMessage>(type, content, callback);
    for (std::shared_ptr<MachineStateMessageReceiver> component: m_components) {
        component->ReceiveMachineStateMessage(message);
    }
}

void Machine::addComponent(std::shared_ptr<MachineStateMessageReceiver> component) {
    m_components.push_back(component);
}

ActionStatusMessage Machine::start() {
    if (m_running) {
        return {message, "Machine is already m_running."};
    }

    ActionStatusMessage result = checkForErrors(true);
    if (result.getType() == good) {
        // Notify all the m_components that we are starting
        m_running = true;
        this->EmitToComponents(Starting, "", nullptr);

        // Notify all the external listeners that we are starting up
        for (auto &externalMachineStateReceiver : m_externalMachineStateReceivers) {
            externalMachineStateReceiver->ReceiveMachineState(true);
        }

        return {good, ""};
    }

    // If there was an error, return it
    return result;
}

ActionStatusMessage Machine::stop() {
    if (!m_running) {
        return {message, "Machine is already stopped."};
    }

    m_running = false;

    // Notify all the m_components that we are shutting down
    this->EmitToComponents(Stopping, "", nullptr);

    // Notify all the external listeners that we are shutting down
    for (auto &externalMachineStateReceiver : m_externalMachineStateReceivers) {
        externalMachineStateReceiver->ReceiveMachineState(false);
    }

    return {good, ""};
}

ActionStatusMessage Machine::checkForErrors(bool starting = false) {
    if (m_running) {
        return {message, "Machine is already m_running."};
    }

    try {
        // Check all m_components if they're working
        // Generate the callback for component reply
        auto callback = [&](const std::shared_ptr<ComponentMessage> &message) {
            m_logger.Log("(CFE) " + std::to_string(message->getType()) + " | " + message->getContent());
            // If it's notification worthy
            if (message->getType() != Neutral && starting) {
                for (auto &externalMessageReceiver : m_externalMessageReceivers) {
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

        return {good, ""};
    }
    catch (const std::exception &e) {
        m_logger.Log("Machine detected an error.");
        m_logger.Log(const_cast<char *>(e.what()));
        return {bad, const_cast<char *>(e.what())};
    }
}

void Machine::receiveMessages(std::shared_ptr<ComponentMessage> ptr) {
    // Write it to console
    m_logger.Log("(E) " + std::to_string(ptr->getType()) + " | " + ptr->getContent());
    // Add to the vector of m_messages
    m_messages.push_back(ptr);
    // Notify all the external listeners
    for (auto &externalMessageReceiver : m_externalMessageReceivers) {
        externalMessageReceiver->ReceiveMessage(ptr);
    }
    // stop the machine if necessary
    if (ptr->getType() == Severe) {
        stop();
    }
}
