//
// Created by nvuletic on 8.8.19..
//

#ifndef MBS_SIMULATOR_CPP_COUNTMESSAGE_H
#define MBS_SIMULATOR_CPP_COUNTMESSAGE_H

namespace simulator
{
    /*
     * This is a class that carries the message from m_components
     * that can notify with their m_count/counter m_percentage
     */


    class CountMessage
    {
    public:
        CountMessage(int count, double percentage);

        int getCount() const;

        double getPercentage() const;

    private:
        int m_count;
        double m_percentage;
    };
}

#endif //MBS_SIMULATOR_CPP_COUNTMESSAGE_H
