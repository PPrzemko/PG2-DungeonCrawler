#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

class Portal : Tile
{
private:
const Tile* destination;
public:
    Portal();
};

#endif // PORTAL_H
