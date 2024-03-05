#pragma once
#include "ActorComponent.h"

class Transform;

class Movement2d : public ActorComponent
{
    Transform& m_transform;
public:
    Movement2d(Transform& transform);
    void Initialize() override;
    void Update(const float deltaTime) override;
    void Move(int directionX, int directionY, float deltaTime, float velocity);
};
