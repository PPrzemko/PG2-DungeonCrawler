#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H
#include "tile.h"
#include "active.h"
class Level;

class Levelchanger : public Tile, public Active
{
public:
    Levelchanger(const int& col, const int& row, Level* destlvl, Character* player=nullptr);



private:
    Level* levelDestination;
    Levelchanger* portalDestination;




    // Tile interface
public:
    Tile *onEnter(Tile *fromTile, Character *who) override;
    Tile *onLeave(Tile *destTile, Character *who) override;

    void setLevelDestination(Level *newLevelDestination);
    void setPortalDestination(Levelchanger *newPortalDestination);
    Level *getLevelDestination() const;
    Levelchanger *getPortalDestination() const;
};

#endif // LEVELCHANGER_H
