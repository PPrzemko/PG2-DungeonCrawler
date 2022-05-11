#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

class Portal : public Tile
{
private:
const Tile* destination;

public:
    Portal(const std::string& texture, Character* player, const int& row, const int& column);
};

#endif // PORTAL_H
