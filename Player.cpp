#include "Player.h"

#include "raylib.h"

static bool isOnGround(const Position& player)
{
    return player.y >= PLAYER_GROUND_Y;
}

void handleInput(const Position& player, float& velocityY)
{
    // IsKeyPressed is true only on the frame the key goes down.
    // IsKeyDown would be true every frame and make the player jump endlessly.
    if (IsKeyPressed(KEY_SPACE) && isOnGround(player)) {
        velocityY = -JUMP_SPEED;  // negative = upwards in Raylib
    }
}

void updateJump(Position& player, float& velocityY, float dt)
{
    if (isOnGround(player) && velocityY >= 0.0f) {
        return;  // standing on the ground, nothing to do
    }

    velocityY += GRAVITY * dt;
    player.y += velocityY * dt;

    // Landing
    if (player.y >= PLAYER_GROUND_Y) {
        player.y = PLAYER_GROUND_Y;
        velocityY = 0.0f;
    }
}

bool checkCollision(const Position& player, const Position& obstacle)
{
    return player.x < obstacle.x + OBSTACLE_WIDTH &&
           player.x + PLAYER_WIDTH > obstacle.x &&
           player.y < obstacle.y + OBSTACLE_HEIGHT &&
           player.y + PLAYER_HEIGHT > obstacle.y;
}
