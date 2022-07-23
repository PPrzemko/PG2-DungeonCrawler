#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <tile.h>
#include <vector>
#include "portal.h"
#include <algorithm>
#include "wall.h"
#include "door.h"
#include "pit.h"
#include "ramp.h"
#include <queue>
#include <set>
#include <list>

class Graph
{
private:
    std::map<Tile*,std::vector<Tile*>> adjacencyList;
public:
    Graph(std::vector<std::vector<Tile*>> &world);
    void calculateAdjacencyList(Tile* currentTile, std::vector<std::vector<Tile*>> &world);
    bool isAccessible(Tile* from, Tile* dest);
    std::list<Tile*> getPath(Tile* from, Tile* to);
    void updateList(std::vector<std::vector<Tile*>> &world);


};

#endif // GRAPH_H
