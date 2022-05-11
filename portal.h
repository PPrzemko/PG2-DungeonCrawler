#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

class Portal : public Tile
{
private:
Tile* destination;

public:
    Portal(const std::string& texture, Character* player, const int& row, const int& column);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;


    void setDestination(Tile *newDestination);
};

#endif // PORTAL_H
