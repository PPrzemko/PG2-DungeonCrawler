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

class Level
{

private:
    const int row;
    const int col;
protected:


    std::vector<std::vector<Tile*>> world;
    std::vector<Character*> characterVector;

public:
    Level(const int& width, const int& height);
    Tile *getTile(int row, int col) const;
    void placeCharacter(Character *c, int row, int col);
    ~Level();



    int getRow() const;
    int getCol() const;
    const std::vector<std::vector<Tile *> > &getTileVector() const;
    const std::vector<Character *> &getCharacterVector() const;
};

#endif // LEVEL_H
