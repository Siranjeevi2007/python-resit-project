#include "Board.h"

#include "raylib.h"

#include "GameObject.h"

void displayState(const std::vector<const GameObject*>& objects, int score, int lives)
{
    // Ground
    DrawRectangle(0, (int)GROUND_Y, SCREEN_WIDTH, SCREEN_HEIGHT - (int)GROUND_Y, DARKGRAY);

    // Player and obstacles: the virtual draw() picks the right drawing for each one
    for (const GameObject* object : objects) {
        object->draw();
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

    const char* hint = "Press ENTER to play again or ESC to quit";
    DrawText(hint, (SCREEN_WIDTH - MeasureText(hint, 20)) / 2, 360, 20, LIGHTGRAY);
}
