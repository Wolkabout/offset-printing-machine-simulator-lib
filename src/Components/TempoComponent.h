//
// Created by nvuletic on 9.9.19..
//

#ifndef MBS_SIMULATOR_TEMPOCOMPONENT_H
#define MBS_SIMULATOR_TEMPOCOMPONENT_H

#include "Component.h"
#include "Interfaces/ComponentMessageReceiver.h"

namespace simulator
{
    class TempoComponent : public Component
    {
    public:
        virtual int getCount() const = 0;

        virtual bool modifyCount(int) = 0;

        virtual bool setCount(int) = 0;

        virtual bool iterate() = 0;

    protected:
        TempoComponent(std::string name, ComponentMessageReceiver& machine) : Component(name, machine) {}

        virtual void EmitCount() = 0;
    };
}

#endif //MBS_SIMULATOR_TEMPOCOMPONENT_H
