#include "wall.h"

Wall::Wall(const int& col, const int& row, Character* player)
    : Tile("#", player, col, row)
{

}

Tile* Wall::onEnter(Tile* fromTile, Character* who){
    return nullptr;
}
Tile* Wall::onLeave(Tile* destTile, Character* who){

    return this;
}
