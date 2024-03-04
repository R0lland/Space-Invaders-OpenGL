#include "Bullet.h"

#include "ResourceManager.h"

Bullet::Bullet(glm::vec2 pos, glm::vec2 size, int direction)
  : Actor(pos, size), m_direction(direction)
{
    //auto spriteRenderer = AddComponent<SpriteRenderer>();
    GetSpriteRenderer().SetTexture(ResourceManager::GetTexture("face"));
}

void Bullet::Initialize()
{
    Actor::Initialize();
}

void Bullet::Update(const float deltaTime)
{
    Actor::Update(deltaTime);
    Move(deltaTime);
}

void Bullet::Move(float dt)
{
    GetTransform().Position.y -= SPEED * m_direction * dt;
}
