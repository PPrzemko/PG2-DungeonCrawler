#ifndef FLOOR_H
#define FLOOR_H
#include "tile.h"
#include <string>

class Floor : public Tile
{
private:


public:
    Floor(const std::string& texture, Character* player, const int& row, const int& columns);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

};

#endif // FLOOR_H