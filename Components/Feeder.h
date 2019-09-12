//
// Created by nvuletic on 10.9.19..
//

#ifndef MBS_SIMULATOR_FEEDER_H
#define MBS_SIMULATOR_FEEDER_H


#include <vector>
#include "../Interfaces/CountMessageReceiver.h"
#include "../Messages/ComponentMessage.h"
#include "../Machine.h"
#include "TempoComponent.h"

class Feeder : public TempoComponent {
private:
    int capacity;
    int count;
    bool warning20;
    bool warning10;
    std::string w20;
    std::string w10;
    std::string wempty;
    std::vector<std::shared_ptr<CountMessageReceiver>> countMessageReceiver;

    std::pair<ComponentMessageType, std::string> checkCount();

    bool checkCountAndEmit();

public:
    int getCapacity() const;

    int getCount() const;

    double getPercentage();

    std::vector<std::shared_ptr<CountMessageReceiver>> &getCountMessageReceiver();

    Feeder(std::string name, ComponentMessageReceiver& machine, int capacity, int initialCount);

    bool modifyCount(int i) override;

    bool iterate() override;

    void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> ptr) override;
};


#endif //MBS_SIMULATOR_FEEDER_H
