#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Board.h"

// Base class of everything that lives in the game world: a rectangle with a
// position and a size, that knows how to update and draw itself.
class GameObject {
public:
    GameObject(Position position, float width, float height);
    virtual ~GameObject() = default;

    // Moves the object for one frame. dt is the frame duration in seconds.
    virtual void update(float dt) = 0;

    // Draws the object. Must be called between BeginDrawing() and EndDrawing().
    virtual void draw() const = 0;

    // True if the two rectangles overlap.
    bool collidesWith(const GameObject& other) const;

    Position getPosition() const;
    float getWidth() const;
    float getHeight() const;

protected:
    Position position;  // top-left corner, in pixels
    float width;
    float height;
};

#endif
