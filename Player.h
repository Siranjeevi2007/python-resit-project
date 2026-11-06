#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

// Jump physics, in pixels per second (and pixels per second squared).
const float JUMP_SPEED = 650.0f;  // initial upward speed when Space is pressed
const float GRAVITY = 1800.0f;    // pulls the player back to the ground

// The red square controlled with the keyboard.
class Player : public GameObject {
public:
    Player();

    // Reads the keyboard. Space starts a jump, only if the player is on the ground.
    void handleInput();

    // Moves the player along its jump and lands it back on the ground.
    void update(float dt) override;

    void draw() const override;

    // Puts the player back on the ground, at its start position.
    void reset();

private:
    bool isOnGround() const;

    float velocityY;  // pixels per second, negative = upwards
};

#endif
