//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_CONVEYORRATEMESSAGE_H
#define MBS_SIMULATOR_CONVEYORRATEMESSAGE_H

namespace simulator
{
    class ConveyorRateMessage
    {
    public:
        ConveyorRateMessage(int currentRate);

        int getCurrentRate() const;
    private:
        int m_currentRate;
    };
}

#endif //MBS_SIMULATOR_CONVEYORRATEMESSAGE_H
