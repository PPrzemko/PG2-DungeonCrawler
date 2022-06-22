#ifndef WALL_H
#define WALL_H
#include "tile.h"

class Wall : public Tile
{
public:
    Wall(const int& col, const int& row, Character* player=nullptr);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;


};

#endif // WALL_H
