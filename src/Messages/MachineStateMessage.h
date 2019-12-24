//
// Created by nvuletic on 8.8.19..
//

#ifndef MBS_SIMULATOR_CPP_MACHINESTATEMESSAGE_H
#define MBS_SIMULATOR_CPP_MACHINESTATEMESSAGE_H

#include <functional>
#include "ComponentMessage.h"

enum class MachineMessageType {
    Starting, Stopping, CheckForErrors
};

/*
 * This is a class used to carry a message from the machine to m_components.
 * It notifies the component of machines intent.
 */

class MachineStateMessage {
private:
    MachineMessageType m_type;
    std::string m_content;

    std::function<void(std::shared_ptr<ComponentMessage>)> m_callback;

public:
    MachineStateMessage(MachineMessageType type, const std::string &content,
                        const std::function<void(std::shared_ptr<ComponentMessage>)> &callback);

    MachineMessageType getType() const;

    const std::string &getContent() const;

    std::function<void(std::shared_ptr<ComponentMessage>)> getCallback();
};


#endif //MBS_SIMULATOR_CPP_MACHINESTATEMESSAGE_H
