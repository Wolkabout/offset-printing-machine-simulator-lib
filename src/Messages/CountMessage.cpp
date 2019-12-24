//
// Created by nvuletic on 8.8.19..
//

#include "CountMessage.h"

namespace simulator
{
    CountMessage::CountMessage(int count, double percentage) : m_count(count), m_percentage(percentage) {}

    int CountMessage::getCount() const
    {
        return m_count;
    }

    double CountMessage::getPercentage() const
    {
        return m_percentage;
    }
}
