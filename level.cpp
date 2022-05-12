#include "level.h"


Level::Level(const int& width, const int& height) :
    width(width), height(height)
{
    Character* d = new Character("X");
    characterVector.push_back(d);

    //Floor* k = new Floor(".", d, 0 , 0);
    //Floor* g = new Floor(".", nullptr, 1 , 1);

    Portal* p1 = new Portal("O", nullptr, 0 , 2);
    Portal* p2 = new Portal("O", nullptr, 0 , 1);
    p1->setDestination(p2);
    p2->setDestination(p1);


    world.push_back({new Floor(".", nullptr, 0 , 0),p2,p1,new Floor(".", nullptr, 0 , 3)});
    world.push_back({new Floor(".", nullptr, 1 , 0),new Floor(".", nullptr, 1 , 1),new Floor(".", nullptr, 1 , 2),new Floor(".", nullptr, 1 , 3)});
    world.push_back({new Floor(".", nullptr, 2 , 0),new Floor(".", nullptr, 2 , 1),new Floor(".", nullptr, 2 , 2),new Floor(".", nullptr, 2 , 3)});
    world.push_back({new Floor(".", nullptr, 3 , 0),new Floor(".", nullptr, 3 , 1),new Floor(".", nullptr, 3 , 2),new Floor(".", nullptr, 3 , 3)});
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

