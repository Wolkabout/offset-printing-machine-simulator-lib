//
// Created by nvuletic on 9.8.19..
//

#ifndef MBS_SIMULATOR_MACHINESTATEMESSAGERECEIVER_H
#define MBS_SIMULATOR_MACHINESTATEMESSAGERECEIVER_H

#include <memory>
#include "../Messages/MachineStateMessage.h"

class MachineStateMessageReceiver {
public:
    virtual ~MachineStateMessageReceiver() = default;
    virtual void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage>) = 0;
};

#endif //MBS_SIMULATOR_MACHINESTATEMESSAGERECEIVER_H