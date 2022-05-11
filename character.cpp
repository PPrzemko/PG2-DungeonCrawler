#include "character.h"



Character::Character(std::string texture) : texture(texture)
{

}


std::string Character::move()
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
const std::string &Character::getTexture() const
{
    return texture;
}



