#include "Player.h"

#include <iostream>
#include <utility>

Player::Player(glm::vec2 pos, glm::vec2 size, Texture2D sprite, std::shared_ptr<BulletsManager> bulletsManager)
  : GameObject(pos, size, sprite)
{
    m_inputProcessor = std::make_unique<InputProcessor>();
    m_bulletsManager = std::move(bulletsManager);
}

void Player::Fire()
{
    if (fireRate >= TIME_TO_FIRE)
    {
        fireRate = 0.0f;
        std::cout << "FIRE" << std::endl;
        m_bulletsManager->CreateBullet(Position + glm::vec2(Size.x / 2.0f, (Size.y + 1.0f) / 2.0f), 1);
    }
}

void Player::Move(const int direction, const float dt)
{
    if (direction == 0)
    {
        return;
    }

    if (Position.x <= 1200 - Size.x && Position.x >= 0.0f)
    {
        Position.x += VELOCITY * direction * dt;
    }
}

void Player::Update(float dt)
{
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
