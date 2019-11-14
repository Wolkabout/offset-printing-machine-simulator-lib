//
// Created by nvuletic on 10.9.19..
//

#include <cmath>
#include "Feeder.h"

int Feeder::getCapacity() const {
    return capacity;
}

int Feeder::getCount() const {
    return count;
}

double Feeder::getPercentage() {
    return round((double) count / capacity);
}

std::vector<std::shared_ptr<CountMessageReceiver>> &Feeder::getCountMessageReceiver() {
    return countMessageReceiver;
}

Feeder::Feeder(std::string name, ComponentMessageReceiver& machine, int capacity, int initialCount) : TempoComponent(name, machine) {
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
    warning20 = false;
    warning10 = false;
}

std::pair<ComponentMessageType, std::string> Feeder::checkCount() {
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

bool Feeder::checkCountAndEmit() {
    std::pair<ComponentMessageType, std::string> result = checkCount();
    if (result.first != Neutral) {
        Emit(result.first, result.second);
        return result.first != Severe;
    }
    return true;
}

bool Feeder::modifyCount(int i) {
    if (capacity - count < i) {
        Emit(Alarming, "You can\'t put more paper than there's room for.");
        return false;
    }

    count += i;
    EmitCount();
    checkCountAndEmit();
    return true;
}

bool Feeder::setCount(int i) {
    count = i;
    return true;
}

bool Feeder::iterate() {
    if (!((Machine &) machine).isRunning()) {
        Emit(Severe, "You can\'t take paper, the machine isn\'t running.");
        return false;
    }
    if (checkCountAndEmit()) {
        count--;
        EmitCount();
        return true;
    }
    return false;
}

void Feeder::ReceiveMachineStateMessage(std::shared_ptr<MachineStateMessage> message) {
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

void Feeder::EmitCount() {
    std::shared_ptr<CountMessage> countMessage = std::make_shared<CountMessage>(count, (double)count / capacity);
    for (auto receiver : countMessageReceiver) {
        receiver->ReceiveMessage(countMessage);
    }
}
