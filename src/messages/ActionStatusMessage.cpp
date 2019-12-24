//
// Created by nvuletic on 8.8.19..
//

#include "ActionStatusMessage.h"

namespace simulator
{
    ActionStatusMessage::ActionStatusMessage(ActionStatusType type, const std::string& content) : m_type(type),
                                                                                                  m_content(content) {}

    ActionStatusType ActionStatusMessage::getType() const
    {
        return m_type;
    }

    const std::string& ActionStatusMessage::getContent() const
    {
        return m_content;
    }
}
