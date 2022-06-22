#ifndef TILE_H
#define TILE_H
#include <string>
#include "character.h"


class Tile
{
private:

protected:
std::string texture;

Character* player;
const int col;
const int row;


public:
    Tile(Character* player, const int& col, const int& row);
    virtual ~Tile(){};
    bool hasCharacter();
    bool moveTo(Tile*destTile,Character*who);
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    virtual Tile* onLeave(Tile* destTile, Character* who) = 0;

    const std::string &getTexture();
    int getRow() const;
    int getColumn() const;

    void setPlayer(Character *newPlayer);
    void setTexture(const std::string &newTexture);
};

#endif // TILE_H
