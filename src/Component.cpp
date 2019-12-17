//
// Created by nvuletic on 11.9.19..
//

#include "Component.h"

#include <utility>

const std::string &Component::getName() const {
    return m_name;
}

Component::Component(const std::string &name, ComponentMessageReceiver& machine) : m_name(name), m_machine(machine), m_logger(name) {
}

void Component::Emit(ComponentMessageType type, const std::string& content) {
    m_machine.receiveMessages(std::make_shared<ComponentMessage>(type, content));
}
