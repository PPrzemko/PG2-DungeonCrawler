#ifndef FLOOR_H
#define FLOOR_H
#include "tile.h"
#include <string>

class Floor : public Tile
{
private:


public:
    Floor(const std::string& texture, Character* player, const int& row, const int& columns);
};

#endif // FLOOR_H
