#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
class AbstractUI;
class Level;

class DungeonCrawler
{

private:
const AbstractUI* UI;
Level* level;

public:
    DungeonCrawler();
};

#endif // DUNGEONCRAWLER_H
