//
// Created by nvuletic on 9.9.19..
//

#include <cmath>
#include <sstream>
#include "Conveyor.h"

int Conveyor::getRatePerHour() const {
    return ratePerHour;
}

int Conveyor::getMaxRatePerHour() const {
    return maxRatePerHour;
}

int Conveyor::getMinRatePerHour() const {
    return minRatePerHour;
}

int Conveyor::getPeriod() const {
    return period;
}

std::vector<std::shared_ptr<TempoComponent>> &Conveyor::getComponents() {
    return components;
}

std::vector<std::shared_ptr<ConveyorRateMessageReceiver>> &Conveyor::getRateMessageReceivers() {
    return rateMessageReceivers;
}

void Conveyor::setRatePerHour(int value) {
    if (value < minRatePerHour || value > maxRatePerHour) {
        throw std::invalid_argument("The rate has to be in the appropriate range.");
    }
    ratePerHour = value;
    period = round(3600 / ratePerHour * 1000);

    std::shared_ptr<ConveyorRateMessage> message = std::make_shared<ConveyorRateMessage>(ratePerHour);
    for (auto &conveyorRateMessageReceiver : rateMessageReceivers) {
        conveyorRateMessageReceiver->ReceiveMessage(message);
    }
}

Conveyor::Conveyor(const std::string& name, std::shared_ptr<ComponentMessageReceiver> machine, int maxRatePerHour, int initialRatePerHour) : Component(name, std::move(machine)) {
    if (maxRatePerHour < minRatePerHour) {
        throw std::invalid_argument(
                "You can\'t put a rate lower than the minimut rate per hour! (" + std::to_string(minRatePerHour) + ')');
    }
    if (initialRatePerHour > maxRatePerHour) {
        throw std::invalid_argument("You can\'t put a higher initial rate than the maximum rate per hour! (" +
                                    std::to_string(maxRatePerHour) + ')');
    }
    ratePerHour = initialRatePerHour;
    period = (int) round(3600 / (double) ratePerHour * 1000);
    this->maxRatePerHour = maxRatePerHour;
}

void Conveyor::runTempo() {
    while (runningLoop) {
        logger.Log("Tempo " + std::to_string(period) + "ms!");
        for (auto &component: components) {
            if (!component->iterate()) {
                break;
            }
        }
        std::chrono::milliseconds timespan(period);
        std::this_thread::sleep_for(timespan);
    }
}

//template< class T, class U >
//std::shared_ptr<T> static_pointer_cast( const std::shared_ptr<U>& r ) noexcept
//{
//    auto p = static_cast<typename std::shared_ptr<T>::element_type*>(r.get());
//    return std::shared_ptr<T>(r, p);
//}

void Conveyor::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message) {
    switch (message->getType()) {
        case Starting:
            components.clear();
            for (std::shared_ptr<MachineStateMessageReceiver> component : ((Machine &)machine).getComponents()) {

            }
            runningLoop = true;
            loop = std::thread([&] { runTempo(); });
            break;
        case CheckForErrors:
            if (message->getCallback() != nullptr) {
                std::function<void(std::shared_ptr<ComponentMessage>)> callback = message->getCallback();
                ComponentMessage componentMessage(Neutral, "");
                callback(std::shared_ptr<ComponentMessage>(&componentMessage));
            }
            break;
        case Stopping:
            runningLoop = false;
            break;
    }
}
