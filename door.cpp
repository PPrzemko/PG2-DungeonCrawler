#include "door.h"

Door::Door(const int& col, const int& row, Character* player) : Tile("X", player, col, row), Passive()
{
    open=false;
}

void Door::notify(Active *source)
{
    this->swapState();
}

void Door::swapState()
{
    open=!open;
    if(open){
        texture = ("/");
    }else{
        texture = ("X");
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
