#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Tile;

class Character
{
private:

protected:
    Tile* currentTile;
    const std::string texture;


public:
    Character(std::string texture);
    Tile *getCurrentTile() const;
    std::string &getTexture() const;
    int move();
};

#endif // CHARACTER_H
