//
// Created by nvuletic on 8.8.19..
//

#include "MachineStateMessage.h"

namespace simulator
{
    MachineStateMessage::MachineStateMessage(MachineMessageType type, const std::string& content,
                                             const std::function<void(std::shared_ptr<ComponentMessage>)>& callback)
            : m_type(type), m_content(content), m_callback(callback) {}

    MachineMessageType MachineStateMessage::getType() const
    {
        return m_type;
    }

    std::function<void(std::shared_ptr<ComponentMessage>)> MachineStateMessage::getCallback()
    {
        return m_callback;
    }

    const std::string& MachineStateMessage::getContent() const
    {
        return m_content;
    }
}
