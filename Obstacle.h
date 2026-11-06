#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObject.h"

const float OBSTACLE_SPEED = 300.0f;  // pixels per second, towards the left

// A grey block standing on the ground and scrolling to the left.
class Obstacle : public GameObject {
public:
    // Creates an obstacle on the ground at the horizontal position x.
    explicit Obstacle(float x);

    void update(float dt) override;
    void draw() const override;

    // True once the obstacle has fully left the screen on the left side.
    bool isOffScreen() const;
};

#endif
