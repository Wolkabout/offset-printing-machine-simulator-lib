//
// Created by nvuletic on 9.9.19..
//

#include <cmath>
#include <sstream>
#include <future>
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

Conveyor::Conveyor(const std::string &name, ComponentMessageReceiver &machine, int maxRatePerHour,
                   int initialRatePerHour) : Component(name, machine) {
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
    logger.Log("Started task!");
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

void Conveyor::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message) {
//    logger.Log("(SM) " + std::to_string(message->getType()) + " | " + message->getContent());
    switch (message->getType()) {
        case Starting:
            components.clear();
            for (std::shared_ptr<MachineStateMessageReceiver> component : ((Machine &) machine).getComponents()) {
                logger.Log("Found component " + ((TempoComponent &) *component.get()).getName());
                try {
                    auto &tc = dynamic_cast<TempoComponent&>(*component.get());
                    components.push_back(std::dynamic_pointer_cast<TempoComponent>(component));
                } catch (std::exception& e) {
//                    logger.Log(((Component &) *component.get()).getName() + " is not a tempo component!");
                }
            }
            runningLoop = true;
            logger.Log("(SM) Found " + std::to_string(components.size()) + " tempo components!");
            loop = std::thread(&Conveyor::runTempo, this);
            break;
        case CheckForErrors:
            if (message->getCallback() != nullptr) {
                std::function<void(std::shared_ptr<ComponentMessage>)> callback = message->getCallback();
                callback(std::make_shared<ComponentMessage>(Neutral, ""));
            }
            break;
        case Stopping:
            runningLoop = false;
            break;
    }
}
