#include <memory>
#include <string>
#include <vector>
#include <type_traits>

#include "Manager.h"
// Forward declaration of the Manager class

class ServiceLocator {
private:
	static ServiceLocator* instance;
	static std::vector<std::unique_ptr<Manager>> _managers;

public:
	static ServiceLocator* getInstance() {
		if (!instance) {
			instance = new ServiceLocator();
		}
		return instance;
	}


	template<typename T>
	static typename std::enable_if<std::is_base_of<Manager, T>::value>::type RegisterManager() {
		_managers.push_back(std::make_unique<T>());
	}

	template<typename T>
	static T* GetManager() {
		for (std::unique_ptr<Manager>& managerPtr : _managers) {
			T* castedManager = dynamic_cast<T*>(managerPtr.get());
			if (castedManager != nullptr) {
				return castedManager;
			}
		}
		return nullptr;
	}

	// Function to initialize all registered managers
	static void InitAllManagers();
	static void CreateManagers();


	~ServiceLocator() {
		// Clearing managers
		_managers.clear();
	}
};
