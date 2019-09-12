//
// Created by nvuletic on 9.8.19..
//

#ifndef MBS_SIMULATOR_COMPONENTMESSAGERECEIVER_H
#define MBS_SIMULATOR_COMPONENTMESSAGERECEIVER_H

#include <memory>
#include "../Messages/ComponentMessage.h"

class ComponentMessageReceiver {
public:
    virtual void receiveMessages(std::shared_ptr<ComponentMessage>) = 0;
};

#endif //MBS_SIMULATOR_COMPONENTMESSAGERECEIVER_H
