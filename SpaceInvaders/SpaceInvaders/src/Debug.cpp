#include "Debug.h"

#include <iostream>

void Debug::Log(std::string& message)
{
    std::cout << message << std::endl;
}

void Debug::Log(std::string message)
{
    std::cout << message << std::endl;
}
