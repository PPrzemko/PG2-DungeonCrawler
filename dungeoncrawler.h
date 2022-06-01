#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "abstractui.h"
#include "level.h"
#include <iostream>

class DungeonCrawler
{

protected:
AbstractUI* UI;
Level* level;

public:
    DungeonCrawler(AbstractUI* UI, Level* level);
    void moveOffset(int i, Tile* currentCharacterTile, int colOfset, int rowOfset);
    void play();
};

#endif // DUNGEONCRAWLER_H
