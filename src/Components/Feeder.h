//
// Created by nvuletic on 10.9.19..
//

#ifndef MBS_SIMULATOR_FEEDER_H
#define MBS_SIMULATOR_FEEDER_H

#include "Interfaces/CountMessageReceiver.h"
#include "Machine.h"
#include "Messages/ComponentMessage.h"
#include "TempoComponent.h"

#include <vector>

namespace simulator
{
    class Feeder : public TempoComponent
    {
    public:
        int getCapacity() const;

        int getCount() const override;

        double getPercentage();

        std::vector<std::shared_ptr<CountMessageReceiver>>& getCountMessageReceiver();

        Feeder(std::string name, ComponentMessageReceiver& machine, int capacity, int initialCount);

        bool modifyCount(int i) override;

        bool setCount(int i) override;

        bool iterate() override;

        void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message) override;

    protected:
        void EmitCount() override;

    private:
        std::pair<ComponentMessageType, std::string> checkCount();

        bool checkCountAndEmit();

        int m_capacity;
        int m_count;
        bool m_warning20;
        bool m_warning10;
        std::string m_w20;
        std::string m_w10;
        std::string m_wEmpty;
        std::vector<std::shared_ptr<CountMessageReceiver>> m_countMessageReceiver;
    };
}

#endif //MBS_SIMULATOR_FEEDER_H
