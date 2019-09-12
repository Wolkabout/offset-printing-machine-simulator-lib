//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_TEMPOCOMPONENT_H
#define MBS_SIMULATOR_TEMPOCOMPONENT_H

#include "../Component.h"
#include "../Machine.h"

class TempoComponent : public Component {
protected:
    TempoComponent(std::string name, std::shared_ptr<ComponentMessageReceiver> machine) : Component(name, std::move(machine)) {}

public:
    virtual bool modifyCount(int) = 0;

    virtual bool iterate() = 0;
};

#endif //MBS_SIMULATOR_TEMPOCOMPONENT_H
