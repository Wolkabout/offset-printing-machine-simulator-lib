//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_CONVEYORRATEMESSAGE_H
#define MBS_SIMULATOR_CONVEYORRATEMESSAGE_H


class ConveyorRateMessage {
private:
    int currentRate;
public:
    ConveyorRateMessage(int currentRate);

    int getCurrentRate() const;
};


#endif //MBS_SIMULATOR_CONVEYORRATEMESSAGE_H
