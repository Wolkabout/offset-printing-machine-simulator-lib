//
// Created by nvuletic on 10.9.19..
//

#ifndef MBS_SIMULATOR_FEEDER_H
#define MBS_SIMULATOR_FEEDER_H


#include <vector>
#include "Interfaces/CountMessageReceiver.h"
#include "Messages/ComponentMessage.h"
#include "Machine.h"
#include "TempoComponent.h"

class Feeder : public TempoComponent {
private:
    int m_capacity;
    int m_count;
    bool m_warning20;
    bool m_warning10;
    std::string m_w20;
    std::string m_w10;
    std::string m_wEmpty;
    std::vector<std::shared_ptr<CountMessageReceiver>> m_countMessageReceiver;

    std::pair<ComponentMessageType, std::string> checkCount();

    bool checkCountAndEmit();

protected:
    void EmitCount() override;

public:
    int getCapacity() const;

    int getCount() const override;

    double getPercentage();

    std::vector<std::shared_ptr<CountMessageReceiver>> &getCountMessageReceiver();

    Feeder(std::string name, ComponentMessageReceiver& machine, int capacity, int initialCount);

    bool modifyCount(int i) override;

    bool setCount(int i) override;

    bool iterate() override;

    void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message) override;
};


#endif //MBS_SIMULATOR_FEEDER_H
