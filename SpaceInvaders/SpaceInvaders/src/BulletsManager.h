#pragma once
#include <vector>

#include "Bullet.h"
#include "Manager.h"

class BulletsManager : public Manager
{
    std::vector<Bullet> m_bullets = {};
public:
    void Init() override;
    BulletsManager();
    void Update(const float dt);
    void CreateBullet(glm::vec2 startingPos, int direction);
    void DrawBullets(SpriteRenderer &renderer) const;
};
