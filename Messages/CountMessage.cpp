//
// Created by nvuletic on 8.8.19..
//

#include "CountMessage.h"

CountMessage::CountMessage(int count, double percentage) : count(count), percentage(percentage) {}

int CountMessage::getCount() const {
    return count;
}

double CountMessage::getPercentage() const {
    return percentage;
}
