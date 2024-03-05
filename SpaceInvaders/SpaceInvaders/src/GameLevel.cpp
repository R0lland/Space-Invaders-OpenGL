#include "GameLevel.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Engine.h"


void GameLevel::Load(const char *file, unsigned int levelWidth, unsigned int levelHeight)
{
    // clear old data
    this->Aliens.clear();
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
            this->init(tileData, levelWidth, levelHeight);
    }
}

void GameLevel::Update(float deltaTime)
{
    
}

bool GameLevel::IsCompleted()
{
    for (std::shared_ptr<Actor> &tile : this->Aliens)
        if (!tile->Destroyed)
            return false;
    return true;
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight)
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
            std::shared_ptr<Actor> alien = Engine::Scene->Instantiate<Actor>(pos, size);
            alien->GetSpriteRenderer().SetTexture(ResourceManager::GetTexture(enemyId));
            this->Aliens.push_back(alien);
        }
    }
}