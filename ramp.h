#ifndef RAMP_H
#define RAMP_H
#include "tile.h"

class Ramp : public Tile
{
public:
    Ramp(const int& col, const int& row, Character* player=nullptr);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

};

#endif // RAMP_H
