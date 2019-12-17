//
// Created by nvuletic on 8.8.19..
//

#include "ComponentMessage.h"

ComponentMessage::ComponentMessage(ComponentMessageType type, const std::string &content) : m_type(type),
                                                                                            m_content(content) {}

ComponentMessageType ComponentMessage::getType() const {
    return m_type;
}

const std::string &ComponentMessage::getContent() const {
    return m_content;
}
