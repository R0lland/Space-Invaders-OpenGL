#pragma once
#include <string>

class Debug
{
public:
    static void Log(std::string& message);
    static void Log(std::string message);
};
