#include "character.h"



const char &Character::getLastMoveDirection() const
{
    return lastMoveDirection;
}

void Character::setLastMoveDirection(const char &newLastMoveDirection)
{
    lastMoveDirection = newLastMoveDirection;
}

Character::Character(Controller* controller) : texture("X"), controller(controller)
{
    texture="Player";
}



Tile *Character::getCurrentTile() const
{
    return currentTile;
}

void Character::setCurrentTile(Tile *newCurrentTile)
{
    currentTile = newCurrentTile;
}

char Character::move()
{
    return controller->move();
}
const std::string &Character::getTexture() const
{
    return texture;
}



