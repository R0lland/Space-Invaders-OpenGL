#include <memory>
#include <string>
#include <vector>

// Forward declaration of the Manager class
class Manager;

class ServiceLocator {
private:
	static std::vector<std::unique_ptr<Manager>> _managers;

public:
	template<typename T>
	static void RegisterManager() {
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
};

