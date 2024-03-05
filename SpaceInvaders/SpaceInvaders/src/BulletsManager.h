#pragma once
#include <vector>

#include "Bullet.h"

class BulletsManager
{
    std::vector<std::shared_ptr<Bullet>> m_bullets = {};
public:
    BulletsManager();
    void Update(const float dt);
    void CreateBullet(glm::vec2 startingPos, int direction);
};
