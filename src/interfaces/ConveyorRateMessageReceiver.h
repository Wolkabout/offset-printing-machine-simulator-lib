//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_CONVEYORRATEMESSAGERECEIVER_H
#define MBS_SIMULATOR_CONVEYORRATEMESSAGERECEIVER_H

#include "messages/ConveyorRateMessage.h"

#include <memory>

namespace simulator
{
    class ConveyorRateMessageReceiver
    {
    public:
        virtual ~ConveyorRateMessageReceiver() = default;

        virtual void ReceiveMessage(std::shared_ptr<ConveyorRateMessage>) = 0;
    };
}

#endif //MBS_SIMULATOR_CONVEYORRATEMESSAGERECEIVER_H
