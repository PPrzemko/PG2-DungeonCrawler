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
    bool npc;
protected:



public:
    Character(Controller* controller, const int& strength, const int& stamina, const bool& npc);
    Tile *getCurrentTile() const;
    const std::string &getTexture() const;
    void setCurrentTile(Tile *newCurrentTile);
    char move();
    const char &getLastMoveDirection() const;
    void setLastMoveDirection(const char &newLastMoveDirection);
    void attack(Character* defender);
    bool isAlive();

    int getMaxHP();
    int getStrength() const;
    int getStamina() const;
    int getHitpoints() const;
    bool getNpc() const;
    void setHitpoints(int newHitpoints);
    void setTexture(const std::string &newTexture);
    Controller *getController() const;
};

#endif // CHARACTER_H
