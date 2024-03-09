#pragma once

#include "Actor.h"

class Alien : public Actor
{
private:
	const int SPEED = 100;

public:
	Alien();
	Alien(glm::vec2 pos, glm::vec2 size, float rotation);
	Alien(glm::vec2 pos, glm::vec2 size, Texture2D sprite,
		glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f));
	Alien(glm::vec2 pos, glm::vec2 size, std::vector<Texture2D> animations, 
		glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));

	void Move(int horizontalDirection, int verticalDirection, float dt);
};

