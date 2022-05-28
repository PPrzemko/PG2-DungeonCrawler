#include "tile.h"



Tile::Tile(const std::string& texture, Character* player, const int& col, const int& row)
    : texture(texture), player(player), col(col), row(row)
{

}



bool Tile::moveTo(Tile *destTile, Character *who)
{

        bool canMove = true;
        Tile* actualLeftTile = onLeave(destTile,who);
        if(actualLeftTile == nullptr){
            canMove = false;
        }else{
            Tile* actualEnteredTile=destTile->onEnter(actualLeftTile, who);
            if(actualEnteredTile == nullptr){
                canMove = false;
            }else{
                actualLeftTile->setPlayer(nullptr);
                who->setCurrentTile(actualEnteredTile);
                actualEnteredTile->setPlayer(who);
            }

        }
        return canMove;


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
    return col;
}

void Tile::setPlayer(Character *newPlayer)
{
    player = newPlayer;
}
