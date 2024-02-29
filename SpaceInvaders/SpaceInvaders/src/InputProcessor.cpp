#include "InputProcessor.h"

#include <iostream>
#include <GLFW/glfw3.h>

int InputProcessor::MoveDirection() const
{
    if (this->m_keys[GLFW_KEY_A] || this->m_keys[GLFW_KEY_LEFT])
    {
       return -1;
    }
    else if (this->m_keys[GLFW_KEY_D] || this->m_keys[GLFW_KEY_RIGHT])
    {
        return 1;
    }
    return 0;
}

bool InputProcessor::Fire() const
{
    if (this->m_keys[GLFW_KEY_SPACE])
    {
        return true;
    }
    return false;
}

void InputProcessor::SetInputFlag(unsigned int input, bool isActive)
{
    m_keys[input] = isActive;
}
