#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "abstractui.h"
#include "terminalui.h"
#include "graphicalui.h"
#include "level.h"
#include <iostream>
#include <vector>
class TerminalUI;
class DungeonCrawler
{

protected:
    GraphicalUI* UI;
    Level* level;
    std::vector<Level*> levelVector;


public:
    DungeonCrawler();
    void moveOffset(int i, Tile* currentCharacterTile, int colOfset, int rowOfset);
    void play();
};

#endif // DUNGEONCRAWLER_H
