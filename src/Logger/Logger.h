//
// Created by nvuletic on 11.9.19..
//

#ifndef MODBUS_SIMULATOR_CPP_LOGGER_H
#define MODBUS_SIMULATOR_CPP_LOGGER_H

#include <string>

namespace simulator
{
    class Logger
    {
    private:
        std::string m_name;
    public:
        Logger(const std::string name);

        void Log(const std::string& message);
    };
}

#endif //MODBUS_SIMULATOR_CPP_LOGGER_H
