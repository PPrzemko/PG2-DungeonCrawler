#include "portal.h"


Portal::Portal(const int& col, const int& row,int portaltype, Character* player)
    : Tile(player, col, row), portalType(portaltype)
{
    texture="Rot";
    /*
    if(portalType==Blau){
    texture="Blau";
    }if(portalType==Rot){
    texture="Rot";
    }else if(portalType==Gelb){
    texture="Gelb";
    }
    */


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
int Portal::getPortalType() const
{
    return portalType;
}
