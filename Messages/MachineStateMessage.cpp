//
// Created by nvuletic on 8.8.19..
//

#include <memory>
#include "MachineStateMessage.h"

MachineStateMessage::MachineStateMessage(MachineMessageType type, const std::string &content,
                                         const std::function<void(std::shared_ptr<ComponentMessage>)> &callback) : type(
        type), content(content), callback(callback) {}

MachineMessageType MachineStateMessage::getType() const {
    return type;
}

std::function<void(std::shared_ptr<ComponentMessage>)> MachineStateMessage::getCallback() {
    return callback;
}

const std::string &MachineStateMessage::getContent() const {
    return content;
}


