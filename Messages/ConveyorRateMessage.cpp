//
// Created by nvuletic on 9.9.19..
//

#include "ConveyorRateMessage.h"

ConveyorRateMessage::ConveyorRateMessage(int currentRate) : currentRate(currentRate) {}

int ConveyorRateMessage::getCurrentRate() const {
    return currentRate;
}
