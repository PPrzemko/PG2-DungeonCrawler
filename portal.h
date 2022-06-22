#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

enum PortalTypes{Blau,Rot,Gelb};

class Portal : public Tile
{
private:

    Tile* destination;
    int portalType;

public:

    Portal(const int& col, const int& row,int portaltype, Character* player=nullptr);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;


    void setDestination(Tile *newDestination);
    Tile *getDestination() const;
    int getPortalType() const;
};

#endif // PORTAL_H
