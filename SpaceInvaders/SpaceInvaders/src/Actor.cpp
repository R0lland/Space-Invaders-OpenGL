#include "Actor.h"

Actor::Actor() 
    : Destroyed(false)
{
    m_transform = AddComponent<Transform>();
    m_spriteRenderer = AddComponent<SpriteRenderer>(*m_transform);
    Initialize();
}

Actor::Actor(glm::vec2 pos, glm::vec2 size) 
    : Destroyed(false)
{
    m_transform = AddComponent<Transform>();
    m_transform->SetPosition(pos.x, pos.y);
    m_transform->SetSize(size.x, size.y);
    m_transform->SetRotation(0.0f);
    
    m_spriteRenderer = AddComponent<SpriteRenderer>(*m_transform);
    Initialize();
}

void Actor::Update(const float deltaTime)
{
    for (std::unique_ptr<ActorComponent>& component : m_actor_components)
    {
        component->Update(deltaTime);
    }
}

void Actor::Initialize()
{
    
}
