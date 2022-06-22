#include "pit.h"

Pit::Pit(const int& col, const int& row, Character* player) : Tile(player, col, row)
{
    texture="pit";
}
Tile* Pit::onEnter(Tile* fromTile, Character* who){
    return this;
}

Tile* Pit::onLeave(Tile* destTile, Character* who){

    if(typeid(*destTile)==typeid(Pit)){
        return this;
    }
    if(typeid(*destTile)==typeid(Ramp)){
        return this;

    }
    return nullptr;

}
