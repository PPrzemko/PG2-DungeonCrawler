#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "abstractui.h"
#include "terminalui.h"
#include "graphicalui.h"
#include "level.h"
#include <iostream>
#include <vector>
#include "passive.h"
#include "list.h"
class Lootchest;
class TerminalUI;
#include "levelchanger.h"


class DungeonCrawler : public Passive, public QObject
{
private:
    void fight(Character* attacker, Character* defender);
    bool playing=true;
    
    void createTmpLevel();

protected:
    GraphicalUI* UI;
    Level* level;
    //std::vector<Level*> levelVector;
    List levelList;


public:
    DungeonCrawler();
    void moveOffset(int i, Tile* currentCharacterTile, int colOfset, int rowOfset);
    void play();
    void notify(Active *source) override;

public slots:
    void writeSavegame();
    void readSavegame();
    void newGame();
};

#endif // DUNGEONCRAWLER_H
