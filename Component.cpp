//
// Created by nvuletic on 11.9.19..
//

#include "Component.h"

Component::Component(const std::string &name, ComponentMessageReceiver& machine) : name(name), machine(machine), logger(name) {}

const std::string &Component::getName() const {
    return name;
}

void Component::Emit(ComponentMessageType type, std::string content) {
    machine.ReceiveMessage(std::make_shared<ComponentMessage>(type, content));
}
