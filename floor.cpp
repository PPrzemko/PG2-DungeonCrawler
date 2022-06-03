#include "floor.h"

Floor::Floor(Character* player, const int& col, const int& row)
    : Tile(".", player, col, row)

{

}

Tile* Floor::onEnter(Tile* fromTile, Character* who){
    return this;
}
Tile* Floor::onLeave(Tile* destTile, Character* who){

    return this;
}
