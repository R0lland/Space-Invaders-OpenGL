#include "Bullet.h"

#include "ResourceManager.h"

Bullet::Bullet(glm::vec2 pos, glm::vec2 size)
  : Actor(pos, size)
{
    //auto spriteRenderer = AddComponent<SpriteRenderer>();
    GetSpriteRenderer().SetTexture(ResourceManager::GetTexture("face"));
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
    Move(deltaTime);
}

void Bullet::Move(float dt)
{
    GetTransform().Position.y -= SPEED * m_direction * dt;
}
