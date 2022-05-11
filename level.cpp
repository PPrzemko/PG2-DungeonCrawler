#include "level.h"


Level::Level(const int& width, const int& height) :
    width(width), height(height)
{
    Character* d = new Character("X");
    characterVector.push_back(d);

    //Floor* k = new Floor(".", d, 0 , 0);
    //Floor* g = new Floor(".", nullptr, 1 , 1);

    Portal* p1 = new Portal("O", nullptr, 0 , 0);
    Portal* p2 = new Portal("O", nullptr, 0 , 0);
    p1->setDestination(p2);
    p2->setDestination(p1);


    world.push_back({new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),p1,new Floor(".", nullptr, 0 , 0)});
    world.push_back({new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0)});
    world.push_back({new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),p2,new Floor(".", nullptr, 0 , 0)});
    world.push_back({new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0)});
    placeCharacter(d,0,0);


}

Level::~Level()
{
 // "delete ptr" all objects in vector



}

void Level::placeCharacter(Character *c, int row, int col)
{
    c->setCurrentTile(world.at(row).at(col));
    world.at(row).at(col)->setPlayer(c);


}


const Tile *Level::getTile(int row, int col) const
{

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

