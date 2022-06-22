#include "switch.h"

Switch::Switch(const int& col, const int& row, Character* player) : Tile("?", player, col, row), Active()
{

}

Tile *Switch::onLeave(Tile *destTile, Character *who)
{
    return this;
}

Tile *Switch::onEnter(Tile *fromTile, Character *who)
{
    this->activate();
    return this;
}
