#include "pit.h"

Pit::Pit(Character* player, const int& col, const int& row) : Tile("_", player, col, row)
{

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
