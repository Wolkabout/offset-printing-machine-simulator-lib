//
// Created by nvuletic on 9.9.19..
//

#include "ConveyorRateMessage.h"

ConveyorRateMessage::ConveyorRateMessage(int currentRate) : m_currentRate(currentRate) {}

int ConveyorRateMessage::getCurrentRate() const {
    return m_currentRate;
}
