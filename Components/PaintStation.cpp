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

std::shared_ptr<ComponentMessage> PaintStation::checkCount() {
    ComponentMessage *message = nullptr;
    ComponentMessage defaultMessage(Neutral, "");
    message = &defaultMessage;
    if (count == 0) {
        ComponentMessage newMessage(Severe, wempty);
        message = &newMessage;
        warning10 = true;
        warning20 = true;
    }

    if (capacity / 10 > count && !warning10) {
        ComponentMessage newMessage(Alarming, w10);
        message = &newMessage;
        warning10 = true;
        warning20 = true;
    } else if (capacity / 5 > count && !warning20) {
        ComponentMessage newMessage(Alarming, w20);
        message = &newMessage;
        warning20 = true;
    }
    messages.push_back(*message);
    return std::shared_ptr<ComponentMessage>(&(messages[messages.size() - 1]));
}

bool PaintStation::checkCountAndEmit() {
    std::shared_ptr<ComponentMessage> message = checkCount();
    if (message != nullptr && message->getType() != Neutral) {
        Emit(message);
        return message->getType() != Severe;
    }
    return true;
}

PaintStation::PaintStation(char *name, Machine *machine, int capacity, int initialCount) : TempoComponent(name,
                                                                                                          machine) {
    if (capacity < 0) {
        throw std::invalid_argument("Capacity can't be a negative number!");
    }
    if (initialCount < 0 || initialCount > capacity) {
        throw std::invalid_argument("Your initial amount of paper must fit in the capacity!");
    }

    w20 = const_cast<char *>(("The " + std::string(name) + " has less than 20% of its capacity left.").c_str());
    w10 = const_cast<char *>(("The " + std::string(name) + " has less than 10% of its capacity left.").c_str());
    wempty = const_cast<char *>(("The " + std::string(name) + " is empty.").c_str());

    this->capacity = capacity;
    this->count = initialCount;
    checkCountAndEmit();
}

bool PaintStation::modifyCount(int i) {
    if (capacity - count < i) {
        ComponentMessage message(Alarming, "You can\'t put more paint than there's room for.");
        Emit(std::shared_ptr<ComponentMessage>(&message));
        return false;
    }

    count += i;
    checkCountAndEmit();
    return true;
}

bool PaintStation::iterate() {
    if (!((Machine *) machine)->isRunning()) {
        ComponentMessage message(Severe, "You can\'t take paint, the machine isn\'t running.");
        Emit(std::shared_ptr<ComponentMessage>(&message));
        return false;
    }
    if (checkCountAndEmit()) {
        count--;
        checkCountAndEmit();
        return true;
    }
    return false;
}

void PaintStation::ReceiveMachineStateMessage(MachineStateMessage *stateMessage) {
    switch (stateMessage->getType()) {
        case Starting:
            logger.Log("Starting work with " + std::to_string(count) + '/' + std::to_string(capacity));
            break;
        case CheckForErrors:
            if (stateMessage->getCallback() != nullptr) {
                std::shared_ptr<ComponentMessage> message = checkCount();
                std::function<void(std::shared_ptr<ComponentMessage>)> callback = stateMessage->getCallback();
                callback(message);
            }
            break;
        case Stopping:
            logger.Log("Stopping work with " + std::to_string(count) + '/' + std::to_string(capacity));
            break;
    }
}

const std::vector<CountMessageReceiver *> &PaintStation::getCountMessageReceiver() const {
    return countMessageReceiver;
}
