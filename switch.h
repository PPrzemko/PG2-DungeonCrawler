#ifndef SWITCH_H
#define SWITCH_H
#include "tile.h"
#include "active.h"

class Switch : public Tile, public Active
{
public:
    Switch(Character *player, const int& col, const int& row);
    Tile *onLeave(Tile *destTile, Character *who) override;
    Tile *onEnter(Tile *fromTile, Character *who) override;
};

#endif // SWITCH_H
