#include "ramp.h"

Ramp::Ramp(const int& col, const int& row, Character* player) : Tile(player, col, row)
{
    texture="Ramp";
}
Tile* Ramp::onEnter(Tile* fromTile, Character* who){
    if(hasCharacter()){
        return nullptr;
    }
    return this;

}

Tile* Ramp::onLeave(Tile* destTile, Character* who){

    return this;
}
