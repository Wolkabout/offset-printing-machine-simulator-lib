//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_DELIVERY_H
#define MBS_SIMULATOR_DELIVERY_H

#include <string>
#include "TempoComponent.h"
#include "../Interfaces/CountMessageReceiver.h"

class Delivery : public TempoComponent {
private:
    int capacity;
    int count;
    bool warning80;
    bool warning90;
    char *w80;
    char *w90;
    char *wfull;
    std::vector<ComponentMessage> messages;
    std::vector<CountMessageReceiver *> countMessageReceiver;

    std::shared_ptr<ComponentMessage> checkCount();

    bool checkCountAndEmit();

public:
    const std::vector<CountMessageReceiver *> &getCountMessageReceiver() const;

    int getCapacity() const;

    int getCount() const;

    double getPercentage();

    Delivery(char *name, Machine *machine, int capacity, int initialCount);

    bool modifyCount(int i) override;

    bool iterate() override;

    void ReceiveMachineStateMessage(MachineStateMessage *stateMessage) override;
};


#endif //MBS_SIMULATOR_DELIVERY_H
