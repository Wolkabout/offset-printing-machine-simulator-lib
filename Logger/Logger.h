//
// Created by nvuletic on 11.9.19..
//

#ifndef MODBUS_SIMULATOR_CPP_LOGGER_H
#define MODBUS_SIMULATOR_CPP_LOGGER_H

#include <string>

class Logger {
private:
    std::string name;
public:
    Logger(std::string name);
    void Log(std::string message);
};


#endif //MODBUS_SIMULATOR_CPP_LOGGER_H
