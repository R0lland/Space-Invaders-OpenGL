#include "Bullet.h"

#include "ResourceManager.h"

Bullet::Bullet(glm::vec2 pos, glm::vec2 size)
  : Actor(pos, size)
{
    GetSpriteRenderer().SetTexture(ResourceManager::GetTexture("face"));
    m_movement_2d = AddComponent<Movement2d>(GetTransform());
}

void Bullet::SetDirection(int direction)
{
    m_direction = direction;
}

void Bullet::Initialize()
{
    Actor::Initialize();
}

void Bullet::Update(const float deltaTime)
{
    Actor::Update(deltaTime);
    m_movement_2d->Move(0.0f, m_direction, deltaTime, SPEED);
}
