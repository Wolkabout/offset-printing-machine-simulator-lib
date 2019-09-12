//
// Created by nvuletic on 10.9.19..
//

#include <cmath>
#include "PaintStation.h"

int PaintStation::getCapacity() const {
    return capacity;
}

int PaintStation::getCount() const {
    return count;
}

double PaintStation::getPercentage() {
    return round((double) count / capacity);
}

std::vector<std::shared_ptr<CountMessageReceiver>> &PaintStation::getCountMessageReceiver() {
    return countMessageReceiver;
}

PaintStation::PaintStation(std::string name, ComponentMessageReceiver& machine, int capacity, int initialCount) : TempoComponent(name, machine) {
    if (capacity < 0) {
        throw std::invalid_argument("Capacity can't be a negative number!");
    }
    if (initialCount < 0 || initialCount > capacity) {
        throw std::invalid_argument("Your initial amount of paper must fit in the capacity!");
    }

    w20 = "The " + std::string(name) + " has less than 20% of its capacity left.";
    w10 = "The " + std::string(name) + " has less than 10% of its capacity left.";
    wempty = "The " + std::string(name) + " is empty.";

    this->capacity = capacity;
    this->count = initialCount;
    checkCountAndEmit();
}

std::pair<ComponentMessageType, std::string> PaintStation::checkCount() {
    ComponentMessageType type = Neutral;
    std::string content;
    if (count == 0) {
        type = Severe;
        content = wempty;
        warning10 = true;
        warning20 = true;
    } else if (capacity / 10 > count && !warning10) {
        type = Alarming;
        content = w10;
        warning10 = true;
        warning20 = true;
    } else if (capacity / 5 > count && !warning20) {
        type = Alarming;
        content = w20;
        warning20 = true;
    }
    return std::pair<ComponentMessageType, std::string>(type, content);
}

bool PaintStation::checkCountAndEmit() {
    std::pair<ComponentMessageType, std::string> result = checkCount();
    if (result.first != Neutral) {
        Emit(result.first, result.second);
        return result.first != Severe;
    }
    return true;
}

bool PaintStation::modifyCount(int i) {
    if (capacity - count < i) {
        Emit(Alarming, "You can\'t put more paint than there's room for.");
        return false;
    }

    count += i;
    checkCountAndEmit();
    return true;
}

bool PaintStation::iterate() {
    if (!((Machine &) machine).isRunning()) {
        Emit(Severe, "You can\'t take paint, the machine isn\'t running.");
        return false;
    }
    if (checkCountAndEmit()) {
        count--;
        checkCountAndEmit();
        return true;
    }
    return false;
}

void PaintStation::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> stateMessage) {
    switch (stateMessage->getType()) {
        case Starting:
            logger.Log("Starting work with " + std::to_string(count) + '/' + std::to_string(capacity));
            break;
        case CheckForErrors:
            if (stateMessage->getCallback() != nullptr) {
                std::pair<ComponentMessageType, std::string> result = checkCount();
                std::function<void(std::shared_ptr<ComponentMessage>)> callback = stateMessage->getCallback();
                callback(std::make_shared<ComponentMessage>(result.first, result.second));
            }
            break;
        case Stopping:
            logger.Log("Stopping work with " + std::to_string(count) + '/' + std::to_string(capacity));
            break;
    }
}
