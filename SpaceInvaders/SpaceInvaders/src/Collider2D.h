#pragma once
#include <vector>

#include "Transform.h"

enum class Tag
{
    NONE = 0,
    PLAYER = 1,
    ALIEN = 2
};

class Collider2D
{
    Tag m_tag;
    Tag m_collisionTarget;
    bool canHitTarget;
    Transform& m_transform;
public:
    Collider2D(Transform& m_transform);
    void SetCollisionTarget(Tag tag);

    Tag GetColliderTag() const
    {
        return m_tag;
    }

    Tag GetColliderTarget() const
    {
        return m_collisionTarget;
    }

    bool GetCanHitTarget() const
    {
        return canHitTarget;
    }

    Transform& GetTransform() const
    {
        return m_transform;
    }
};
