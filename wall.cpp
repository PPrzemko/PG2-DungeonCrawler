#include "wall.h"

Wall::Wall(const std::string& texture, Character* player, const int& row, const int& column)
    : Tile(texture, player, row, column)
{

}

Tile* Wall::onEnter(Tile* fromTile, Character* who){
    return nullptr;
}
Tile* Wall::onLeave(Tile* destTile, Character* who){

    return this;
}
