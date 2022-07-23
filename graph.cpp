#include "graph.h"


Graph::Graph(std::vector<std::vector<Tile*>> &world)
{
    for(auto tileVector: world){
        for(auto tile: tileVector){
            calculateAdjacencyList(tile,world);
        }
    }

}

void Graph::calculateAdjacencyList(Tile* currentTile, std::vector<std::vector<Tile*>> &world)
{
    int currentTileCol = currentTile->getColumn();
    int currentTileRow = currentTile->getRow();

    if(currentTileCol - 1 > -1 && currentTileCol + 1 < world.size() && currentTileRow - 1 > -1 && currentTileRow + 1 < world.at(currentTileCol).size()){

        Tile* topLeftTile = world.at(currentTileCol - 1).at(currentTileRow - 1);
        Tile* topTile = world.at(currentTileCol - 1).at(currentTileRow);
        Tile* topRightTile = world.at(currentTileCol - 1).at(currentTileRow + 1);

        Tile* leftTile = world.at(currentTileCol).at(currentTileRow - 1);
        Tile* rightTile = world.at(currentTileCol).at(currentTileRow + 1);

        Tile* bottomLeftTile = world.at(currentTileCol + 1).at(currentTileRow - 1);
        Tile* bottomTile = world.at(currentTileCol + 1).at(currentTileRow);
        Tile* bottomRightTile = world.at(currentTileCol + 1).at(currentTileRow + 1);

        std::vector<Tile*> adjacency;
        if(isAccessible(currentTile,topLeftTile)){
            adjacency.push_back(topLeftTile);
        }
        if(isAccessible(currentTile,topTile)){
            adjacency.push_back(topTile);
        }
        if(isAccessible(currentTile,topRightTile)){
            adjacency.push_back(topRightTile);
        }

        if(isAccessible(currentTile,leftTile)){
            adjacency.push_back(leftTile);
        }
        if(isAccessible(currentTile,rightTile)){
            adjacency.push_back(rightTile);
        }

        if(isAccessible(currentTile,bottomLeftTile)){
            adjacency.push_back(bottomLeftTile);
        }
        if(isAccessible(currentTile,bottomTile)){
            adjacency.push_back(bottomTile);
        }
        if(isAccessible(currentTile,bottomRightTile)){
            adjacency.push_back(bottomRightTile);
        }

        if(typeid (*currentTile) == typeid (Portal)){
            adjacency.push_back(dynamic_cast<Portal*>(currentTile)->getDestination());
        }

        adjacencyList.insert(std::make_pair(currentTile, adjacency));
    }


}

bool Graph::isAccessible(Tile *from, Tile *dest)
{
    bool returnValue = true;

    if(typeid (*dest) == typeid (Wall)){
        returnValue = false;
    }

    if(typeid (*dest) == typeid (Door)){
        if(!dynamic_cast<Door*>(dest)->isOpen()){
            returnValue = false;
        }
    }

    if(typeid (*from) == typeid (Pit)){
        if(typeid (dest) != typeid (Pit) && typeid (dest) != typeid (Ramp)){
            returnValue = false;
        }
    }

    return returnValue;
}

std::list<Tile *> Graph::getPath(Tile *from, Tile *to)
{
 // Breitensuche Pseudocode von Wikipedia https://en.wikipedia.org/wiki/Breadth-first_search
    std::map<Tile*,Tile*> tilePrevTile;
    std::set<Tile*> explored;
    std::queue<Tile*> q;
    Tile* root = from;
    Tile* currentTile = nullptr;
    explored.insert(root);
    q.push(root);
    while(!q.empty()){
        currentTile = q.front();
        q.pop();
        if(currentTile == to){
            break;
        }

        for(auto tile : adjacencyList.find(currentTile)->second){
            if(!(explored.count(tile) > 0)){
                explored.insert(tile);
                q.push(tile);
                tilePrevTile.insert(std::make_pair(tile, currentTile));
            }
        }
    }

    std::list<Tile*> path;
    while(currentTile != root){
        path.push_front(currentTile);
        currentTile = tilePrevTile.find(currentTile)->second;
    }
    return path;
}

void Graph::updateList(std::vector<std::vector<Tile *> > &world)
{
    // TODO: Error
    adjacencyList = std::map<Tile*,std::vector<Tile*>>();

    for(auto& tileVector: world){
        for(auto& tile: tileVector){
            calculateAdjacencyList(tile,world);
        }
    }

}



