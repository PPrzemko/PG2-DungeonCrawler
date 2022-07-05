#include "character.h"
Character::Character(Controller* controller, const int& strength, const int& stamina, const bool& npc) : controller(controller), strength(strength), stamina(stamina), npc(npc)
{
    if(npc){
        texture="zombieRIGHT";
    }else{
        texture="Player";
    }

    this->hitpoints=getMaxHP();

}

void Character::attack(Character *defender)
{
    defender->setHitpoints(defender->getHitpoints()-strength);
}

bool Character::isAlive()
{
    bool isAlive = true;
    if(hitpoints<=0){
        isAlive=false;
    }
    return isAlive;
}


bool Character::getNpc() const
{
    return npc;
}
int Character::getStrength() const
{
    return strength;
}

int Character::getStamina() const
{
    return stamina;
}


int Character::getHitpoints() const
{
    return hitpoints;
}



const char &Character::getLastMoveDirection() const
{
    return lastMoveDirection;
}

void Character::setLastMoveDirection(const char &newLastMoveDirection)
{
    lastMoveDirection = newLastMoveDirection;
}


int Character::getMaxHP()
{
    int maxHP = 20+(stamina*5);
    return maxHP;
}

Tile *Character::getCurrentTile() const
{
    return currentTile;
}

void Character::setCurrentTile(Tile *newCurrentTile)
{
    currentTile = newCurrentTile;
}

char Character::move()
{
    return controller->move();
}
const std::string &Character::getTexture() const
{
    return texture;
}

void Character::setHitpoints(int newHitpoints)
{
    hitpoints = newHitpoints;
}

void Character::setTexture(const std::string &newTexture)
{
    texture = newTexture;
}

