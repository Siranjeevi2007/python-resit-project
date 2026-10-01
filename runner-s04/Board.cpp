#include "Board.h"

#include "raylib.h"

void displayState(const Position& player, const std::vector<Position>& obstacles,
                  int score, int lives)
{
    // Ground
    DrawRectangle(0, (int)GROUND_Y, SCREEN_WIDTH, SCREEN_HEIGHT - (int)GROUND_Y, DARKGRAY);

    // Player
    DrawRectangle((int)player.x, (int)player.y, (int)PLAYER_WIDTH, (int)PLAYER_HEIGHT, RED);

    // Obstacles
    for (const Position& obstacle : obstacles) {
        DrawRectangle((int)obstacle.x, (int)obstacle.y,
                      (int)OBSTACLE_WIDTH, (int)OBSTACLE_HEIGHT, GRAY);
    }

    // Score (top left) and lives (top right)
    DrawText(TextFormat("Score: %d", score), 20, 20, 30, BLACK);

    const char* livesText = TextFormat("Lives: %d", lives);
    int livesWidth = MeasureText(livesText, 30);
    DrawText(livesText, SCREEN_WIDTH - livesWidth - 20, 20, 30, MAROON);
}

void displayGameOver(int score)
{
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Fade(BLACK, 0.6f));

    const char* title = "GAME OVER";
    DrawText(title, (SCREEN_WIDTH - MeasureText(title, 80)) / 2, 180, 80, RED);

    const char* scoreText = TextFormat("Final score: %d", score);
    DrawText(scoreText, (SCREEN_WIDTH - MeasureText(scoreText, 40)) / 2, 290, 40, RAYWHITE);

    const char* hint = "Press ESC to quit";
    DrawText(hint, (SCREEN_WIDTH - MeasureText(hint, 20)) / 2, 360, 20, LIGHTGRAY);
}
