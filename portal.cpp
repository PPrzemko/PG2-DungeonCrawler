#include "portal.h"


Portal::Portal(int portaltype, const int& col, const int& row, Character* player)
    : Tile(player, col, row), portalTypeID(portaltype)
{
    if(portalTypeID == Blau){
        texture="Blau";
    }else if(portalTypeID == Rot){
        texture="Rot";
    }else if(portalTypeID == Gelb){
        texture="Gelb";
    }



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
int Portal::getPortalTypeID() const
{
    return portalTypeID;
}
