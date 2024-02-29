#include "Transform.h"

Transform::Transform()
{
    SetPosition(0.0f, 0.0f);
    SetSize(0.0f, 0.0f);
}

Transform::Transform(glm::vec2 position, glm::vec2 size, float rotation)
    : Position(position), Size(size), Rotation(rotation)
{
}

void Transform::SetPosition(const float x, const float y)
{
    Position.x = x;
    Position.y = y;
}

void Transform::SetSize(const float x, const float y)
{
    Size.x = x;
    Size.y = y;
}
