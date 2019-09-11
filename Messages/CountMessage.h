//
// Created by nvuletic on 8.8.19..
//

#ifndef MBS_SIMULATOR_CPP_COUNTMESSAGE_H
#define MBS_SIMULATOR_CPP_COUNTMESSAGE_H

/*
 * This is a class that carries the message from components
 * that can notify with their count/counter percentage
 */

class CountMessage {
private:
    int count;
    double percentage;
public:
    CountMessage(int count, double percentage);

    int getCount() const;

    double getPercentage() const;
};


#endif //MBS_SIMULATOR_CPP_COUNTMESSAGE_H
