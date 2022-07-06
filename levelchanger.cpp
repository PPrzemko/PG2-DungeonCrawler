#include "levelchanger.h"

Levelchanger::Levelchanger(const int& col, const int& row,Level* destlvl, Character* player)
    : Tile(player, col, row), Active(), levelDestination(destlvl)
{
    texture="levelChanger";
}



Tile *Levelchanger::onEnter(Tile *fromTile, Character *who)
{
    activate();
    return portalDestination;
    // TODO ZOMBIE CHECK PORTAL
    /*
    if (!who->getNpc()) {
      activate();
    }
    */
    //return nullptr;

}

Tile *Levelchanger::onLeave(Tile *destTile, Character *who)
{
    return this;
}
void Levelchanger::setLevelDestination(Level *newLevelDestination)
{
    levelDestination = newLevelDestination;
}

void Levelchanger::setPortalDestination(Levelchanger *newPortalDestination)
{
    portalDestination = newPortalDestination;
}

Level *Levelchanger::getLevelDestination() const
{
    return levelDestination;
}

Levelchanger *Levelchanger::getPortalDestination() const
{
    return portalDestination;
}
