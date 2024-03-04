#include "Actor.h"

Actor::Actor() 
    : m_transform(std::make_shared<Transform>(glm::vec2(0.0f, 0.0f) , glm::vec2(1.0f, 1.0f), 0.0f)),
    Destroyed(false), m_spriteRenderer(std::make_shared<SpriteRenderer>(*m_transform) )
{
    Initialize();
}

Actor::Actor(glm::vec2 pos, glm::vec2 size, glm::vec2 velocity) 
    : m_transform(std::make_shared<Transform>(pos, size, 0.0f)), Destroyed(false),
    m_spriteRenderer(std::make_shared<SpriteRenderer>(*m_transform) )
{
    Initialize();
}

void Actor::Update(const float deltaTime)
{
    for (std::shared_ptr<ActorComponent>& component : m_actor_components)
    {
        component->Update(deltaTime);
    }
}

void Actor::Initialize()
{
    m_actor_components.push_back(m_transform);
    m_actor_components.push_back(m_spriteRenderer);
}
