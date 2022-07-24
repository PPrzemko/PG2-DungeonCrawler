#include "door.h"

Door::Door(const int& col, const int& row, Character* player) : Tile(player, col, row), Passive()
{
    open=false;
    texture = ("DoorClose");
}

Door::Door(const int &col, const int &row, const bool &status, Character *player) : Tile(player, col, row), Passive()
{
    // needed for JSon read in level
    if(status){
        open=true;
        texture = ("DoorOpen");
    }else if(!status){
        open=false;
        texture = ("DoorClose");
    }
}

void Door::notify(Active *source)
{
    this->swapState();
    this->activate();


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

bool Door::isOpen() const
{
    return open;
}

Tile* Door::onLeave(Tile* destTile, Character* who){

    return this;
}
