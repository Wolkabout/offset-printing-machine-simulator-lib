//
// Created by nvuletic on 9.9.19..
//

#include <cmath>
#include "Delivery.h"

int Delivery::getCapacity() const {
    return capacity;
}

int Delivery::getCount() const {
    return count;
}

double Delivery::getPercentage() {
    return round((double) count / capacity);
}

std::vector<std::shared_ptr<CountMessageReceiver>> &Delivery::getCountMessageReceiver() {
    return countMessageReceiver;
}

Delivery::Delivery(const std::string& name, ComponentMessageReceiver& machine, int capacity, int initialCount)
        : TempoComponent(name, machine) {
    if (capacity < 0) {
        throw std::invalid_argument("Capacity can't be a negative number!");
    }
    if (initialCount < 0 || initialCount > capacity) {
        throw std::invalid_argument("Your initial amount of paper must fit in the capacity!");
    }

    w80 = "The " + std::string(name) + " is 80% full.";
    w90 = "The " + std::string(name) + " is 90% full.";
    wfull = "The " + std::string(name) + " is full.";

    this->capacity = capacity;
    this->count = initialCount;
    checkCountAndEmit();
    warning80 = false;
    warning90 = false;
}

std::pair<ComponentMessageType, std::string> Delivery::checkCount() {
    ComponentMessageType type = Neutral;
    std::string content;
    if (count == capacity) {
        type = Severe;
        content = wfull;
        warning90 = true;
        warning80 = true;
    } else if ((capacity / 10) * 9 <= count && !warning90) {
        type = Alarming;
        content = w90;
        warning90 = true;
        warning80 = true;
    } else if ((capacity / 5) * 4 <= count && !warning80) {
        type = Alarming;
        content = w80;
        warning80 = true;
    }
    return std::pair<ComponentMessageType, std::string>(type, content);
}

bool Delivery::checkCountAndEmit() {
    std::pair<ComponentMessageType, std::string> result = checkCount();
    if (result.first != Neutral) {
        Emit(result.first, result.second);
        return result.first != Severe;
    }
    return true;
}

bool Delivery::modifyCount(int i) {
    if (count < i) {
        Emit(Alarming, "You can\'t take more paper than there is here.");
        return false;
    }

    count -= i;
    checkCountAndEmit();
    return true;
}

bool Delivery::iterate() {
    if (!((Machine &) machine).isRunning()) {
        Emit(Severe, "You can\'t take paper, the machine isn\'t runing.");
        return false;
    }
    if (checkCountAndEmit()) {
        count++;
        checkCountAndEmit();
        return true;
    }
    return false;
}

void Delivery::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message) {
//    logger.Log("(SM) " + std::to_string(message->getType()) + " | " + message->getContent());
    switch (message->getType()) {
        case Starting:
            logger.Log("Starting work with " + std::to_string(count) + '/' + std::to_string(capacity));
            break;
        case CheckForErrors:
            if (message->getCallback() != nullptr) {
                std::pair<ComponentMessageType, std::string> result = checkCount();
                std::function<void(std::shared_ptr<ComponentMessage>)> callback = message->getCallback();
                callback(std::make_shared<ComponentMessage>(result.first, result.second));
            }
            break;
        case Stopping:
            logger.Log("Stopping work with " + std::to_string(count) + '/' + std::to_string(capacity));
            break;
    }
}
