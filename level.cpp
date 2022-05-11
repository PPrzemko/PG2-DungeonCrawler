#include "level.h"


Level::Level(const int& width, const int& height) :
    width(width), height(height)
{
    Character* d = new Character("X");
    characterVector.push_back(d);
    //Floor* k = new Floor(".", d, 0 , 0);
    //Floor* g = new Floor(".", nullptr, 1 , 1);

    world.push_back({new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0)});
    world.push_back({new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0)});
    world.push_back({new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0)});
    world.push_back({new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0),new Floor(".", nullptr, 0 , 0)});


    /*
    for(int i=0;i<=height;++i){

        world.push_back({k,k,k,k,k});

        for(int j=0;i<=width;++i){

        world.at(i).at(j)=k;

        }


    }
    world.at(k->getColumn()).at(k->getRow())=k;
    world.at(g->getColumn()).at(g->getRow())=k;

    */




}

Level::~Level()
{




}


const Tile *Level::getTile(int row, int col) const
{

}

void Level::placeCharacter(Character *c, int row, int col)
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

