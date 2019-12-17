//
// Created by nvuletic on 9.8.19..
//

#ifndef MBS_SIMULATOR_EXTERNALMESSAGERECEIVER_H
#define MBS_SIMULATOR_EXTERNALMESSAGERECEIVER_H

#include <memory>
#include "../Messages/ComponentMessage.h"

class ExternalMachineMessageReceiver {
public:
    virtual ~ExternalMachineMessageReceiver() = default;
    virtual void ReceiveMessage(std::shared_ptr<ComponentMessage>) = 0;
};

#endif //MBS_SIMULATOR_EXTERNALMESSAGERECEIVER_H
