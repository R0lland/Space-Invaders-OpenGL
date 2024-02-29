#pragma once
#include "Actor.h"

class Bullet : public Actor
{
    const float SPEED = 500.0f;

    int m_direction;
public:
    Bullet(glm::vec2 pos, glm::vec2 size, Texture2D sprite, int direction);
    void Move(float dt);
};