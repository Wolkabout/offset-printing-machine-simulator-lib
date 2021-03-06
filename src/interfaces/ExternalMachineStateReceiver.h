//
// Created by nvuletic on 9.8.19..
//

#ifndef MBS_SIMULATOR_EXTERNALMACHINESTATERECEIVER_H
#define MBS_SIMULATOR_EXTERNALMACHINESTATERECEIVER_H

namespace simulator
{
    class ExternalMachineStateReceiver
    {
    public:
        virtual ~ExternalMachineStateReceiver() = default;

        virtual void ReceiveMachineState(bool) = 0;
    };
}

#endif //MBS_SIMULATOR_EXTERNALMACHINESTATERECEIVER_H
