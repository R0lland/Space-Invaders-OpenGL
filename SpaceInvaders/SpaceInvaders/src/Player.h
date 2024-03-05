#pragma once
#include <memory>

#include "BulletsManager.h"
#include "Actor.h"
#include "InputProcessor.h"

class Player : public Actor
{
    const float VELOCITY = 500.0f;
    const float TIME_TO_FIRE = 0.5f;
    
    std::unique_ptr<InputProcessor> m_inputProcessor;
    std::shared_ptr<BulletsManager> m_bulletsManager;
    float fireRate = TIME_TO_FIRE;
public:
    Player(glm::vec2 pos, glm::vec2 size);
    void Fire();
    void Move(int direction, float dt);
    
    void Update(const float dt) override;
    void SetInputFlag(unsigned int input, bool isActive) const;
    void SetData(Texture2D texture, std::shared_ptr<BulletsManager> bulletsManager);
};
