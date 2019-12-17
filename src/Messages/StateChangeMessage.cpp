//
// Created by nvuletic on 8.8.19..
//

#include "StateChangeMessage.h"

StateChangeMessage::StateChangeMessage(bool stateChange) : m_stateChange(stateChange) {}

bool StateChangeMessage::getState() const {
    return m_stateChange;
}
