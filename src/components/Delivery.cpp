//
// Created by nvuletic on 9.9.19..
//

#include "Delivery.h"

#include <cmath>

namespace simulator
{
    int Delivery::getCapacity() const
    {
        return m_capacity;
    }

    int Delivery::getCount() const
    {
        return m_count;
    }

    double Delivery::getPercentage()
    {
        return round((double) m_count / m_capacity);
    }

    std::vector<std::shared_ptr<CountMessageReceiver>>& Delivery::getCountMessageReceiver()
    {
        return m_CountMessageReceivers;
    }

    Delivery::Delivery(const std::string& name, ComponentMessageReceiver& machine, int capacity, int initialCount)
            : TempoComponent(name, machine)
    {
        if (capacity < 0)
        {
            throw std::invalid_argument("Capacity can't be a negative number!");
        }
        if (initialCount < 0 || initialCount > capacity)
        {
            throw std::invalid_argument("Your initial amount of paper must fit in the capacity!");
        }

        m_w80 = "The " + std::string(name) + " is 80% full.";
        m_w90 = "The " + std::string(name) + " is 90% full.";
        m_wFull = "The " + std::string(name) + " is full.";

        this->m_capacity = capacity;
        this->m_count = initialCount;
        checkCountAndEmit();
        m_warning80 = false;
        m_warning90 = false;
    }

    std::pair<ComponentMessageType, std::string> Delivery::checkCount()
    {
        ComponentMessageType type = ComponentMessageType::NEUTRAL;
        std::string content;
        if (m_count == m_capacity)
        {
            type = ComponentMessageType::SEVERE;
            content = m_wFull;
            m_warning90 = true;
            m_warning80 = true;
        }
        else if ((m_capacity / 10) * 9 <= m_count && !m_warning90)
        {
            type = ComponentMessageType::ALARMING;
            content = m_w90;
            m_warning90 = true;
            m_warning80 = true;
        }
        else if ((m_capacity / 5) * 4 <= m_count && !m_warning80)
        {
            type = ComponentMessageType::ALARMING;
            content = m_w80;
            m_warning80 = true;
        }
        return std::pair<ComponentMessageType, std::string>(type, content);
    }

    bool Delivery::checkCountAndEmit()
    {
        std::pair<ComponentMessageType, std::string> result = checkCount();
        if (result.first != ComponentMessageType::NEUTRAL)
        {
            Emit(result.first, result.second);
            return result.first != ComponentMessageType::SEVERE;
        }
        return true;
    }

    bool Delivery::modifyCount(int i)
    {
        if (m_count < i)
        {
            Emit(ComponentMessageType::ALARMING,
                    "You can\'t take more paper than there is here.");
            return false;
        }

        m_count -= i;
        EmitCount();
        checkCountAndEmit();
        return true;
    }

    bool Delivery::setCount(int i)
    {
        m_count = i;
        EmitCount();
        checkCountAndEmit();
        return true;
    }

    bool Delivery::iterate()
    {
        if (!((Machine&) m_machine).isRunning())
        {
            Emit(ComponentMessageType::SEVERE,
                    "You can\'t take paper, the machine isn\'t running.");
            return false;
        }
        if (checkCountAndEmit())
        {
            m_count++;
            EmitCount();
            checkCountAndEmit();
            return true;
        }
        return false;
    }

    void Delivery::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message)
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

    void Delivery::EmitCount()
    {
        std::shared_ptr<CountMessage> countMessage =
                std::make_shared<CountMessage>(m_count, (double) m_count / m_capacity);
        for (auto receiver : m_CountMessageReceivers)
        {
            receiver->ReceiveMessage(countMessage);
        }
    }
}
