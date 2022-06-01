#include "switch.h"

Switch::Switch(Character* player, const int& col, const int& row) : Tile("?", player, col, row), Active()
{

}

Tile *Switch::onLeave(Tile *destTile, Character *who)
{

}

Tile *Switch::onEnter(Tile *fromTile, Character *who)
{

}
