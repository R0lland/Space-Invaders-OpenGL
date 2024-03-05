#include "Game.h"

#include "Engine.h"
#include "ResourceManager.h"

Direction VectorDirection(glm::vec2 target)
{
    glm::vec2 compass[] = {
        glm::vec2(0.0f, 1.0f),	// up
        glm::vec2(1.0f, 0.0f),	// right
        glm::vec2(0.0f, -1.0f),	// down
        glm::vec2(-1.0f, 0.0f)	// left
    };
    float max = 0.0f;
    unsigned int best_match = -1;
    for (unsigned int i = 0; i < 4; i++)
    {
        float dot_product = glm::dot(glm::normalize(target), compass[i]);
        if (dot_product > max)
        {
            max = dot_product;
            best_match = i;
        }
    }
    return (Direction)best_match;
}

Game::Game(unsigned int width, unsigned int height) 
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{ 
    m_bulletsManager = std::make_shared<BulletsManager>();
}

Game::~Game()
{

}

void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader("res/shaders/VertexSprite.shader", "res/shaders/FragmentSprite.shader", nullptr, "sprite");
    ResourceManager::LoadShader("res/shaders/VertexParticle.shader", "res/shaders/FragmentParticle.shader", nullptr, "particle");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), 
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    ResourceManager::GetShader("particle").Use().SetMatrix4("projection", projection);

    // load textures
    ResourceManager::LoadTexture("res/textures/player.png", true, "player");
    ResourceManager::LoadTexture("res/textures/background.jpg", false, "background");
    ResourceManager::LoadTexture("res/textures/awesomeface.png", true, "face");
    ResourceManager::LoadTexture("res/textures/block.png", false, "block");
    ResourceManager::LoadTexture("res/textures/block_solid.png", false, "block_solid");
    ResourceManager::LoadTexture("res/textures/particle.png", true, "particle");

    //Aliens
    ResourceManager::LoadTexture("res/textures/enemies/green.png", true, "enemy1");
    ResourceManager::LoadTexture("res/textures/enemies/yellow.png", true, "enemy2");
    ResourceManager::LoadTexture("res/textures/enemies/red.png", true, "enemy3");
    // load levels
    GameLevel one; one.Load("res/levels/space_invaders.txt", this->Width, this->Height / 2);
    // GameLevel two; two.Load("res/levels/two.txt", this->Width, this->Height / 2);
    // GameLevel three; three.Load("res/levels/three.txt", this->Width, this->Height / 2);
    // GameLevel four; four.Load("res/levels/four.txt", this->Width, this->Height / 2);
    this->Levels.push_back(one);
    // this->Levels.push_back(two);
    // this->Levels.push_back(three);
    // this->Levels.push_back(four);
    this->Level = 0;


    glm::vec2 playerPos = glm::vec2(
        this->Width / 2.0f - PLAYER_SIZE.x / 2.0f, 
        this->Height - PLAYER_SIZE.y
    );

    player = Engine::Scene->Instantiate<Player>(playerPos, PLAYER_SIZE);
    player->SetData(ResourceManager::GetTexture("player"), m_bulletsManager);
}

void Game::ChangeInputFlag(unsigned int input, bool isActive)
{
    
}

void Game::Update(float dt)
{
    //DoCollisions();
}

void Game::ResetLevel()
{
    if (this->Level == 0)
        this->Levels[0].Load("res/levels/space_invaders.txt", this->Width, this->Height / 2);
}

void Game::ResetPlayer()
{
    // reset player/ball stats
    player->GetTransform().Size = PLAYER_SIZE;
    player->GetTransform().Position = glm::vec2(this->Width / 2.0f - PLAYER_SIZE.x / 2.0f, this->Height - PLAYER_SIZE.y);
}

bool CheckCollision(Actor &one, Actor &two) // AABB - AABB collision
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

// Collision CheckCollision(BallObject &one, GameObject &two) // AABB - Circle collision
// {
//     // get center point circle first 
//     glm::vec2 center(one.GetTransform().Position + one.Radius);
//     // calculate AABB info (center, half-extents)
//     glm::vec2 aabb_half_extents(two.GetTransform().Size.x / 2.0f, two.GetTransform().Size.y / 2.0f);
//     glm::vec2 aabb_center(two.GetTransform().Position.x + aabb_half_extents.x, two.GetTransform().Position.y + aabb_half_extents.y);
//     // get difference vector between both centers
//     glm::vec2 difference = center - aabb_center;
//     glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
//     // now that we know the clamped values, add this to AABB_center and we get the value of box closest to circle
//     glm::vec2 closest = aabb_center + clamped;
//     // now retrieve vector between center circle and closest point AABB and check if length < radius
//     difference = closest - center;
//
//     if (glm::length(difference) < one.Radius) // not <= since in that case a collision also occurs when object one exactly touches object two, which they are at the end of each collision resolution stage.
//         return std::make_tuple(true, VectorDirection(difference), difference);
//     else
//         return std::make_tuple(false, UP, glm::vec2(0.0f, 0.0f));
// }

// void Game::DoCollisions()
// {
//     for (GameObject &alien : this->Levels[this->Level].Aliens)
//     {
//         if (!alien.Destroyed)
//         {
//             Collision collision = CheckCollision(*Ball, alien);
//             if (std::get<0>(collision)) // if collision is true
//             {
//                 // destroy block if not solid
//                 if (!alien.IsSolid)
//                     alien.Destroyed = true;
//                 // collision resolution
//                 Direction dir = std::get<1>(collision);
//                 glm::vec2 diff_vector = std::get<2>(collision);
//                 if (dir == LEFT || dir == RIGHT) // horizontal collision
//                 {
//                     Ball->Velocity.x = -Ball->Velocity.x; // reverse horizontal velocity
//                     // relocate
//                     float penetration = Ball->Radius - std::abs(diff_vector.x);
//                     if (dir == LEFT)
//                         Ball->Position.x += penetration; // move ball to right
//                     else
//                         Ball->Position.x -= penetration; // move ball to left;
//                 }
//                 else // vertical collision
//                 {
//                     Ball->Velocity.y = -Ball->Velocity.y; // reverse vertical velocity
//                     // relocate
//                     float penetration = Ball->Radius - std::abs(diff_vector.y);
//                     if (dir == UP)
//                         Ball->Position.y -= penetration; // move ball bback up
//                     else
//                         Ball->Position.y += penetration; // move ball back down
//                 }               
//             }
//         }    
//     }
//     // check collisions for player pad (unless stuck)
//     Collision result = CheckCollision(*Ball, *Player);
//     if (!Ball->Stuck && std::get<0>(result))
//     {
//         // check where it hit the board, and change velocity based on where it hit the board
//         float centerBoard = Player->Position.x + Player->Size.x / 2.0f;
//         float distance = (Ball->Position.x + Ball->Radius) - centerBoard;
//         float percentage = distance / (Player->Size.x / 2.0f);
//         // then move accordingly
//         float strength = 2.0f;
//         glm::vec2 oldVelocity = Ball->Velocity;
//         Ball->Velocity.x = INITIAL_BALL_VELOCITY.x * percentage * strength; 
//         //Ball->Velocity.y = -Ball->Velocity.y;
//         Ball->Velocity = glm::normalize(Ball->Velocity) * glm::length(oldVelocity); // keep speed consistent over both axes (multiply by length of old velocity, so total strength is not changed)
//         // fix sticky paddle
//         Ball->Velocity.y = -1.0f * abs(Ball->Velocity.y);
//     }
// }