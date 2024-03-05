#include "BulletsManager.h"

#include "Engine.h"
#include "ResourceManager.h"

BulletsManager::BulletsManager()
{
}

void BulletsManager::Update(const float dt)
{
    
}

void BulletsManager::CreateBullet(glm::vec2 startingPos, int direction)
{
    std::shared_ptr<Bullet> bullet = Engine::Scene->Instantiate<Bullet>(startingPos, glm::vec2(10.0f,50.0f));
    bullet->SetDirection(direction);
    m_bullets.push_back(bullet);
}
