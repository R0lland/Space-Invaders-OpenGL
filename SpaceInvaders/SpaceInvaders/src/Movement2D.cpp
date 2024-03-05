#include "Movement2d.h"

#include "Transform.h"

Movement2d::Movement2d(Transform& transform) : m_transform(transform)
{
}

void Movement2d::Initialize()
{
    ActorComponent::Initialize();
}

void Movement2d::Update(const float deltaTime)
{
    ActorComponent::Update(deltaTime);
}

void Movement2d::Move(int directionX, int directionY, float deltaTime, float velocity)
{
    if (directionX == 0 && directionY == 0)
    {
        return;
    }

    if (m_transform.Position.x <= 1200 - m_transform.Size.x && m_transform.Position.x >= 0.0f)
    {
        m_transform.SetPosition(
            m_transform.Position.x + (velocity * directionX * deltaTime),
            m_transform.Position.y + (velocity * directionY * deltaTime));
    }
}
