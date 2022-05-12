#include "tile.h"



Tile::Tile(const std::string& texture, Character* player, const int& col, const int& row)
    : texture(texture), player(player), col(col), row(row)
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

bool Tile::moveTo(Tile *destTile, Character *who)
{
    bool canMove = true;
    Tile* currentTile=destTile->onEnter(player->getCurrentTile(), who);

    if(currentTile!= nullptr){
        destTile=currentTile;
    }else if(currentTile==nullptr){
        destTile=player->getCurrentTile();
    canMove = false;
    }


        Tile* actualLeavedTile = onLeave(destTile,who);
        if(actualLeavedTile == nullptr){
            canMove = false;
        }else{
            //std::cout << destTile->getColumn() << destTile->getRow() << std::endl;
            who->setCurrentTile(destTile);
            destTile->setPlayer(who);

        }
        return canMove;

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
