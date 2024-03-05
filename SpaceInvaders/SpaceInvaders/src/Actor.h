#pragma once

#include <GL/glew.h>
#include <memory>
#include <vector>
#include <glm\glm.hpp>

#include "SpriteRenderer.h"
#include "Transform.h"

// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.
class Actor
{
private:
    std::shared_ptr<Transform> m_transform;
    std::shared_ptr<SpriteRenderer> m_spriteRenderer;
    std::vector<std::shared_ptr<ActorComponent>> m_actor_components;
    
public:

    template<typename TComponent>
    std::enable_if_t<std::is_base_of_v<ActorComponent, TComponent>, TComponent> AddComponent()
    {
        return TComponent {};
    }

    template<typename TComponent>
    std::enable_if_t<std::is_base_of_v<ActorComponent, TComponent>, TComponent> AddComponent(Transform& transform)
    {
        return TComponent {transform};
    }
    
    bool Destroyed;

    // constructor(s)
    Actor();
    Actor(glm::vec2 pos, glm::vec2 size);
    
    // draw sprite
    virtual void Initialize();
    virtual void Update(const float deltaTime);

    Transform& GetTransform() { return *m_transform; }
    SpriteRenderer& GetSpriteRenderer() { return *m_spriteRenderer; }
};