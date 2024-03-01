#include "GameLevel.h"
#include "AliensManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <ServiceLocator.h>

void GameLevel::Load(const char *file, unsigned int levelWidth, unsigned int levelHeight)
{
    AliensManager& aliensManager = *ServiceLocator::GetManager<AliensManager>();
    // clear old data
    aliensManager.ClearAliens();
    // load from file
    unsigned int tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    if (fstream.fail())
    {
        std::cout << "ERROR LOADING FILEPATH: " << file;
    }
    std::vector<std::vector<unsigned int>> tileData;
    if (fstream)
    {
        while (std::getline(fstream, line)) // read each line from level file
        {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;
            while (sstream >> tileCode) // read each word separated by spaces
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
            aliensManager.CreateAliens(tileData, levelWidth, levelHeight);
    }
}

void GameLevel::Draw(SpriteRenderer &renderer)
{
    AliensManager& aliensManager = *ServiceLocator::GetManager<AliensManager>();
    std::vector<std::shared_ptr<Alien>>& aliens = aliensManager.GetAliens();
    for (size_t i = 0; i < aliens.size(); i++)
    {
        if (!aliens[i]->Destroyed)
        {
           aliens[i]->Draw(renderer);
        }
    }
}

bool GameLevel::IsCompleted()
{
	AliensManager& aliensManager = *ServiceLocator::GetManager<AliensManager>();
	std::vector<std::shared_ptr<Alien>>& aliens = aliensManager.GetAliens();
	
    for (size_t i = 0; i < aliens.size(); i++)
	{
		if (!aliens[i]->IsSolid && !aliens[i]->Destroyed)
			return false;
	}
    return true;
}
