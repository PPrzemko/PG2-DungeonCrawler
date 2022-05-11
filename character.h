#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Tile;

class Character
{
private:

protected:
    Tile* currentTile;
    std::string texture;


public:
    Character(std::string texture);
    Tile *getCurrentTile() const;
    std::string move();
    const std::string &getTexture() const;
};

#endif // CHARACTER_H
