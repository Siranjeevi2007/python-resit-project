#include <vector>

#include "raylib.h"

#include "Board.h"
#include "Player.h"

// Obstacles, in pixels and seconds.
const float OBSTACLE_SPEED = 300.0f;  // pixels per second, towards the left
const float SPAWN_INTERVAL = 1.5f;    // one new obstacle every SPAWN_INTERVAL seconds

// Moves every obstacle to the left. Obstacles that leave the screen
// are removed and earn one point.
static void updateObstacles(std::vector<Position>& obstacles, float dt, int& score)
{
    for (Position& obstacle : obstacles) {
        obstacle.x -= OBSTACLE_SPEED * dt;
    }

    for (size_t i = 0; i < obstacles.size();) {
        if (obstacles[i].x + OBSTACLE_WIDTH < 0.0f) {
            obstacles.erase(obstacles.begin() + i);
            score++;
        } else {
            i++;
        }
    }
}

// Adds a new obstacle on the right edge every SPAWN_INTERVAL seconds.
static void spawnObstacles(std::vector<Position>& obstacles, float& spawnTimer, float dt)
{
    spawnTimer += dt;
    if (spawnTimer >= SPAWN_INTERVAL) {
        spawnTimer -= SPAWN_INTERVAL;
        obstacles.push_back({(float)SCREEN_WIDTH, OBSTACLE_GROUND_Y});
    }
}

// Removes the obstacles that touch the player and costs one life for each.
static void handleCollisions(const Position& player, std::vector<Position>& obstacles, int& lives)
{
    for (size_t i = 0; i < obstacles.size();) {
        if (checkCollision(player, obstacles[i])) {
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

    Position player = {PLAYER_X, PLAYER_GROUND_Y};
    float velocityY = 0.0f;

    std::vector<Position> obstacles;
    float spawnTimer = 0.0f;

    int score = 0;
    int lives = MAX_LIVES;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        bool gameOver = lives <= 0;

        // --- Update ---
        if (!gameOver) {
            handleInput(player, velocityY);
            updateJump(player, velocityY, dt);

            spawnObstacles(obstacles, spawnTimer, dt);
            updateObstacles(obstacles, dt, score);
            handleCollisions(player, obstacles, lives);
        }

        // --- Draw ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        displayState(player, obstacles, score, lives);
        if (gameOver) {
            displayGameOver(score);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
