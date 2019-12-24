//
// Created by nvuletic on 8.8.19..
//

#ifndef MBS_SIMULATOR_CPP_COMPONENTMESSAGE_H
#define MBS_SIMULATOR_CPP_COMPONENTMESSAGE_H

#include <string>

enum class ComponentMessageType {
    Neutral, Alarming, Severe
};

/*
 * This is an internal class used for carrying m_messages
 * from m_components to machines, also, machine can notify
 * external objects with this message.
 */

class ComponentMessage {
private:
    ComponentMessageType m_type;
    std::string m_content;
public:
    ComponentMessage(ComponentMessageType type, const std::string &content);

    ComponentMessageType getType() const;

    const std::string &getContent() const;
};

#endif //MBS_SIMULATOR_CPP_COMPONENTMESSAGE_H
