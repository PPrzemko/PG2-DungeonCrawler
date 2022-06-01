#include "character.h"



Character::Character() : texture("X")
{

}


char Character::move()
{
// input getten
char input;
std::cout << "Bewege dich...";
std::cin >> input;
return input;



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



