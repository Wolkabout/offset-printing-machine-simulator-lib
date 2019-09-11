//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_CONVEYOR_H
#define MBS_SIMULATOR_CONVEYOR_H

#include <thread>
#include <vector>
#include "../Component.h"
#include "TempoComponent.h"
#include "../Interfaces/ConveyorRateMessageReceiver.h"

#define MAX_ARRAY 10

class Conveyor : public Component {
private:
    int ratePerHour;
    int maxRatePerHour;
    int minRatePerHour = 1000;
    int period;
    bool runningLoop;
    std::thread loop;
    std::vector<TempoComponent *> components;
    std::vector<ConveyorRateMessageReceiver *> rateMessageReceivers;

    void runTempo();

public:
    Conveyor(char *name, Machine &machine, int maxRatePerHour, int initialRatePerHour);

    const std::vector<ConveyorRateMessageReceiver *> &getRateMessageReceivers() const;

    void ReceiveMachineStateMessage(MachineStateMessage *stateMessage) override;

    int getPeriod() const;

    int getRatePerHour() const;

    void setRatePerHour(int value);

    int getMaxRatePerHour() const;

    int getMinRatePerHour() const;
};

#endif //MBS_SIMULATOR_CONVEYOR_H
