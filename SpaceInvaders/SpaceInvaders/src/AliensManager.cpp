#include "AliensManager.h"
#include <ResourceManager.h>


void AliensManager::Init()
{
}


void AliensManager::CreateAliens(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight)
{
	// calculate dimensions
	unsigned int height = tileData.size();
	unsigned int width = tileData[0].size(); // note we can index vector at [0] since this function is only called if height > 0
	float unit_width = 50.0f;// / static_cast<float>(width);
	float unit_height = 50.0f;//levelHeight / height;
	float xOffset = 180.0f;
	float yOffset = 40.0f;
	glm::vec3 color = glm::vec3(1.0f); // original: white

	// initialize level tiles based on tileData		
	for (unsigned int y = 0; y < height; ++y)
	{
		for (unsigned int x = 0; x < width; ++x)
		{
			glm::vec2 pos(xOffset + ((unit_width + 10.0f) * x), yOffset + ((unit_height + 10.0f) * y));
			glm::vec2 size(unit_width, unit_height);
			std::string enemyId = "enemy" + std::to_string(tileData[y][x]);
			//Creating aliens
			this->m_Aliens.push_back(std::make_shared<Alien>(pos, size, ResourceManager::GetTexture(enemyId), color));
		}
	}
}

void AliensManager::StartAliensMovement(float dt)
{
	int control = 0;
	float movementRange = 3.f;

	while (control == 0)
	{
		
		for (size_t i = 0; i < m_Aliens.size(); i++)
		{
			m_Aliens[i]->Move()
		}
	}

}

void AliensManager::StopAliensMovement()
{
}
