#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include "controller.h"
class Tile;
class Character
{
private:

protected:
    Tile* currentTile;
    std::string texture;
    Controller* controller;


public:
    Character(Controller* controller);
    Tile *getCurrentTile() const;
    const std::string &getTexture() const;
    void setCurrentTile(Tile *newCurrentTile);
    char move();
};

#endif // CHARACTER_H
