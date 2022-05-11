#ifndef TILE_H
#define TILE_H
#include <string>

class Character;

class Tile
{
private:

protected:
const std::string& texture;
Character& player;
const int& row;
const int& column;

public:
    Tile(const std::string& texture, Character& player, const int& row, const int& column);
    virtual void onEnter() const = 0;
    virtual void onLeave() const = 0;
    bool hasCharacter();
    bool moveTo(Tile*destTile,Character*who);
    Tile* onEnter(Tile* fromTile, Character* who);
    Tile* onLeave(Tile* destTile, Character* who);

    const std::string &getTexture() const;
};

#endif // TILE_H
