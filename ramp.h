#ifndef RAMP_H
#define RAMP_H
#include "tile.h"

class Ramp : public Tile
{
public:
    Ramp(Character* player, const int& col, const int& row);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

};

#endif // RAMP_H
