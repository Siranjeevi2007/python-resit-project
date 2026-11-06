#include "Player.h"

#include "raylib.h"

Player::Player()
    : GameObject({PLAYER_X, PLAYER_GROUND_Y}, PLAYER_WIDTH, PLAYER_HEIGHT), velocityY(0.0f)
{
}

bool Player::isOnGround() const
{
    return position.y >= PLAYER_GROUND_Y;
}

void Player::handleInput()
{
    // IsKeyPressed is true only on the frame the key goes down.
    // IsKeyDown would be true every frame and make the player jump endlessly.
    if (IsKeyPressed(KEY_SPACE) && isOnGround()) {
        velocityY = -JUMP_SPEED;  // negative = upwards in Raylib
    }
}

void Player::update(float dt)
{
    if (isOnGround() && velocityY >= 0.0f) {
        return;  // standing on the ground, nothing to do
    }

    velocityY += GRAVITY * dt;
    position.y += velocityY * dt;

    // Landing
    if (position.y >= PLAYER_GROUND_Y) {
        position.y = PLAYER_GROUND_Y;
        velocityY = 0.0f;
    }
}

void Player::draw() const
{
    DrawRectangle((int)position.x, (int)position.y, (int)width, (int)height, RED);
}

void Player::reset()
{
    position = {PLAYER_X, PLAYER_GROUND_Y};
    velocityY = 0.0f;
}
