#include "Player.h"
#include <utility>

#include "Debug.h"
#include "Movement2d.h"
#include "ResourceManager.h"

Player::Player(glm::vec2 pos, glm::vec2 size) : Actor(pos, size)
{
    m_movement_2d = AddComponent<Movement2d>(GetTransform());
}

void Player::Fire()
{
    if (m_fireRate >= TIME_TO_FIRE)
    {
        m_fireRate = 0.0f;
        Debug::Log("Fire");
        m_bulletsManager->CreateBullet(GetTransform().Position + glm::vec2(GetTransform().Size.x / 2.0f, (GetTransform().Size.y + 1.0f) / 2.0f), -1);
    }
}

void Player::Update(float dt)
{
    Actor::Update(dt);
    
    m_fireRate += dt;
    if (m_inputProcessor->Fire())
    {
        Fire();
    }
    
    m_movement_2d->Move(m_inputProcessor->MoveDirection(), 0.0f, dt, VELOCITY);
}

void Player::SetInputFlag(unsigned int input, bool isActive) const
{
    m_inputProcessor->SetInputFlag(input, isActive);
}

void Player::SetData(Texture2D texture, std::shared_ptr<BulletsManager> bulletsManager)
{
    GetSpriteRenderer().SetTexture(texture);
    m_inputProcessor = std::make_unique<InputProcessor>();
    m_bulletsManager = std::move(bulletsManager);
}

void Player::Initialize()
{
    Actor::Initialize();
    
}
