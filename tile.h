#ifndef TILE_H
#define TILE_H
#include <string>
#include "character.h"


class Tile
{
private:

protected:
const std::string texture;
Character* player;
const int row;
const int col;

public:
    Tile(const std::string& texture, Character* player, const int& col, const int& row);

    bool hasCharacter();
    bool moveTo(Tile*destTile,Character*who);
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    virtual Tile* onLeave(Tile* destTile, Character* who) = 0;

    const std::string &getTexture();
    int getRow() const;
    int getColumn() const;

    void setPlayer(Character *newPlayer);
};

#endif // TILE_H
