//
// Created by nvuletic on 10.9.19..
//

#include <cmath>
#include "Feeder.h"

namespace simulator
{
    int Feeder::getCapacity() const
    {
        return m_capacity;
    }

    int Feeder::getCount() const
    {
        return m_count;
    }

    double Feeder::getPercentage()
    {
        return round((double) m_count / m_capacity);
    }

    std::vector<std::shared_ptr<CountMessageReceiver>>& Feeder::getCountMessageReceiver()
    {
        return m_countMessageReceiver;
    }

    Feeder::Feeder(std::string name, ComponentMessageReceiver& machine,
            int capacity, int initialCount) : TempoComponent(name, machine)
    {
        if (capacity < 0)
        {
            throw std::invalid_argument("Capacity can't be a negative number!");
        }
        if (initialCount < 0 || initialCount > capacity)
        {
            throw std::invalid_argument("Your initial amount of paper must fit in the capacity!");
        }

        m_w20 = "The " + std::string(name) + " has less than 20% of its capacity left.";
        m_w10 = "The " + std::string(name) + " has less than 10% of its capacity left.";
        m_wEmpty = "The " + std::string(name) + " is empty.";

        this->m_capacity = capacity;
        this->m_count = initialCount;
        checkCountAndEmit();
        m_warning20 = false;
        m_warning10 = false;
    }

    std::pair<ComponentMessageType, std::string> Feeder::checkCount()
    {
        ComponentMessageType type = ComponentMessageType::NEUTRAL;
        std::string content;
        if (m_count == 0)
        {
            type = ComponentMessageType::SEVERE;
            content = m_wEmpty;
            m_warning10 = true;
            m_warning20 = true;
        }
        else if (m_capacity / 10 > m_count && !m_warning10)
        {
            type = ComponentMessageType::ALARMING;
            content = m_w10;
            m_warning10 = true;
            m_warning20 = true;
        }
        else if (m_capacity / 5 > m_count && !m_warning20)
        {
            type = ComponentMessageType::ALARMING;
            content = m_w20;
            m_warning20 = true;
        }
        return std::pair<ComponentMessageType, std::string>(type, content);
    }

    bool Feeder::checkCountAndEmit()
    {
        std::pair<ComponentMessageType, std::string> result = checkCount();
        if (result.first != ComponentMessageType::NEUTRAL)
        {
            Emit(result.first, result.second);
            return result.first != ComponentMessageType::SEVERE;
        }
        return true;
    }

    bool Feeder::modifyCount(int i)
    {
        if (m_capacity - m_count < i)
        {
            Emit(ComponentMessageType::ALARMING,
                    "You can\'t put more paper than there's room for.");
            return false;
        }

        m_count += i;
        EmitCount();
        checkCountAndEmit();
        return true;
    }

    bool Feeder::setCount(int i)
    {
        m_count = i;
        EmitCount();
        checkCountAndEmit();
        return true;
    }

    bool Feeder::iterate()
    {
        if (!((Machine&) m_machine).isRunning())
        {
            Emit(ComponentMessageType::SEVERE,
                    "You can\'t take paper, the machine isn\'t running.");
            return false;
        }
        if (checkCountAndEmit())
        {
            m_count--;
            EmitCount();
            return true;
        }
        return false;
    }

    void Feeder::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message)
    {
        m_logger.Log("(SM) "
                     + std::to_string(static_cast<double>(message->getType())) + " | " + message->getContent());
        switch (message->getType())
        {
            case MachineMessageType::STARTING:
                m_logger.Log("Starting work with "
                             + std::to_string(m_count) + '/' + std::to_string(m_capacity));
                break;
            case MachineMessageType::CHECK_FOR_ERRORS:
                if (message->getCallback() != nullptr)
                {
                    std::pair<ComponentMessageType, std::string> result = checkCount();
                    std::function<void(std::shared_ptr<ComponentMessage>)> callback = message->getCallback();
                    callback(std::make_shared<ComponentMessage>(result.first, result.second));
                }
                break;
            case MachineMessageType::STOPPING:
                m_logger.Log("Stopping work with "
                             + std::to_string(m_count) + '/' + std::to_string(m_capacity));
                break;
        }
    }

    void Feeder::EmitCount()
    {
        std::shared_ptr<CountMessage> countMessage =
                std::make_shared<CountMessage>(m_count, (double) m_count / m_capacity);
        for (const auto& receiver : m_countMessageReceiver)
        {
            receiver->ReceiveMessage(countMessage);
        }
    }
}
