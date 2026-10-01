#ifndef BOARD_H
#define BOARD_H

#include <vector>

// ---------------------------------------------------------------------------
// Window (graphics constants)
// ---------------------------------------------------------------------------
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 576;
const int TARGET_FPS = 60;
const char* const WINDOW_TITLE = "Runner";

// ---------------------------------------------------------------------------
// World positions, in pixels.
// A Position is the top-left corner of a rectangle (Raylib convention:
// x grows to the right, y grows downwards).
// ---------------------------------------------------------------------------
struct Position {
    float x;
    float y;
};

const float GROUND_Y = 450.0f;  // y of the ground line

const float PLAYER_X = 150.0f;
const float PLAYER_WIDTH = 40.0f;
const float PLAYER_HEIGHT = 60.0f;
const float PLAYER_GROUND_Y = GROUND_Y - PLAYER_HEIGHT;  // player standing on the ground

const float OBSTACLE_WIDTH = 30.0f;
const float OBSTACLE_HEIGHT = 50.0f;
const float OBSTACLE_GROUND_Y = GROUND_Y - OBSTACLE_HEIGHT;

const int MAX_LIVES = 3;

// Draws the ground, the player, the obstacles, the score and the lives.
// Must be called between BeginDrawing() and EndDrawing().
void displayState(const Position& player, const std::vector<Position>& obstacles,
                  int score, int lives);

// Draws the GAME OVER screen on top of the last frame.
void displayGameOver(int score);

#endif
