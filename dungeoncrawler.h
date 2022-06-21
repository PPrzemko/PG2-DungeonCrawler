#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "abstractui.h"
#include "terminalui.h"
#include "graphicalui.h"
#include "level.h"
#include <iostream>
class TerminalUI;
class DungeonCrawler
{

protected:
AbstractUI* UI;
Level* level;

public:
    DungeonCrawler();
    void moveOffset(int i, Tile* currentCharacterTile, int colOfset, int rowOfset);
    void play();
};

#endif // DUNGEONCRAWLER_H
