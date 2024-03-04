#include "BulletsManager.h"

#include "ResourceManager.h"

BulletsManager::BulletsManager()
{
}

void BulletsManager::Update(const float dt)
{
    for (Bullet& bullet : m_bullets)
    {
        bullet.Update(dt);
    }
}

void BulletsManager::CreateBullet(glm::vec2 startingPos, int direction)
{
    m_bullets.emplace_back(startingPos, glm::vec2(10.0f,50.0f), direction);
}
