#include "character.h"



Character::Character(Controller* controller) : texture("X"), controller(controller)
{

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



}
const std::string &Character::getTexture() const
{
    return texture;
}



