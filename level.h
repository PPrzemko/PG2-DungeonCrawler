#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "portal.h"
class Wall;
#include "floor.h"
class Tile;
#include "character.h"


class Level
{

private:
    const int width;
    const int height;
protected:


    std::vector<std::vector<Tile*>> world;
    std::vector<Character*> characterVector;

public:
    Level(const int& width, const int& height);
    Tile *getTile(int row, int col) const;
    void placeCharacter(Character *c, int row, int col);
    ~Level();



    int getWidth() const;
    int getHeight() const;
    const std::vector<std::vector<Tile *> > &getTileVector() const;
    const std::vector<Character *> &getCharacterVector() const;
};

#endif // LEVEL_H
