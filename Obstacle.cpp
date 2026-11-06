#include "Obstacle.h"

#include "raylib.h"

Obstacle::Obstacle(float x)
    : GameObject({x, OBSTACLE_GROUND_Y}, OBSTACLE_WIDTH, OBSTACLE_HEIGHT)
{
}

void Obstacle::update(float dt)
{
    position.x -= OBSTACLE_SPEED * dt;
}

void Obstacle::draw() const
{
    DrawRectangle((int)position.x, (int)position.y, (int)width, (int)height, GRAY);
}

bool Obstacle::isOffScreen() const
{
    return position.x + width < 0.0f;
}
