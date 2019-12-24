//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_COUNTMESSAGERECEIVER_H
#define MBS_SIMULATOR_COUNTMESSAGERECEIVER_H

#include "messages/CountMessage.h"

#include <memory>

namespace simulator
{
    class CountMessageReceiver
    {
    public:
        virtual ~CountMessageReceiver() = default;

        virtual void ReceiveMessage(std::shared_ptr<CountMessage>) = 0;
    };
}

#endif //MBS_SIMULATOR_COUNTMESSAGERECEIVER_H
