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

Level::Level(const Level &level) : col(level.getCol()), row(level.getRow())
{
    std::vector<Portal*> portalQueue;
    std::vector<Tile*> linkQueue;


    // Copy world tiles
    for(int i=0; i<col;++i){
        world.push_back(std::vector<Tile*>(row));
    }


    for(int i=0; i < level.getCol() ; i++) {
        for(int j=0; j < level.getRow() ; j++){
            Tile* c = level.getTileVector().at(i).at(j);
            if(typeid (*c)==typeid (Wall)){
                Tile* k = new Wall(nullptr, c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Floor)){
                Tile* k = new Floor(nullptr, c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Portal)){
                Tile* k = new Portal(nullptr, c->getColumn() , c->getRow());
                portalQueue.push_back(dynamic_cast<Portal*>(k));
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Door)){
                Tile* k = new Door(nullptr, c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Switch)){
                Tile* k = new Switch(nullptr, c->getColumn() , c->getRow());
                linkQueue.push_back(dynamic_cast<Tile*>(k));
                Switch *c1 = dynamic_cast<Switch*>(c);
                for(auto &a:c1->getLinkedPassives()){
                     linkQueue.push_back(dynamic_cast<Tile*>(a));
                }
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Ramp)){
                Tile* k = new Ramp(nullptr, c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Pit)){
                Tile* k = new Pit(nullptr, c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }

        }


    }

    // copy player
    for(auto &a:level.getCharacterVector()){
        Character* player = new Character(*a);
        int oldCol = a->getCurrentTile()->getColumn();
        int oldRow = a->getCurrentTile()->getRow();
        placeCharacter(player,oldCol,oldRow);
        characterVector.push_back(player);
    }
    // Portal
    for(auto &newPortal : portalQueue){
        int NewCol = newPortal->getColumn();
        int NewRow = newPortal->getRow();
        Portal* altesPortal= dynamic_cast<Portal*>(level.getTile(NewCol,NewRow));
        if(!altesPortal->getDestination()){
            int destCol = altesPortal->getDestination()->getColumn();
            int destRow = altesPortal->getDestination()->getRow();
            Portal* linkedPortal = dynamic_cast<Portal*>(getTile(destCol,destRow));
            newPortal->setDestination(linkedPortal);
            linkedPortal->setDestination(newPortal);

        }
    }

    //Switch Door linking
    for(auto &a : linkQueue){
        static Active* currentlyActive = nullptr;


        if(dynamic_cast<Active*>(a)){
            currentlyActive=dynamic_cast<Active*>(a);
        }else if(dynamic_cast<Passive*>(a)){
            currentlyActive->attach(dynamic_cast<Passive*>(a));
        }


    }


}



Level::~Level()
{
    for(auto &a:characterVector){
        delete a;
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

