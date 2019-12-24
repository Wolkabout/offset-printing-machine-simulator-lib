//
// Created by nvuletic on 11.9.19..
//

#include "Logger.h"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <utility>

namespace simulator
{
    Logger::Logger(std::string name) : m_name(std::move(name)) {}

    void Logger::Log(const std::string& message)
    {
        auto time = std::time(nullptr);
        std::cout << '[' << m_name << ']' << '[' << std::put_time(std::localtime(&time), "%F %T%z") << ']' << " -> "
                  << message << std::endl;
    }
}
