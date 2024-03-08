#pragma once
#include <vector>
#include <memory>

#include <GL/glew.h>
#include <glm\glm.hpp>

#include "Actor.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"

class Alien;

/// GameLevel holds all Tiles as part of a Breakout level and 
/// hosts functionality to Load/render levels from the harddisk.
class GameLevel
{

private:
    unsigned int _index = 0;

public:
    // level state
    std::vector<std::shared_ptr<Alien>> Aliens;
    // constructor
    GameLevel();
    // loads level from file
    void Load(unsigned int index, const char *file, unsigned int levelWidth, unsigned int levelHeight);
    void Play(float deltaTime);
    void PlayOnce();
    // render level
    void Draw(SpriteRenderer &renderer);
    // check if the level is completed (all non-solid tiles are destroyed)
    bool IsCompleted();
};