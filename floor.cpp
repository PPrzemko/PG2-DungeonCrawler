#include "floor.h"

Floor::Floor(const std::string& texture, Character* player, const int& row, const int& column)
    : Tile(texture, player, row, column)

{

}

Tile* Floor::onEnter(Tile* fromTile, Character* who){
    return nullptr;
}
