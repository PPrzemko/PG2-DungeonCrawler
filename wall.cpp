#include "wall.h"

Wall::Wall(const std::string& texture, Character* player, const int& col, const int& row)
    : Tile(texture, player, col, row)
{

}

Tile* Wall::onEnter(Tile* fromTile, Character* who){
    return nullptr;
}
Tile* Wall::onLeave(Tile* destTile, Character* who){

    return this;
}
