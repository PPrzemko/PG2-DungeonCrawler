#include "portal.h"



Portal::Portal(Character* player, const int& col, const int& row)
    : Tile("O", player, col, row)
{

}
Tile* Portal::onEnter(Tile* fromTile, Character* who){
    return this->destination;
}
Tile* Portal::onLeave(Tile* destTile, Character* who){

    return this;
}
void Portal::setDestination(Tile *newDestination)
{
    destination = newDestination;
}
Tile *Portal::getDestination() const
{
    return destination;
}
