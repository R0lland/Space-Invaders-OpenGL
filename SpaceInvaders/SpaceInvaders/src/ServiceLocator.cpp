#include "ServiceLocator.h"
#include <BulletsManager.h>
#include <AliensManager.cpp>
#include <ResourceManager.h>

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
