#include "portal.h"

Portal::Portal(const std::string& texture, Character* player, const int& row, const int& column)
    : Tile(texture, player, row, column)
{

}
Tile* Portal::onEnter(Tile* fromTile, Character* who){
    return this->destination;
}
Tile* Portal::onLeave(Tile* destTile, Character* who){

    return this;
}
