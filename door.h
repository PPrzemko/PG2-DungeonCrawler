#ifndef DOOR_H
#define DOOR_H
#include "passive.h"
#include "tile.h"

class Door : public Tile, public Passive
{
public:
    Door(const int& col, const int& row, Character* player=nullptr);
    void notify(Active* source) override;
    void swapState();
    Tile* onLeave(Tile* destTile, Character* who) override;
    Tile* onEnter(Tile* fromTile, Character* who) override;
    bool getOpen() const;

private:
    bool open;
};

#endif // DOOR_H
