#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
class Tile;

class Character
{
private:

protected:
    Tile* currentTile;
    std::string texture;


public:
    Character();
    Tile *getCurrentTile() const;
    char move();
    const std::string &getTexture() const;
    void setCurrentTile(Tile *newCurrentTile);
};

#endif // CHARACTER_H
