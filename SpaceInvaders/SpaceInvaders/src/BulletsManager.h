#pragma once
#include <vector>

#include "Bullet.h"

class BulletsManager
{
    std::vector<Bullet> m_bullets = {};
public:
    BulletsManager();
    void Update(const float dt);
    void CreateBullet(glm::vec2 startingPos, int direction);
    void DrawBullets(SpriteRenderer &renderer) const;
};
