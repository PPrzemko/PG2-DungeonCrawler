#include "tile.h"



Tile::Tile(const std::string& texture, Character* player, const int& row, const int& column)
    : texture(texture), player(player), row(row), column(column)
{

}



const std::string &Tile::getTexture() const
{
    return texture;
}
int Tile::getRow() const
{
    return row;
}

int Tile::getColumn() const
{
    return column;
}
