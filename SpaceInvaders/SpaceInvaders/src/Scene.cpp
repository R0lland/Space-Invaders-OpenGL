#include "Scene.h"

void Scene::Update(float dt)
{
    for (std::shared_ptr<Actor>& actor : m_actors)
    {
        actor->Update(dt);
    }
}

void Scene::AddCollider(Collider2D* collider_2d)
{
    m_colliders2D.push_back(collider_2d);
}

bool Scene::CheckCollision(Collider2D& one, Collider2D& two)
{
    // collision x-axis?
    bool collisionX = one.GetTransform().Position.x + one.GetTransform().Size.x >= two.GetTransform().Position.x &&
        two.GetTransform().Position.x + two.GetTransform().Size.x >= one.GetTransform().Position.x;
    // collision y-axis?
    bool collisionY = one.GetTransform().Position.y + one.GetTransform().Size.y >= two.GetTransform().Position.y &&
        two.GetTransform().Position.y + two.GetTransform().Size.y >= one.GetTransform().Position.y;
    // collision only if on both axes
    return collisionX && collisionY;
}

void Scene::UpdateCollisions()
{
    for (Collider2D*& collider : m_colliders2D)
    {
        if (collider->GetColliderTag() == Tag::NONE && collider->GetCanHitTarget())
        {
            
        }
    }
}
