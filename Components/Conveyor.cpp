//
// Created by nvuletic on 9.9.19..
//

#include <cmath>
#include <sstream>
#include "Conveyor.h"
#include "../Messages/ConveyorRateMessage.h"

int Conveyor::getRatePerHour() const {
    return ratePerHour;
}

int Conveyor::getMaxRatePerHour() const {
    return maxRatePerHour;
}

int Conveyor::getMinRatePerHour() const {
    return minRatePerHour;
}

void Conveyor::setRatePerHour(int value) {
    if (value < minRatePerHour || value > maxRatePerHour) {
        throw std::invalid_argument("The rate has to be in the appropriate range.");
    }
    ratePerHour = value;
    period = round(3600 / ratePerHour * 1000);

    ConveyorRateMessage message(ratePerHour);
    for (auto &conveyorRateMessageReceiver : rateMessageReceivers) {
        conveyorRateMessageReceiver->ReceiveMessage(&message);
    }
}

int Conveyor::getPeriod() const {
    return period;
}

Conveyor::Conveyor(char *name, Machine *machine, int maxRatePerHour, int initialRatePerHour) : Component(name,
                                                                                                         machine) {
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

void Conveyor::ReceiveMachineStateMessage(MachineStateMessage *message) {
    switch (message->getType()) {
        case Starting:
            components.clear();
            for (auto component : ((Machine *) machine)->getComponents()) {
                auto *tempoComponent = dynamic_cast<TempoComponent *>(component);
                if (tempoComponent != nullptr) {
                    components.push_back(tempoComponent);
                }
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

const std::vector<ConveyorRateMessageReceiver *> &Conveyor::getRateMessageReceivers() const {
    return rateMessageReceivers;
}
