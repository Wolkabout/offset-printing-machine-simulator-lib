//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_CONVEYOR_H
#define MBS_SIMULATOR_CONVEYOR_H

#include "Component.h"
#include "interfaces/ConveyorRateMessageReceiver.h"
#include "TempoComponent.h"

#include <thread>
#include <vector>

namespace simulator
{
    class Conveyor : public Component
    {
    public:
        int getPeriod() const;

        int getRatePerHour() const;

        void setRatePerHour(int value);

        int getMaxRatePerHour() const;

        int getMinRatePerHour() const;

        std::vector<std::shared_ptr<TempoComponent>>& getComponents();

        std::vector<std::shared_ptr<ConveyorRateMessageReceiver>>& getRateMessageReceivers();

        Conveyor(const std::string& name, ComponentMessageReceiver& machine, int maxRatePerHour,
                 int initialRatePerHour);

        void ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> ptr) override;

    private:
        void runTempo();

        int m_ratePerHour;
        int m_maxRatePerHour;
        int m_minRatePerHour = 1000;
        int m_period;
        bool m_runningLoop;
        std::thread m_loop;
        std::vector<std::shared_ptr<TempoComponent>> m_components;
        std::vector<std::shared_ptr<ConveyorRateMessageReceiver>> m_rateMessageReceivers;
    };
}

#endif //MBS_SIMULATOR_CONVEYOR_H
