#include <vector>

#include "raylib.h"

#include "Board.h"
#include "Obstacle.h"
#include "Player.h"

const float SPAWN_INTERVAL = 1.5f;  // one new obstacle every SPAWN_INTERVAL seconds

// Moves every obstacle to the left. Obstacles that leave the screen
// are removed and earn one point.
static void updateObstacles(std::vector<Obstacle>& obstacles, float dt, int& score)
{
    for (Obstacle& obstacle : obstacles) {
        obstacle.update(dt);
    }

    for (size_t i = 0; i < obstacles.size();) {
        if (obstacles[i].isOffScreen()) {
            obstacles.erase(obstacles.begin() + i);
            score++;
        } else {
            i++;
        }
    }
}

// Adds a new obstacle on the right edge every SPAWN_INTERVAL seconds.
static void spawnObstacles(std::vector<Obstacle>& obstacles, float& spawnTimer, float dt)
{
    spawnTimer += dt;
    if (spawnTimer >= SPAWN_INTERVAL) {
        spawnTimer -= SPAWN_INTERVAL;
        obstacles.push_back(Obstacle((float)SCREEN_WIDTH));
    }
}

// Removes the obstacles that touch the player and costs one life for each.
static void handleCollisions(const Player& player, std::vector<Obstacle>& obstacles, int& lives)
{
    for (size_t i = 0; i < obstacles.size();) {
        if (player.collidesWith(obstacles[i])) {
            obstacles.erase(obstacles.begin() + i);
            lives--;
        } else {
            i++;
        }
    }
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);

    Player player;

    std::vector<Obstacle> obstacles;
    float spawnTimer = 0.0f;

    int score = 0;
    int lives = MAX_LIVES;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        bool gameOver = lives <= 0;

        // --- Update ---
        if (!gameOver) {
            player.handleInput();
            player.update(dt);

            spawnObstacles(obstacles, spawnTimer, dt);
            updateObstacles(obstacles, dt, score);
            handleCollisions(player, obstacles, lives);
        } else if (IsKeyPressed(KEY_ENTER)) {
            // Restart: back to the initial state
            player.reset();
            obstacles.clear();
            spawnTimer = 0.0f;
            score = 0;
            lives = MAX_LIVES;
        }

        // --- Draw ---
        // Every object of the world, seen through the GameObject base class
        std::vector<const GameObject*> world;
        world.push_back(&player);
        for (const Obstacle& obstacle : obstacles) {
            world.push_back(&obstacle);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        displayState(world, score, lives);
        if (gameOver) {
            displayGameOver(score);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
