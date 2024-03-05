#pragma once
#include "glm/vec2.hpp"
#include "ActorComponent.h"

class Transform : public ActorComponent
{
public:
    glm::vec2 Position, Size;
    float Rotation;
    Transform();
    Transform(glm::vec2 position, glm::vec2 size, float rotation);

    void SetPosition(const float x, const float y);
    void SetSize(const float x, const float y);
    void SetRotation(float rot);
};
