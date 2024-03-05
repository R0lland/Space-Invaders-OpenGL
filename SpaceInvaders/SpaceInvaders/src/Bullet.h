#pragma once
#include "Actor.h"
#include "Movement2d.h"

class Bullet : public Actor
{
    const float SPEED = 500.0f;

    int m_direction;
    Movement2d* m_movement_2d;
public:
    Bullet(glm::vec2 pos, glm::vec2 size);

    void SetDirection(int direction);
    void Initialize() override;
    void Update(const float deltaTime) override;
};
