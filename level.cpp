#include "level.h"


Level::Level(const int& col, const int& row, Controller *con) :
    col(col), row(row)
{
    Character* d = new Character(con);
    characterVector.push_back(d);

    //Floor* k = new Floor(".", d, 0 , 0);
    //Floor* g = new Floor(".", nullptr, 1 , 1);

    Portal* p1 = new Portal(nullptr, 2 , 4);
    Portal* p2 = new Portal(nullptr, 0 , 0);
    p1->setDestination(p2);
    p2->setDestination(p1);
    Door* d1 = new Door(nullptr, 1 , 0);
    Switch* s1 = new Switch(nullptr, 4 ,1);
    s1->attach(d1);

    Ramp *r1 = new Ramp(nullptr, 0, 3);
    Pit *pit1 = new Pit(nullptr, 0, 4);
    Pit *pit2 = new Pit(nullptr, 1, 4);

    world.push_back({p2, new Floor(nullptr, 0 , 1),new Floor(nullptr, 0 , 2),r1,pit1});
    world.push_back({d1,new Floor(nullptr, 1 , 1),new Floor(nullptr, 1 , 2),new Floor(nullptr, 1 , 3),pit2});
    world.push_back({new Wall(nullptr, 2 , 0),new Floor(nullptr, 2 , 1),new Floor(nullptr, 2 , 2),new Floor(nullptr, 2 , 3),p1});
    world.push_back({new Wall(nullptr, 3 , 0),new Floor(nullptr, 3 , 1),new Floor(nullptr, 3 , 2),new Floor(nullptr, 3 , 3),new Floor(nullptr, 3 , 4)});
    world.push_back({new Wall(nullptr, 4 , 0),s1,new Floor(nullptr, 4 , 2),new Floor(nullptr, 4 , 3),new Floor(nullptr, 4 , 4)});
    placeCharacter(d,2,2);


}

Level::~Level()
{

    for(size_t i = 0; i < characterVector.size(); ++i){
        delete characterVector.at(i);
    }
    for(size_t i = 0; i < world.size(); ++i){
        for (int j = 0; i < world.at(i).size(); ++i){
            delete world.at(i).at(j);
        }
    }




}

void Level::placeCharacter(Character *c, int col, int row)
{
    c->setCurrentTile(world.at(col).at(row));
    world.at(col).at(row)->setPlayer(c);


}


Tile *Level::getTile(int col, int row) const
{
    return world.at(col).at(row);
}





int Level::getCol() const
{
    return col;
}
int Level::getRow() const
{
    return row;
}

const std::vector<std::vector<Tile *> > &Level::getTileVector() const
{
    return world;
}

const std::vector<Character *> &Level::getCharacterVector() const
{
    return characterVector;
}

