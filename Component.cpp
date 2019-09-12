//
// Created by nvuletic on 11.9.19..
//

#include "Component.h"

#include <utility>

const std::string &Component::getName() const {
    return name;
}

Component::Component(const std::string &name, ComponentMessageReceiver& machine) : name(name), machine(machine), logger(name) {
}

void Component::Emit(ComponentMessageType type, const std::string& content) {
    machine.receiveMessages(std::make_shared<ComponentMessage>(type, content));
}
