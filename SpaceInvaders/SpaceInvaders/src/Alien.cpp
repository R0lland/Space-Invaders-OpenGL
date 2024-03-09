#include "Alien.h"
#include "Display.h"

Alien::Alien() : Actor() {}

Alien::Alien(glm::vec2 pos, glm::vec2 size, float rotation)
	: Actor(pos, size, rotation) {}

Alien::Alien(glm::vec2 pos, glm::vec2 size, Texture2D sprite,
	glm::vec3 color, glm::vec2 velocity)
	: Actor(pos, size, sprite, color, velocity) {}

Alien::Alien(glm::vec2 pos, glm::vec2 size, std::vector<Texture2D> animations,
    glm::vec3 color, glm::vec2 velocity) : Actor(pos, size, animations, color, velocity)
{
}

void Alien::Move(int horizontalDirection, int verticalDirection, float dt) {
    /*if (horizontalDirection == 0 && verticalDirection == 0) {
        return;
    }*/

    float newX = m_transform.Position.x + (SPEED * horizontalDirection * dt);
    float newY = m_transform.Position.y + (SPEED * verticalDirection * dt);

    // Check horizontal bounds
    if (newX <= Display::WIDTH - m_transform.Size.x && newX >= 0.0f) {
        m_transform.SetPosition(newX, m_transform.Position.y);
    }

    // Check vertical bounds
    if (newY <= Display::HEIGHT - m_transform.Size.y && newY >= 0.0f) {
        m_transform.SetPosition(m_transform.Position.x, newY);
    }
}
