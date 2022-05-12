#include "floor.h"

Floor::Floor(const std::string& texture, Character* player, const int& col, const int& row)
    : Tile(texture, player, col, row)

{

}

Tile* Floor::onEnter(Tile* fromTile, Character* who){
    return this;
}
Tile* Floor::onLeave(Tile* destTile, Character* who){

    return this;
}
