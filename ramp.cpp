#include "ramp.h"

Ramp::Ramp(const int& col, const int& row, Character* player) : Tile(">", player, col, row)
{

}
Tile* Ramp::onEnter(Tile* fromTile, Character* who){
    return this;

}

Tile* Ramp::onLeave(Tile* destTile, Character* who){

    return this;
}
