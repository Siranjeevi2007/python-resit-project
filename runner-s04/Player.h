#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

// Jump physics, in pixels per second (and pixels per second squared).
const float JUMP_SPEED = 650.0f;  // initial upward speed when Space is pressed
const float GRAVITY = 1800.0f;    // pulls the player back to the ground

// Reads the keyboard. Space starts a jump, only if the player is on the ground.
void handleInput(const Position& player, float& velocityY);

// Moves the player along its jump and lands it back on the ground.
// dt is the duration of the frame in seconds (GetFrameTime()).
void updateJump(Position& player, float& velocityY, float dt);

// True if the player rectangle overlaps the obstacle rectangle.
bool checkCollision(const Position& player, const Position& obstacle);

#endif
