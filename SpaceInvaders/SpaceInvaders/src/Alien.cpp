#include "Alien.h"
#include "Display.h"

Alien::Alien() : Actor() {}

Alien::Alien(glm::vec2 pos, glm::vec2 size, float rotation)
	: Actor(pos, size, rotation) {}

Alien::Alien(glm::vec2 pos, glm::vec2 size, Texture2D sprite,
	glm::vec3 color, glm::vec2 velocity)
	: Actor(pos, size, sprite, color, velocity) {}

void Alien::Move(int direction, float dt) {

	if (direction == 0)
	{
		return;
	}

	if (m_transform.Position.x <= Display::WIDTH - m_transform.Size.x && m_transform.Position.x >= 0.0f)
	{
		m_transform.SetPosition(m_transform.Position.x + (SPEED * direction * dt), m_transform.Position.y);
	}
}