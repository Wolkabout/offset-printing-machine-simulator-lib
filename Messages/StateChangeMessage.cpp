//
// Created by nvuletic on 8.8.19..
//

#include "StateChangeMessage.h"

StateChangeMessage::StateChangeMessage(bool stateChange) : stateChange(stateChange) {}

bool StateChangeMessage::getState() const {
    return stateChange;
}
