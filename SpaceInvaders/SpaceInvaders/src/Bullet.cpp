#include "Bullet.h"

Bullet::Bullet(glm::vec2 pos, glm::vec2 size, Texture2D sprite, int direction)
  : GameObject(pos, size, sprite), m_direction(direction)
{
}

void Bullet::Move(float dt)
{
    GetTransform().Position.y -= SPEED * m_direction * dt;
}
