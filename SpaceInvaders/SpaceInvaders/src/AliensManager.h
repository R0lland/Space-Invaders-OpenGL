#pragma once
#include <vector>
#include <memory>
#include <Alien.h>
#include <Manager.h>

class AliensManager : public Manager
{
private:
	std::vector<std::shared_ptr<Alien>> m_Aliens {};
public:
	std::vector<std::shared_ptr<Alien>>& CreateAliens(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
	void StartAliensMovement(float dt);
	void StopAliensMovement();
	inline std::vector<std::shared_ptr<Alien>>& GetAliens() { return m_Aliens; };
	inline void ClearAliens() { m_Aliens.clear(); }

	// Inherited via Manager
	void Init() override;
};

