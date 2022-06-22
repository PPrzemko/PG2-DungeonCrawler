#include "floor.h"

Floor::Floor(const int& col, const int& row, Character* player)
    : Tile(".", player, col, row)

{

}

Tile* Floor::onEnter(Tile* fromTile, Character* who){
    return this;
}
Tile* Floor::onLeave(Tile* destTile, Character* who){

    return this;
}
