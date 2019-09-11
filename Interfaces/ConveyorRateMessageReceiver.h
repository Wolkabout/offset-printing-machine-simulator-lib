//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_CONVEYORRATEMESSAGERECEIVER_H
#define MBS_SIMULATOR_CONVEYORRATEMESSAGERECEIVER_H

#include <memory>
#include "../Messages/ConveyorRateMessage.h"

class ConveyorRateMessageReceiver {
public:
    virtual void ReceiveMessage(std::shared_ptr<ConveyorRateMessage>) = 0;
};

#endif //MBS_SIMULATOR_CONVEYORRATEMESSAGERECEIVER_H
