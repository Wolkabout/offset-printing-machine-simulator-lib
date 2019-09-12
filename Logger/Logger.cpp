//
// Created by nvuletic on 11.9.19..
//

#include "Logger.h"
#include <utility>
#include <iostream>
#include <ctime>
#include <iomanip>

Logger::Logger(std::string name) : name(std::move(name)) {}

void Logger::Log(std::string message) {
    auto time = std::time(nullptr);
    std::cout << '[' << name << ']' << '[' << std::put_time(std::localtime(&time), "%F %T%z") << ']' << " -> " << message << std::endl;
}
