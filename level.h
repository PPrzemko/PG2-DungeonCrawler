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
#include "lootchest.h"
#include "stationarycontroller.h"
#include "guardcontroller.h"
#include "levelchanger.h"
#include <algorithm>
#include "json.hpp"
#include <fstream>

// includes for Json
//#include "graphicalui.h"
#include "stationarycontroller.h"
#include "guardcontroller.h"

#include "passive.h"
#include "graph.h"
#include "attackcontroller.h"
#include <list>

class GraphicalUI;
class Controller;
class Level : public Passive
{

private:
    int col;
    int row;
    std::string name;
    bool active=false;
    Graph* graph;


protected:


    std::vector<std::vector<Tile*>> world;
    std::vector<Character*> characterVector;
    std::vector<std::tuple<Levelchanger*, std::string, int, int>> levelchangervector;

public:
    Level(const int& col, const int& row, const std::string& name, Controller *con);
    Level(const Level &level);
    Level(const std::string& path, Controller *con);

    std::vector<std::string> getPath(const Level* from,const Level* to);
    Level &operator=(Level level);
    Tile *getTile(int row, int col) const;
    Levelchanger* createLevelChangerAt(const int& col, const int& row, Level* level);
    void createLootChestAt(const int& col, const int& row);
    void placeCharacter(Character *c, int row, int col);
    void writeInJSON(const std::string& path);
    ~Level();




    int getRow() const;
    int getCol() const;
    const std::vector<std::vector<Tile *> > &getTileVector() const;
    const std::vector<Character *> &getCharacterVector() const;
    void setCharacterinVector(Character* newCharacter);
    const std::string &getName() const;
    const std::vector<std::tuple<Levelchanger *, std::string, int, int> > &getLevelchangervector() const;
    void setActive(bool newActive);
    bool getActive() const;

    void notify(Active *source) override;
    Graph *getGraph() const;
};

#endif // LEVEL_H
