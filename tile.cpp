#include "tile.h"



Tile::Tile(const std::string& texture, Character* player, const int& row, const int& column)
    : texture(texture), player(player), row(row), column(column)
{

}

bool Tile::hasCharacter()
{
    if(player==nullptr){
        return false;
    }else{
        return true;
    }
}



const std::string &Tile::getTexture()
{
    if(hasCharacter()){
        return player->getTexture();
    }
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

void Tile::setPlayer(Character *newPlayer)
{
    player = newPlayer;
}
