#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "portal.h"
#include "wall.h"
#include "floor.h"
class Tile;
#include "character.h"
#include "door.h"
#include "switch.h"
#include "ramp.h"
#include "pit.h"
#include <algorithm>

class Controller;
class Level
{

private:
    int col;
    int row;
protected:


    std::vector<std::vector<Tile*>> world;
    std::vector<Character*> characterVector;

public:
    Level(const int& col, const int& row, Controller *con);
    Level(const Level &level);
    Level &operator=(Level level);
    Tile *getTile(int col, int row) const;
    void placeCharacter(Character *c, int col, int row);
    ~Level();


    int getCol() const;
    int getRow() const;

    const std::vector<std::vector<Tile *> > &getTileVector() const;
    const std::vector<Character *> &getCharacterVector() const;
};

#endif // LEVEL_H
