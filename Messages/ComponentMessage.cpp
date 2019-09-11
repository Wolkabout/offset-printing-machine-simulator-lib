//
// Created by nvuletic on 8.8.19..
//

#include "ComponentMessage.h"

ComponentMessage::ComponentMessage(ComponentMessageType type, const std::string &content) : type(type),
                                                                                            content(content) {}

ComponentMessageType ComponentMessage::getType() const {
    return type;
}

const std::string &ComponentMessage::getContent() const {
    return content;
}
