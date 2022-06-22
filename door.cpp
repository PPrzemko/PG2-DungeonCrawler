#include "door.h"

Door::Door(const int& col, const int& row, Character* player) : Tile(player, col, row), Passive()
{
    open=false;
    texture = ("DoorClose");
}

void Door::notify(Active *source)
{
    this->swapState();
}

void Door::swapState()
{
    open=!open;
    if(open){
        texture = ("DoorOpen");
    }else{
        texture = ("DoorClose");
    }
}
Tile* Door::onEnter(Tile* fromTile, Character* who){
    if(open){
        return this;
    }else{
        return nullptr;
    }
}

Tile* Door::onLeave(Tile* destTile, Character* who){

    return this;
}
