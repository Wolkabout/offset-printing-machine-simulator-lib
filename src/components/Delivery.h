//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_DELIVERY_H
#define MBS_SIMULATOR_DELIVERY_H

#include "interfaces/CountMessageReceiver.h"
#include "TempoComponent.h"

#include <string>

namespace simulator
{
    class Delivery : public TempoComponent
    {
    public:
        int getCapacity() const;

        int getCount() const override;

        double getPercentage();

        std::vector<std::shared_ptr<CountMessageReceiver>>& getCountMessageReceiver();

        Delivery(const std::string& name, ComponentMessageReceiver& machine, int capacity, int initialCount);

        bool modifyCount(int i) override;

        bool setCount(int i) override;

        bool iterate() override;

        void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message) override;

    protected:
        void EmitCount() override;

    private:
        bool checkCountAndEmit();

        std::pair<ComponentMessageType, std::string> checkCount();

        int m_capacity;
        int m_count;
        bool m_warning80;
        bool m_warning90;
        std::string m_w80;
        std::string m_w90;
        std::string m_wFull;
        std::vector<std::shared_ptr<CountMessageReceiver>> m_CountMessageReceivers;
    };
}

#endif //MBS_SIMULATOR_DELIVERY_H
