//
// Created by nvuletic on 8.8.19..
//

#ifndef MBS_SIMULATOR_STATECHANGEMESSAGE_H
#define MBS_SIMULATOR_STATECHANGEMESSAGE_H

/*
 * Class that carries a message from machine to outside.
 * Used to notify if machine gets turned on/off.
 */

class StateChangeMessage {
private:
    bool m_stateChange;
public:
    StateChangeMessage(bool stateChange);

    bool getState() const;
};


#endif //MBS_SIMULATOR_STATECHANGEMESSAGE_H
