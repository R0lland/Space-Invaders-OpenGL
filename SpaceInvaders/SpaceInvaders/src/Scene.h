#pragma once
#include <memory>
#include <vector>

#include "Actor.h"
#include "Collider2D.h"

class Scene
{
    std::vector<std::shared_ptr<Actor>> m_actors;
    std::vector<Collider2D*> m_colliders2D;
public:
    template<typename T>
    std::shared_ptr<T> Instantiate()
    {
        std::shared_ptr<T> instance_ptr = std::make_shared<T>();
        m_actors.push_back(instance_ptr);
        return instance_ptr;
    }
    
    template<typename T>
    std::shared_ptr<T> Instantiate(glm::vec2 pos, glm::vec2 size)
    {
        std::shared_ptr<T> instance_ptr = std::make_shared<T>(pos, size);
        m_actors.push_back(instance_ptr);
        return instance_ptr;
    }
    
    void Update(float dt);
    void AddCollider(Collider2D* collider_2d);
    bool CheckCollision(Collider2D &one, Collider2D &two); // AABB - AABB collision
    void UpdateCollisions();
};
