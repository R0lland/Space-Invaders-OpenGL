#include "AliensManager.h"
#include <ResourceManager.h>
#include "Display.h"

//TODO: Move??
std::vector<std::shared_ptr<Alien>>& AliensManager::CreateAliens(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight)
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

    return m_Aliens;
}

void AliensManager::StartAliensMovement(float deltaTime) {
    int cycles = 1; // Adjust as needed
    float speed = 1.f;
    float movementRange = 800.f; // Adjust this value as needed
    int direction = 1; // Initial direction: move right
    int cyclesCount = 0;

    while (cyclesCount < cycles) {
        // Move right
        for (size_t i = 0; i < m_Aliens.size(); i++) {
             m_Aliens[i]->Move(direction, 0, deltaTime);
        }

        // Move down
        for (size_t i = 0; i < m_Aliens.size(); i++) {
             m_Aliens[i]->Move(0, 1, deltaTime);
        }

        // Move left
        for (size_t i = 0; i < m_Aliens.size(); i++) {
              m_Aliens[i]->Move(-direction, 0, deltaTime);
        }

        // Move down
        for (size_t i = 0; i < m_Aliens.size(); i++) {
             m_Aliens[i]->Move(0, 1, deltaTime); 
        }

        cyclesCount++;
    }
}

void AliensManager::StopAliensMovement()
{
}

void AliensManager::Init()
{
}
