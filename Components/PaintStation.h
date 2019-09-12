//
// Created by nvuletic on 10.9.19..
//

#ifndef MBS_SIMULATOR_PAINTSTATION_H
#define MBS_SIMULATOR_PAINTSTATION_H


#include "TempoComponent.h"
#include "../Interfaces/CountMessageReceiver.h"

class PaintStation : public TempoComponent {
private:
    int capacity;
    int count;
    bool warning20;
    bool warning10;
    char *w20;
    char *w10;
    char *wempty;
    std::vector<CountMessageReceiver *> countMessageReceiver;

    std::shared_ptr<ComponentMessage> checkCount();

    bool checkCountAndEmit();

public:
    const std::vector<CountMessageReceiver *> &getCountMessageReceiver() const;

    int getCapacity() const;

    int getCount() const;

    double getPercentage();

    PaintStation(std::string name, Machine &machine, int capacity, int initialCount);

    bool modifyCount(int i) override;

    bool iterate() override;

    void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> ptr) override;
};


#endif //MBS_SIMULATOR_PAINTSTATION_H
