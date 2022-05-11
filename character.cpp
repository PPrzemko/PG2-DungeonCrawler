#include "character.h"


Character::Character(std::string texture) : texture("X")
{

}


std::string Character::move()
{

}

Tile *Character::getCurrentTile() const
{
    return currentTile;
}

const std::string &Character::getTexture() const
{
    return texture;
}



