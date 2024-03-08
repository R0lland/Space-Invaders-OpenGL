#pragma once
#include <vector>
#include <memory>
#include <Alien.h>
#include <Manager.h>

enum class Border;

enum class CurrentDirection {
	None,
	GoingRight = 1,
	GoingLeft = -1,
	GoingDown = 0
};

class AliensManager : public Manager
{
private:
	std::vector<std::shared_ptr<Alien>> m_Aliens {};
	CurrentDirection _currentDirection = CurrentDirection::None;
	
	const float _maxVerticalMovementAmount = 1.f;
	float _currentMovementAmount = 0.f;
public:
	std::vector<std::shared_ptr<Alien>>& CreateAliens(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);

	void AliensMovement(float deltaTime);
	void StopAliensMovement();
	inline std::vector<std::shared_ptr<Alien>>& GetAliens() { return m_Aliens; };
	inline void ClearAliens() { m_Aliens.clear(); }
	void MoveAliens(int direction, float deltaTime);
	bool CheckAliensAtBorder(int direction);

	// Inherited via Manager
	void Init() override;
};

