#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "abstractui.h"
#include "level.h"

class DungeonCrawler
{

protected:
const AbstractUI* UI;
Level* level;

public:
    DungeonCrawler(AbstractUI* UI, Level* level);
};

#endif // DUNGEONCRAWLER_H
