#include "character.h"

Character::Character(std::string texture) : texture("X")
{

}


int Character::move()
{

}

Tile *Character::getCurrentTile() const
{
    return currentTile;
}

std::string &Character::getTexture() const
{
    return texture;
}


