#ifndef LOOTCHEST_H
#define LOOTCHEST_H
#include "floor.h"

class Lootchest : public Floor
{
public:
    Lootchest(const int& col, const int& row, Character* player=nullptr);
};

#endif // LOOTCHEST_H
