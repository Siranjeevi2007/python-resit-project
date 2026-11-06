#include "GameObject.h"

GameObject::GameObject(Position position, float width, float height)
    : position(position), width(width), height(height)
{
}

bool GameObject::collidesWith(const GameObject& other) const
{
    return position.x < other.position.x + other.width &&
           position.x + width > other.position.x &&
           position.y < other.position.y + other.height &&
           position.y + height > other.position.y;
}

Position GameObject::getPosition() const
{
    return position;
}

float GameObject::getWidth() const
{
    return width;
}

float GameObject::getHeight() const
{
    return height;
}
