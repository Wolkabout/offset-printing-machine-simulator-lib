//
// Created by nvuletic on 8.8.19..
//

#ifndef MBS_SIMULATOR_CPP_ACTIONSTATUSMESSAGE_H
#define MBS_SIMULATOR_CPP_ACTIONSTATUSMESSAGE_H

#include <string>

enum ActionStatusType {
    good, bad, message
};

/*
 * This class is used to carry the message of
 * Machine actions like Start(), Stop(), CheckForErrors()
 */

class ActionStatusMessage {
private:
    ActionStatusType type;
    std::string content;
public:
    ActionStatusMessage(ActionStatusType type, const std::string &content);

    ActionStatusType getType() const;

    const std::string &getContent() const;
};


#endif //MBS_SIMULATOR_CPP_ACTIONSTATUSMESSAGE_H
