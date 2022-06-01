#include "level.h"


Level::Level(const int& width, const int& height) :
    width(width), height(height)
{
    Character* d = new Character();
    characterVector.push_back(d);

    //Floor* k = new Floor(".", d, 0 , 0);
    //Floor* g = new Floor(".", nullptr, 1 , 1);

    Portal* p1 = new Portal(nullptr, 2 , 3);
    Portal* p2 = new Portal(nullptr, 0 , 0);
    p1->setDestination(p2);
    p2->setDestination(p1);
    Door* d1 = new Door(nullptr, 1 , 0);
    Switch* s1 = new Switch(nullptr, 3 ,1);
    s1->attach(d1);

    Ramp *r1 = new Ramp(nullptr, 0, 2);
    Pit *pit1 = new Pit(nullptr, 0, 3);
    Pit *pit2 = new Pit(nullptr, 1, 3);

    world.push_back({p2, new Floor(nullptr, 0 , 1),r1,pit1});
    world.push_back({d1,new Floor(nullptr, 1 , 1),new Floor(nullptr, 1 , 2),pit2});
    world.push_back({new Wall(nullptr, 2 , 0),new Floor(nullptr, 2 , 1),new Floor(nullptr, 2 , 2),p1});
    world.push_back({new Wall(nullptr, 3 , 0),s1,new Floor(nullptr, 3 , 2),new Floor(nullptr, 3 , 3)});
    placeCharacter(d,2,2);


}

Level::~Level()
{

    for(int i = 0; i < characterVector.size(); ++i){
        delete characterVector.at(i);
    }
    for(int i = 0; i < world.size(); ++i){
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





int Level::getHeight() const
{
    return height;
}
int Level::getWidth() const
{
    return width;
}

const std::vector<std::vector<Tile *> > &Level::getTileVector() const
{
    return world;
}

const std::vector<Character *> &Level::getCharacterVector() const
{
    return characterVector;
}

