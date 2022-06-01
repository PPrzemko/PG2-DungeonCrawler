#ifndef DOOR_H
#define DOOR_H
#include "passive.h"
#include "tile.h"

class Door : public Tile, public Passive
{
public:
    Door(Character* player, const int& col, const int& row);
    void notify(Active* source) override;
    void swapState();
    Tile* onLeave(Tile* destTile, Character* who) override;
    Tile* onEnter(Tile* fromTile, Character* who) override;
private:
    bool open;
};

#endif // DOOR_H
