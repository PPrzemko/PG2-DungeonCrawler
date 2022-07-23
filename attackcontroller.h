#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H
#include "controller.h"
#include "graph.h"
#include <list>
#include <tile.h>
#include "character.h"
class AttackController : public Controller
{

private:
    Graph* graph;
    Character* thisCharacter;
    Character* followingCharacter;
public:
    AttackController(Graph* graph);
    char move() override;
    void setThisCharacter(Character *newThisCharacter);
    void setFollowingCharacter(Character *newFollowingCharacter);
};

#endif // ATTACKCONTROLLER_H
