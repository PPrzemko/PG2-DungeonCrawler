#include "attackcontroller.h"


AttackController::AttackController(Graph* graph) : graph(graph)
{

}

char AttackController::move()
{
    static int i=3;
    i++;
    if(i>2){
        i=0;
        return 's';
    }



    Tile* from = thisCharacter->getCurrentTile();
    Tile* to = followingCharacter->getCurrentTile();
    std::list<Tile*> path = graph->getPath(from, to);

    Tile* nextTile = path.front();

    int currentCol = from->getColumn();
    int currentRow = from->getRow();

    int nextCol = nextTile->getColumn();
    int nextRow = nextTile->getRow();

    int diffCol = nextCol - currentCol;
    int diffRow = nextRow - currentRow;

    char returnValue = 'o';

    if(diffCol < 0 && diffRow < 0){
        returnValue = 'q';
    }else if(diffCol < 0 && diffRow == 0){
        returnValue = 'w';
    }else if(diffCol < 0 && diffRow > 0){
        returnValue = 'e';
    }else if(diffCol == 0 && diffRow < 0){
        returnValue = 'a';
    }else if(diffCol == 0 && diffRow > 0){
        returnValue = 'd';
    }else if(diffCol > 0 && diffRow < 0){
        returnValue = 'y';
    }else if(diffCol > 0 && diffRow == 0){
        returnValue = 'x';
    }else if(diffCol > 0 && diffRow > 0){
        returnValue = 'c';
    }else{
        returnValue = 's';
    }
    return returnValue;
}

void AttackController::setThisCharacter(Character *newThisCharacter)
{
    thisCharacter = newThisCharacter;
}

void AttackController::setFollowingCharacter(Character *newFollowingCharacter)
{
    followingCharacter = newFollowingCharacter;
}

