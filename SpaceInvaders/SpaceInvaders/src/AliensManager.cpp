#include "AliensManager.h"
#include <ResourceManager.h>
#include "Display.h"

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


void AliensManager::AliensMovement(float deltaTime) {
    bool atRightBorder = CheckAliensAtBorder(1);
    bool atLeftBorder = CheckAliensAtBorder(-1);

    switch (_currentDirection) {
    case CurrentDirection::GoingRight:
        if (atRightBorder) {
            _currentDirection = CurrentDirection::GoingDown;
        }
        break;

    case CurrentDirection::GoingDown:
        _currentMovementAmount += 1 * deltaTime;
        if (_currentMovementAmount >= _maxVerticalMovementAmount) {
            _currentDirection = atLeftBorder ? CurrentDirection::GoingRight : CurrentDirection::GoingLeft;
            _currentMovementAmount = 0;
        }
        break;

    case CurrentDirection::GoingLeft:
        if (atLeftBorder) {
            _currentDirection = CurrentDirection::GoingDown;
        }
        break;
    }

    MoveAliens(static_cast<int>(_currentDirection), deltaTime);
}






//void AliensManager::AliensMovement(float deltaTime) {
//  
//    if (CheckAliensAtBorder(1) && _currentDirection == CurrentDirection::GoingRight)
//    {
//        _currentDirection = CurrentDirection::GoingDown;
//    }
//    if (CheckAliensAtBorder(1) && _currentDirection == CurrentDirection::GoingDown 
//        && _currentMovementAmount < _maxVerticalMovementAmount)
//    {
//        _currentMovementAmount += 1 * deltaTime;
//    }
//    if (CheckAliensAtBorder(1) && _currentDirection == CurrentDirection::GoingDown 
//        && _currentMovementAmount >= _maxVerticalMovementAmount)
//    {
//        _currentDirection = CurrentDirection::GoingLeft;
//        _currentMovementAmount = 0;
//    }
//    if (CheckAliensAtBorder(1) && _currentDirection == CurrentDirection::GoingLeft)
//    {
//  
//    }
//    if (CheckAliensAtBorder(-1) && _currentDirection == CurrentDirection::GoingLeft)
//    {
//        _currentDirection = CurrentDirection::GoingDown;
//    }
//    if (CheckAliensAtBorder(-1) && _currentDirection == CurrentDirection::GoingDown 
//        && _currentMovementAmount < _maxVerticalMovementAmount)
//    {
//        _currentMovementAmount += 1 * deltaTime;
//    }
//    if (CheckAliensAtBorder(-1) && _currentDirection == CurrentDirection::GoingDown 
//        && _currentMovementAmount >= _maxVerticalMovementAmount)
//    {
//        _currentDirection = CurrentDirection::GoingRight;
//        _currentMovementAmount = 0;
//    }
//
//    MoveAliens(static_cast<int>(_currentDirection), deltaTime);
//}

bool AliensManager::CheckAliensAtBorder(int direction) {
    float greatestX = -FLT_MAX;
    float lowestX = FLT_MAX;
    float alienWidth = m_Aliens[0]->Sprite.Width;
    for (size_t i = 0; i < m_Aliens.size(); i++) {
        float alienX = m_Aliens[i]->GetTransform().Position.x;
        if (alienX > greatestX)
            greatestX = alienX;

        if (alienX < lowestX)
            lowestX = alienX;
    }
    
    switch (direction)
    {
        case -1:
            if (lowestX <= (alienWidth / 2))
            {
                return true;
            }
            break;
        case 1:
            if (greatestX >= (Display::WIDTH - (alienWidth + 20))) {
                return true;
            }
            break;
        default:
            break;
    }
 
    return false;
}

void AliensManager::MoveAliens(int horizontalDirection, float deltaTime) {
    int verticalDirection = horizontalDirection != 0 ? 0 : 1;

    for (size_t i = 0; i < m_Aliens.size(); i++) {   
        m_Aliens[i]->Move(horizontalDirection, verticalDirection, deltaTime);
    }

}

void AliensManager::StopAliensMovement()
{
}

void AliensManager::Init()
{
    //TODO: CREATE VECTOR OF MOVEMENTS FOR THE ALIENS
    _currentDirection = CurrentDirection::GoingRight;
}
