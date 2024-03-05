#include "Player.h"

#include <iostream>
#include <utility>
#include "ResourceManager.h"

Player::Player(glm::vec2 pos, glm::vec2 size) : Actor(pos, size)
{
}

void Player::Fire()
{
    if (fireRate >= TIME_TO_FIRE)
    {
        fireRate = 0.0f;
        std::cout << "FIRE" << std::endl;
        m_bulletsManager->CreateBullet(GetTransform().Position + glm::vec2(GetTransform().Size.x / 2.0f, (GetTransform().Size.y + 1.0f) / 2.0f), 1);
    }
}

void Player::Move(const int direction, const float dt)
{
    if (direction == 0)
    {
        return;
    }

    if (GetTransform().Position.x <= 1200 - GetTransform().Size.x && GetTransform().Position.x >= 0.0f)
    {
        Transform& transform = GetTransform();
        transform.SetPosition(transform.Position.x + (VELOCITY * direction * dt), transform.Position.y);
    }
}

void Player::Update(float dt)
{
    Actor::Update(dt);
    
    fireRate += dt;
    if (m_inputProcessor->Fire())
    {
        Fire();
    }

    Move(m_inputProcessor->MoveDirection(), dt);
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
