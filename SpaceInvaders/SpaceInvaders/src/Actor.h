#pragma once

#include <GL/glew.h>
#include <memory>
#include <glm\glm.hpp>

#include "Texture2D.h"
#include "SpriteRenderer.h"
#include "Transform.h"

// struct asset_ptr
// {
//     void* asset{nullptr};
//
//     bool operator ==(nullptr_t)
//     {
//         return asset == nullptr;
//     }
//
// };
//
// void F()
// {
//     asset_ptr assetPtr{};
//
//     if(assetPtr == nullptr)
//     {
//         
//     }
// }

// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.
class Actor
{
private:
    Transform m_transform;
    //SpriteRenderer m_spriteRenderer;
    
public:
    // object state
    glm::vec2   Velocity;
    glm::vec3   Color;
    bool        IsSolid;
    bool        Destroyed;
    // render state
    Texture2D   Sprite;	
    // constructor(s)
    Actor();
    Actor(glm::vec2 pos, glm::vec2 size, float rotation);
    Actor(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
    // draw sprite
    virtual void Draw(SpriteRenderer &renderer);

    Transform& GetTransform() { return m_transform; }
};