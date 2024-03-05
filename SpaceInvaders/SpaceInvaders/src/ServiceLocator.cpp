#include "ServiceLocator.h"

#include "AliensManager.h"
#include "BulletsManager.h"

ServiceLocator* ServiceLocator::instance = nullptr;
std::vector<std::unique_ptr<Manager>> ServiceLocator::_managers;

void ServiceLocator::InitAllManagers()
{
	if (_managers.size() > 0)
	{
		for (auto& manager : _managers) {
			manager->Init();
		}
	}
}

void ServiceLocator::CreateManagers()
{
	RegisterManager<AliensManager>();
	RegisterManager<BulletsManager>();

	InitAllManagers();
}
