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
    std::string w80;
    std::string w90;
    std::string wfull;
    std::vector<std::shared_ptr<CountMessageReceiver>> countMessageReceiver;

    std::pair<ComponentMessageType, std::string> checkCount();

    bool checkCountAndEmit();

protected:
    void EmitCount() override;

public:
    int getCapacity() const;

    int getCount() const override;

    double getPercentage();

    std::vector<std::shared_ptr<CountMessageReceiver>> &getCountMessageReceiver();

    Delivery(const std::string& name, ComponentMessageReceiver& machine, int capacity, int initialCount);

    bool modifyCount(int i) override;

    bool iterate() override;

    void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message) override;
};


#endif //MBS_SIMULATOR_DELIVERY_H
