#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

class Portal : public Tile
{
private:
Tile* destination;

public:
    Portal(const int& col, const int& row, Character* player=nullptr);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;


    void setDestination(Tile *newDestination);
    Tile *getDestination() const;
};

#endif // PORTAL_H
