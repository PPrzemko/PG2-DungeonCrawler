#ifndef WALL_H
#define WALL_H
#include "tile.h"

class Wall : public Tile
{
public:
    Wall(const std::string& texture, Character* player, const int& row, const int& column);
    Tile* onEnter(Tile* fromTile, Character* who) override;



};

#endif // WALL_H
