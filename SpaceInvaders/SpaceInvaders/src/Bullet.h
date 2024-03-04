#pragma once
#include "Actor.h"

class Bullet : public Actor
{
    const float SPEED = 500.0f;

    int m_direction;
    void Move(float dt);
public:
    Bullet(glm::vec2 pos, glm::vec2 size, int direction);
    
    void Initialize() override;
    void Update(const float deltaTime) override;
};