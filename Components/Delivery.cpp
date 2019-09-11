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

std::shared_ptr<ComponentMessage> Delivery::checkCount() {
    ComponentMessage *message = nullptr;
    ComponentMessage defaultMessage(Neutral, "");
    message = &defaultMessage;
    if (count == capacity) {
        ComponentMessage newMessage(Severe, wfull);
        message = &newMessage;
        warning90 = true;
        warning80 = true;
    }

    if ((capacity / 10) * 9 <= count && !warning90) {
        ComponentMessage newMessage(Alarming, w90);
        message = &newMessage;
        warning90 = true;
        warning80 = true;
    } else if ((capacity / 5) * 4 <= count && !warning80) {
        ComponentMessage newMessage(Alarming, w80);
        message = &newMessage;
        warning80 = true;
    }
    messages.push_back(*message);
    return std::shared_ptr<ComponentMessage>(&(messages[messages.size() - 1]));
}

bool Delivery::checkCountAndEmit() {
    std::shared_ptr<ComponentMessage> message = checkCount();
    if (message != nullptr && message->getType() != Neutral) {
        Emit(message);
        return message->getType() != Severe;
    }
    return true;
}

Delivery::Delivery(char *name, Machine *machine, int capacity, int initialCount) : TempoComponent(name, machine) {
    if (capacity < 0) {
        throw std::invalid_argument("Capacity can't be a negative number!");
    }
    if (initialCount < 0 || initialCount > capacity) {
        throw std::invalid_argument("Your initial amount of paper must fit in the capacity!");
    }

    w80 = const_cast<char *>(("The " + std::string(name) + " is 80% full.").c_str());
    w90 = const_cast<char *>(("The " + std::string(name) + " is 90% full.").c_str());
    wfull = const_cast<char *>(("The " + std::string(name) + " is full.").c_str());

    this->capacity = capacity;
    this->count = initialCount;
    checkCountAndEmit();
}

bool Delivery::modifyCount(int i) {
    if (count < i) {
        ComponentMessage message(Alarming, "You can\'t take more paper than there is here.");
        Emit(std::shared_ptr<ComponentMessage>(&message));
        return false;
    }

    count -= i;
    checkCountAndEmit();
    return true;
}

bool Delivery::iterate() {
    if (!((Machine *) machine)->isRunning()) {
        ComponentMessage message(Severe, "You can\'t take paper, the machine isn\'t runing.");
        Emit(std::shared_ptr<ComponentMessage>(&message));
        return false;
    }
    if (checkCountAndEmit()) {
        count++;
        checkCountAndEmit();
        return true;
    }
    return false;
}

void Delivery::ReceiveMachineStateMessage(MachineStateMessage *stateMessage) {
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

const std::vector<CountMessageReceiver *> &Delivery::getCountMessageReceiver() const {
    return countMessageReceiver;
}
