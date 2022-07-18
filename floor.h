#ifndef FLOOR_H
#define FLOOR_H
#include "tile.h"
#include <string>
#include <ctime>

class Floor : public Tile
{
private:


public:
    Floor(const int& col, const int& row, Character* player=nullptr);
    Floor(const int& col, const int& row, const std::string &texture, Character* player=nullptr);
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

};

#endif // FLOOR_H
