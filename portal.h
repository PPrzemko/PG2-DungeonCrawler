#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

enum PortalTypes{Blau,Rot,Gelb};

class Portal : public Tile
{
private:

    Tile* destination;
    int portalTypeID;

public:

    Portal(int portaltype, const int& col, const int& row,Character* player=nullptr);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;


    void setDestination(Tile *newDestination);
    Tile *getDestination() const;
    int getPortalTypeID() const;
};

#endif // PORTAL_H
