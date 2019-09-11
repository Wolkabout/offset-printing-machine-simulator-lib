//
// Created by nvuletic on 8.8.19..
//

#ifndef MBS_SIMULATOR_CPP_COMPONENTMESSAGE_H
#define MBS_SIMULATOR_CPP_COMPONENTMESSAGE_H

#include <string>

enum ComponentMessageType {
    Neutral, Alarming, Severe
};

/*
 * This is an internal class used for carrying messages
 * from components to machines, also, machine can notify
 * external objects with this message.
 */

class ComponentMessage {
private:
    ComponentMessageType type;
    std::string content;
public:
    ComponentMessage(ComponentMessageType type, const std::string &content);

    ComponentMessageType getType() const;

    const std::string &getContent() const;
};

#endif //MBS_SIMULATOR_CPP_COMPONENTMESSAGE_H
