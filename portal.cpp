#include "portal.h"


Portal::Portal(const std::string& texture, Character* player, const int& col, const int& row)
    : Tile(texture, player, col, row)
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
