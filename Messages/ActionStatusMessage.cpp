//
// Created by nvuletic on 8.8.19..
//

#include "ActionStatusMessage.h"

ActionStatusMessage::ActionStatusMessage(ActionStatusType type, const std::string &content) : type(type),
                                                                                              content(content) {}

ActionStatusType ActionStatusMessage::getType() const {
    return type;
}

const std::string &ActionStatusMessage::getContent() const {
    return content;
}
