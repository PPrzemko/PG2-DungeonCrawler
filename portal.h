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



};

#endif // PORTAL_H
