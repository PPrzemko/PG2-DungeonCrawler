#include "switch.h"

Switch::Switch(Character* player, const int& col, const int& row) : Tile("?", player, col, row), Active()
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
