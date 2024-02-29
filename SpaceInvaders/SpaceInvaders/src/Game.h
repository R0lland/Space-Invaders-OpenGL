#pragma once

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "BallObject.h"
#include "GameLevel.h"
#include "ParticleGenerator.h"
#include "Player.h"
#include "SpriteRenderer.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Represents the four possible (collision) directions
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
// Defines a Collision typedef that represents collision data
typedef std::tuple<bool, Direction, glm::vec2> Collision; // <collision?, what direction?, difference vector center - closest point>

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
    std::shared_ptr<BulletsManager> m_bulletsManager;
public:
    // game state
    GameState               State;	
    bool                    Keys[1024];
    unsigned int            Width, Height;
    SpriteRenderer  *Renderer;
    ///ParticleGenerator   *Particles;

    std::vector<GameLevel> Levels;
    unsigned int           Level;

    // Initial size of the player paddle
    const glm::vec2 PLAYER_SIZE{100.0f, 20.0f};
    // Initial velocity of the player paddle
    const float PLAYER_VELOCITY{500.0f};
    Player *Player;

    // Initial velocity of the Ball
    const glm::vec2 INITIAL_BALL_VELOCITY{100.0f, -350.0f};
    // Radius of the ball object
    const float BALL_RADIUS = 12.5f;
    //BallObject *Ball;
    
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ChangeInputFlag(unsigned int input, bool isActive);
    void Update(float dt);
    void Render();
    //void DoCollisions();
    // reset
    void ResetLevel();
    void ResetPlayer();
};