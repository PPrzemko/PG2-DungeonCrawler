#include "ramp.h"

Ramp::Ramp(Character* player, const int& col, const int& row) : Tile(">", player, col, row)
{

}
Tile* Ramp::onEnter(Tile* fromTile, Character* who){
    return this;

}

Tile* Ramp::onLeave(Tile* destTile, Character* who){

    return this;
}
