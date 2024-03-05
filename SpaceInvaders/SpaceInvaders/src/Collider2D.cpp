#include "Collider2D.h"

Collider2D::Collider2D(Transform& transform) : canHitTarget(false), m_transform(transform)
{
}

void Collider2D::SetCollisionTarget(Tag tag)
{
    m_collisionTarget = tag;
}
