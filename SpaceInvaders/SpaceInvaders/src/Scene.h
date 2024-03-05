#pragma once
#include <memory>
#include <vector>

#include "Actor.h"

class Scene
{
    std::vector<std::shared_ptr<Actor>> m_actors;
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
    
    void Update(float dt)
    {
        for (std::shared_ptr<Actor>& actor : m_actors)
        {
            actor->Update(dt);
        }
    }
};
