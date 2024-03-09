#include "Actor.h"

Actor::Actor() 
    : m_transform(glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 1.0f), 0.0f), Velocity(0.0f), Color(1.0f), Sprite(), IsSolid(false), Destroyed(false)
{ }

Actor::Actor(glm::vec2 pos, glm::vec2 size, float rotation)
    : m_transform(pos, size, rotation)
{
}

Actor::Actor(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity) 
    : m_transform(pos, size, 0.0f), Velocity(velocity), Color(color), Sprite(sprite), IsSolid(false), Destroyed(false) { }

Actor::Actor(glm::vec2 pos, glm::vec2 size, std::vector<Texture2D> animation, glm::vec3 color, glm::vec2 velocity)
    : m_transform(pos, size, 0.0f), Animation(animation), CurrentFrameIndex(0), AnimationSpeed(1.0f), AnimationTimer(0.0f), Color(color), Velocity(velocity), IsSolid(true), Destroyed(false) {}

//void Actor::Draw(SpriteRenderer &renderer)
//{
//    renderer.DrawSprite(this->Sprite, m_transform.Position, m_transform.Size, m_transform.Rotation, this->Color);
//}

void Actor::Update(float deltaTime)
{
    if (Animation.size() > 0)
    {
        AnimationTimer += deltaTime * AnimationSpeed;
        if (AnimationTimer >= 1.0f) {
            CurrentFrameIndex = (CurrentFrameIndex + 1) % Animation.size();
            AnimationTimer = 0.0f;
        }
    }
}

void Actor::Draw(SpriteRenderer& renderer) {
    if (Animation.size() > 0)
    {
        renderer.DrawSprite(Animation[CurrentFrameIndex], m_transform.Position, m_transform.Size, m_transform.Rotation, Color);
    }
    else {
        renderer.DrawSprite(Sprite, m_transform.Position, m_transform.Size, m_transform.Rotation, Color);
    }
}