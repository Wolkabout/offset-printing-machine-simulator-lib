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
    char *w20;
    char *w10;
    char *wempty;
    std::vector<ComponentMessage> messages;
    std::vector<CountMessageReceiver *> countMessageReceiver;

    std::shared_ptr<ComponentMessage> checkCount();

    bool checkCountAndEmit();

public:
    const std::vector<CountMessageReceiver *> &getCountMessageReceiver() const;

    int getCapacity() const;

    int getCount() const;

    double getPercentage();

    Feeder(char *name, Machine *machine, int capacity, int initialCount);

    bool modifyCount(int i) override;

    bool iterate() override;

    void ReceiveMachineStateMessage(MachineStateMessage *stateMessage) override;
};


#endif //MBS_SIMULATOR_FEEDER_H
