#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include "controller.h"
class Tile;
class Character
{
private:
    Tile* currentTile;
    std::string texture;
    Controller* controller;
    char lastMoveDirection;
    int strength;
    int stamina;
    int hitpoints;
protected:



public:
    Character(Controller* controller, const int& strength, const int& stamina);
    Tile *getCurrentTile() const;
    const std::string &getTexture() const;
    void setCurrentTile(Tile *newCurrentTile);
    char move();
    const char &getLastMoveDirection() const;
    void setLastMoveDirection(const char &newLastMoveDirection);

    int getMaxHP();
    int getStrength() const;
    int getStamina() const;
    int getHitpoints() const;
};

#endif // CHARACTER_H
