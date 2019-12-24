//
// Created by nvuletic on 9.9.19..
//

#include "Conveyor.h"

#include <cmath>

namespace simulator
{
    int Conveyor::getRatePerHour() const
    {
        return m_ratePerHour;
    }

    int Conveyor::getMaxRatePerHour() const
    {
        return m_maxRatePerHour;
    }

    int Conveyor::getMinRatePerHour() const
    {
        return m_minRatePerHour;
    }

    int Conveyor::getPeriod() const
    {
        return m_period;
    }

    std::vector<std::shared_ptr<TempoComponent>>& Conveyor::getComponents()
    {
        return m_components;
    }

    std::vector<std::shared_ptr<ConveyorRateMessageReceiver>>& Conveyor::getRateMessageReceivers()
    {
        return m_rateMessageReceivers;
    }

    void Conveyor::setRatePerHour(int value)
    {
        if (value < m_minRatePerHour || value > m_maxRatePerHour)
        {
            throw std::invalid_argument("The rate has to be in the appropriate range.");
        }
        m_ratePerHour = value;
        m_period = (int) round(3600 / (double) m_ratePerHour * 1000);

        std::shared_ptr<ConveyorRateMessage> message =
                std::make_shared<ConveyorRateMessage>(m_ratePerHour);
        for (auto& conveyorRateMessageReceiver : m_rateMessageReceivers)
        {
            conveyorRateMessageReceiver->ReceiveMessage(message);
        }
    }

    Conveyor::Conveyor(const std::string& name, ComponentMessageReceiver& machine, int maxRatePerHour,
                       int initialRatePerHour) : Component(name, machine)
    {
        if (maxRatePerHour < m_minRatePerHour)
        {
            throw std::invalid_argument(
                    "You can\'t put a rate lower than the minimut rate per hour! (" +
                    std::to_string(m_minRatePerHour) + ')');
        }
        if (initialRatePerHour > maxRatePerHour)
        {
            throw std::invalid_argument("You can\'t put a higher initial rate than the maximum rate per hour! (" +
                                        std::to_string(maxRatePerHour) + ')');
        }
        m_ratePerHour = initialRatePerHour;
        m_period = (int) round(3600 / (double) m_ratePerHour * 1000);
        this->m_maxRatePerHour = maxRatePerHour;
    }

    void Conveyor::runTempo()
    {
        m_logger.Log("Started task!");
        while (m_runningLoop)
        {
            m_logger.Log("Tempo " + std::to_string(m_period) + "ms!");
            for (auto& component: m_components)
            {
                if (!component->iterate())
                {
                    break;
                }
            }
            std::chrono::milliseconds timespan(m_period);
            std::this_thread::sleep_for(timespan);
        }
    }

    void Conveyor::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message)
    {
        m_logger.Log("(SM) " + std::to_string(static_cast<double>(message->getType())) +
        " | " + message->getContent());
        switch (message->getType())
        {
            case MachineMessageType::STARTING:
                m_components.clear();
                for (const std::shared_ptr<MachineStateMessageReceiver>& component :
                        ((Machine&) m_machine).getComponents())
                {
                    m_logger.Log("Found component " + ((TempoComponent&) *component).getName());
                    try
                    {
                        auto& tc = dynamic_cast<TempoComponent&>(*component);
                        m_components.push_back(std::dynamic_pointer_cast<TempoComponent>(component));
                    }
                    catch (std::exception& e)
                    {
                        m_logger.Log(((Component &) *component).getName() + " is not a tempo component!");
                    }
                }
                m_runningLoop = true;
                m_logger.Log("(SM) Found "
                             + std::to_string(m_components.size()) + " tempo m_components!");
                m_loop = std::thread(&Conveyor::runTempo, this);
                break;
            case MachineMessageType::CHECK_FOR_ERRORS:
                if (message->getCallback() != nullptr)
                {
                    std::function<void(std::shared_ptr<ComponentMessage>)> callback = message->getCallback();
                    callback(std::make_shared<ComponentMessage>(ComponentMessageType::NEUTRAL, ""));
                }
                break;
            case MachineMessageType::STOPPING:
                m_runningLoop = false;
                m_loop.detach();
                break;
        }
    }
}
