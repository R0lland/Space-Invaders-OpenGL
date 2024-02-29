#pragma once

class InputProcessor
{
    bool m_keys[1024];
public:
    int MoveDirection() const;
    bool Fire() const;
    void SetInputFlag(unsigned int input, bool isActive);
};
