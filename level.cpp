#include "level.h"

using nlohmann::json;

Level::Level(const int& col, const int& row, const std::string& name, Controller *con) :
    col(col), row(row), name(name)
{


    //Floor* k = new Floor(".", d, 0 , 0);
    //Floor* g = new Floor(".", nullptr, 1 , 1);
    Portal* redPortal1 = new Portal(Rot, 1 , 9);
    Portal* redPortal2 = new Portal(Rot, 2 , 1);
    redPortal1->setDestination(redPortal2);
    redPortal2->setDestination(redPortal1);

    Portal* bluePortal1 = new Portal(Blau, 3 , 7);
    Portal* bluePortal2 = new Portal(Blau, 6 , 1);
    bluePortal1->setDestination(bluePortal2);
    bluePortal2->setDestination(bluePortal1);



    Door* door1 = new Door(4 , 11);
    Switch* switch1 = new Switch(6 ,6);
    switch1->attach(door1);


    // 0
    world.push_back({new Wall(0 , 0),new Wall(0 , 1),new Wall(0 , 2),new Wall(0 , 3),new Wall(0 , 4),new Wall(0 , 5),new Wall(0 , 6),new Wall(0 , 7),new Wall(0 , 8),
                     new Wall(0 , 9),new Wall(0 , 10),new Wall(0 , 11),new Wall(0 , 12),new Wall(0 , 13),new Wall(0 , 14),new Wall(0 , 15)});
    //1
    world.push_back({new Wall(1 , 0),new Floor(1 , 1),new Floor(1 , 2),new Floor(1 , 3),new Floor(1 , 4),new Floor(1 , 5),new Floor(1 , 6),new Floor(1 , 7),new Wall(1 , 8),
                     redPortal1     ,new Floor(1 , 10),new Pit(1 , 11),new Ramp(1 , 12),new Floor(1 , 13),new Floor(1 , 14),new Wall(1 , 15)});
    // 2
    world.push_back({new Wall(2 , 0),redPortal2     ,new Floor(2 , 2),new Floor(2 , 3),new Floor(2 , 4),new Floor(2 , 5),new Wall(2 , 6),new Wall(2 , 7),new Wall(2 , 8),
                     new Floor(2 , 9),new Pit(2 , 10),new Pit(2 , 11),new Pit(2 , 12),new Floor(2 , 13),new Floor(2 , 14),new Wall(2 , 15)});
    // 3
    world.push_back({new Wall(3 , 0),new Floor(3 , 1),new Floor(3 , 2),new Floor(3 , 3),new Floor(3 , 4),new Floor(3 , 5),new Wall(3 , 6),bluePortal1   ,new Wall(3 , 8),
                     new Floor(3 , 9),new Floor(3 , 10),new Floor(3 , 11),new Floor(3 , 12),new Floor(3 , 13),new Floor(3 , 14),new Wall(3 , 15)});
    // 4
    world.push_back({new Wall(4 , 0),new Floor(4 , 1),new Floor(4 , 2),new Floor(4 , 3),new Floor(4 , 4),new Floor(4 , 5),new Floor(4 , 6),new Floor(4 , 7),new Wall(4 , 8),
                     new Wall(4 , 9),new Wall(4 , 10),door1     ,new Wall(4 , 12),new Wall(4 , 13),new Wall(4 , 14),new Wall(4 , 15)});
    // 5
    world.push_back({new Wall(5 , 0),new Wall(5 , 1),new Wall(5 , 2),new Wall(5 , 3),new Wall(5 , 4),new Wall(5 , 5),new Wall(5 , 6),new Wall(5 , 7),new Wall(5 , 8),
                     new Floor(5 , 9),new Floor(5 , 10),new Floor(5 , 11),new Floor(5 , 12),new Floor(5 , 13),new Floor(5 , 14),new Wall(5 , 15)});
    //6
    world.push_back({new Wall(6 , 0),bluePortal2        ,new Floor(6 , 2),new Floor(6 , 3),new Floor(6 , 4),new Floor(6 , 5),switch1      ,new Wall(6 , 7),new Wall(6 , 8),
                     new Floor(6 , 9),new Floor(6 , 10),new Floor(6 , 11),new Floor(6 , 12),new Floor(6 , 13),new Floor(6 , 14),new Wall(6 , 15)});
    // 7
    world.push_back({new Wall(7 , 0),new Wall(7 , 1),new Wall(7 , 2),new Wall(7 , 3),new Wall(7 , 4),new Wall(7 , 5),new Wall(7 , 6),new Wall(7 , 7),new Wall(7 , 8),
                     new Wall(7 , 9),new Wall(7 , 10),new Wall(7 , 11),new Wall(7 , 12),new Wall(7 , 13),new Wall(7 , 14),new Wall(7 , 15)});



    Character* d = new Character(con,10,5,false);
    characterVector.push_back(d);
    placeCharacter(d,2,2);
    d->getCurrentTile()->setPlayer(nullptr);

    StationaryController* z1c = new StationaryController();
    Character* z1 = new Character(z1c,9,2,true);
    characterVector.push_back(z1);
    placeCharacter(z1,4,4);

    GuardController* z2c = new GuardController("axdw");
    Character* z2 = new Character(z2c,20,10,true);
    characterVector.push_back(z2);
    placeCharacter(z2,3,14);


}

void Level::placeCharacter(Character *c, int col, int row)
{
    c->setCurrentTile(world.at(col).at(row));
    world.at(col).at(row)->setPlayer(c);
}

void Level::writeInJSON(const std::string &path)
{
    std::ofstream tmplevel(path);
    json j;
    j["alevel"] = name;
    j["characters"] = json::array();
    j["tiles"] = json::array();



    for(auto& a: characterVector){

        //if(typeid(*a->getController() == *GuardController))
        std::string givenController = typeid(*a->getController()).name();
        givenController=givenController.erase(0,2);

        if(givenController=="GuardController"){
            j["characters"].push_back({
                                          {"col", a->getCurrentTile()->getColumn()},
                                          {"row", a->getCurrentTile()->getRow()},
                                          {"controller", givenController},
                                          {"hp", a->getHitpoints()},
                                          {"stamina", a->getStamina()},
                                          {"strength", a->getStrength()},
                                          {"npc", a->getNpc()},
                                          {"texture", a->getTexture()},
                                          {"movement",dynamic_cast<GuardController*>(a->getController())->getSequence()}
            });
        }else{
            j["characters"].push_back({
                                            {"col", a->getCurrentTile()->getColumn()},
                                            {"row", a->getCurrentTile()->getRow()},
                                            {"controller", givenController},
                                            {"hp", a->getHitpoints()},
                                            {"stamina", a->getStamina()},
                                            {"strength", a->getStrength()},
                                            {"npc", a->getNpc()},
                                            {"texture", a->getTexture()}
            });
        }



    }

    for(auto &a : world){
        for(auto &b : a){
           if(typeid(*b)==typeid(Floor) || typeid(*b)==typeid(Wall) || typeid(*b)==typeid(Lootchest) ){
               j["tiles"].push_back({
                                             {"col", b->getColumn()},
                                             {"row", b->getRow()},
                                             {"texture", b->getTexture()}
                                         });
           }else if(typeid(*b)==typeid(Portal)){
               j["tiles"].push_back({
                                        {"col", b->getColumn()},
                                        {"row", b->getRow()},
                                        {"texture", b->getTexture()},
                                        {"destinationCol", dynamic_cast<Portal*>(b)->getDestination()->getColumn()},
                                        {"destinationRow", dynamic_cast<Portal*>(b)->getDestination()->getRow()}
                                         });
           }else if(typeid(*b)==typeid(Switch)){


               json passivearray;
               passivearray= json::array();

               for(auto &a : dynamic_cast<Active*>(b)->getLinkedPassives()){
                   passivearray.push_back({
                                              {"linkedcol", dynamic_cast<Tile*>(a)->getColumn()},
                                              {"linkedrow", dynamic_cast<Tile*>(a)->getRow()}
                                          });

               }



               j["tiles"].push_back({
                                        {"col", b->getColumn()},
                                        {"row", b->getRow()},
                                        {"texture", b->getTexture()},
                                        {"targets", passivearray}
                                    });




           }else if(typeid(*b)==typeid(Door)){

               j["tiles"].push_back({
                                        {"col", b->getColumn()},
                                        {"row", b->getRow()},
                                        {"texture", b->getTexture()},
                                        {"opened", dynamic_cast<Door*>(b)->getOpen()}
                                    });
           }else if(typeid(*b)==typeid(Levelchanger)){

                j["tiles"].push_back({
                                        {"col", b->getColumn()},
                                        {"row", b->getRow()},
                                        {"texture", b->getTexture()},
                                        {"destinationPortalCol", dynamic_cast<Levelchanger*>(b)->getPortalDestination()->getColumn()},
                                        {"destinationPortalRol", dynamic_cast<Levelchanger*>(b)->getPortalDestination()->getRow()},
                                        {"destinationLevel", dynamic_cast<Levelchanger*>(b)->getLevelDestination()->getName()}
                                    });
           }





        }
    }






    tmplevel << j.dump(2);
    tmplevel.close();
}
Levelchanger *Level::createLevelChangerAt(const int &col, const int &row, Level *level)
{
    delete world.at(col).at(row);
    Levelchanger* tmpLevelchanger = new Levelchanger(col,row, level);
    world.at(col).at(row)=tmpLevelchanger;
    return tmpLevelchanger;

}

void Level::createLootChestAt(const int &col, const int &row)
{
    delete world.at(col).at(row);
    Lootchest* tmpLootChest = new Lootchest(col,row);
    world.at(col).at(row)=tmpLootChest;

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
                Tile* k = new Wall(c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Floor)){
                Tile* k = new Floor(c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Portal)){
                Tile* k = new Portal(dynamic_cast<Portal*>(c)->getPortalTypeID(),c->getColumn() , c->getRow());
                portalQueue.push_back(dynamic_cast<Portal*>(k));
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Door)){
                Tile* k = new Door(c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Switch)){
                Tile* k = new Switch(c->getColumn() , c->getRow());
                linkQueue.push_back(dynamic_cast<Tile*>(k));
                Switch *c1 = dynamic_cast<Switch*>(c);
                for(auto &a:c1->getLinkedPassives()){
                     linkQueue.push_back(dynamic_cast<Tile*>(a));
                }
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Ramp)){
                Tile* k = new Ramp(c->getColumn() , c->getRow());
                world.at(i).at(j)=k;
            }else if(typeid (*c)==typeid (Pit)){
                Tile* k = new Pit(c->getColumn() , c->getRow());
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
    // TODO: Copy constructor PortalColor/ID prob not working
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

Level &Level::operator=(Level level)
{
    col=level.getCol();
    row=level.getRow();
    std::swap(characterVector,level.characterVector);
    std::swap(world,level.world);
    return *this;
}

Level::~Level()
{
    for(size_t i = 0; i < characterVector.size(); ++i){
            delete characterVector.at(i);
    }

    for(auto&a : world){
        for(auto&b : a){
            delete b;
        }
    }

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

const std::string &Level::getName() const
{
    return name;
}

const std::vector<std::vector<Tile *> > &Level::getTileVector() const
{
    return world;
}

const std::vector<Character *> &Level::getCharacterVector() const
{
    return characterVector;
}


void Level::setCharacterinVector(Character* newCharacter)
{
    characterVector.at(0)=newCharacter;
}
