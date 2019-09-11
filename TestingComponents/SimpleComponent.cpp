//
// Created by nvuletic on 11.9.19..
//

#include "SimpleComponent.h"

SimpleComponent::SimpleComponent(const std::string &name, ComponentMessageReceiver& machine) : Component(name,
                                                                                                         machine) {}

void SimpleComponent::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> ptr) {

}
