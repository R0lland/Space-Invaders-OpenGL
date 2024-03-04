#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "ActorComponent.h"
#include "shader.h"
#include "Texture2D.h"
#include "Transform.h"

class SpriteRenderer : public ActorComponent
{
    Shader m_shader; 
    Texture2D m_sprite;
    glm::vec3 m_color;
    Transform& m_transform;
    unsigned int quadVAO;
    // Renders a defined quad textured with given sprite
    void DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
    void initRenderData();
public:
    // Constructor (inits shaders/shapes)
    SpriteRenderer(Transform& transform);
    // Destructor
    ~SpriteRenderer();
    
    void Initialize() override;
    void SetTexture(Texture2D texture);
    void Update(const float deltaTime) override;
};