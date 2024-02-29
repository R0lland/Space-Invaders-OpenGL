#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
    const float SPEED = 500.0f;

    int m_direction;
public:
    Bullet(glm::vec2 pos, glm::vec2 size, Texture2D sprite, int direction);
    void Move(float dt);
};