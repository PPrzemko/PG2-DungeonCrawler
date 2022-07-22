#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler()
{
    UI= new GraphicalUI();

    //writeSavegame()
    //readSavegame();
    level = new Level(8,16,"tmpLevel", UI);

    QPushButton* save = UI->getMainWindow()->getSaveGameButton();
    QPushButton* load = UI->getStartScreen()->getLoadGameButton();
    QPushButton* start = UI->getStartScreen()->getButtonStartGame();

    QObject::connect(save, &QPushButton::clicked, this, &DungeonCrawler::writeSavegame);
    QObject::connect(load, &QPushButton::clicked, this, &DungeonCrawler::readSavegame);
    QObject::connect(start, &QPushButton::clicked, this, &DungeonCrawler::newGame);


}

void DungeonCrawler::writeSavegame()
{
    for(List::Iterator it = levelList.begin(); it != levelList.end(); ++it){
        std::string filename = (*it)->getName();
        filename.append(".json");
        (*it)->writeInJSON(filename);
    }



    UI->initField(level);
    UI->StartButtonClicked();

}

void DungeonCrawler::readSavegame()
{
    // TODO: Need to read all json in level
    auto level1  = new Level("Level1.json", UI);
    levelList.push_back(level1);
    auto level2  = new Level("Level2.json", UI);
    levelList.push_back(level2);

    for(List::Iterator it = levelList.begin(); it != levelList.end(); ++it){
        // go through every Levelchanger for level
        for(auto& levelchanger : (*it)->getLevelchangervector()){
            // Search for level
            for(List::Iterator it = levelList.begin(); it != levelList.end(); ++it){
                if((*it)->getName()==std::get<1>(levelchanger)){
                    Level* zielLevel=(*it);
                    std::get<0>(levelchanger)->setLevelDestination(zielLevel);

                    Tile* zielTile = zielLevel->getTile(std::get<2>(levelchanger),std::get<3>(levelchanger));
                    std::get<0>(levelchanger)->setPortalDestination(dynamic_cast<Levelchanger*>(zielTile));
                    std::get<0>(levelchanger)->attach(this);
                }
            }
        }
    }



    this->level = level1;
    UI->initField(level);
    UI->StartButtonClicked();

    // TODO Go to correct level





}

void DungeonCrawler::newGame()
{


    level = new Level(8,16,"Level1", UI);
    Level* k2 = new Level(8,16,"Level2",UI);
    levelList.push_back(level);
    levelList.push_back(k2);


    k2->createLootChestAt(6,14);

    Levelchanger* l1 = level->createLevelChangerAt(6,14,k2); // 6, 13
    Levelchanger* l2 = k2->createLevelChangerAt(1,1,level);
    l1->setPortalDestination(l2);
    l2->setPortalDestination(l1);

    Passive* dc = dynamic_cast<Passive*>(this);
    l1->attach(dc);
    l2->attach(dc);



    UI->initField(level);
    UI->StartButtonClicked();


}
void DungeonCrawler::notify(Active *source)
{

    Levelchanger* levelchanger = dynamic_cast<Levelchanger*>(source);
    levelchanger->getLevelDestination()->setCharacterinVector(this->level->getCharacterVector().at(0));

    UI->reDrawTexture(levelchanger->getColumn(),levelchanger->getRow());
    this->level=levelchanger->getLevelDestination();

}

void DungeonCrawler::play()
{
    bool playing=true;
    while(playing){
        UI->draw(level);
        for(size_t i=0;i<level->getCharacterVector().size();++i){
            if(level->getCharacterVector().at(i)->isAlive()){
                char input = level->getCharacterVector().at(i)->move();
                level->getCharacterVector().at(i)->setLastMoveDirection(input);
                std:: cout << "Char:" << i << " : "<< input << std::endl;
                Tile* currentCharacterTile = level->getCharacterVector().at(i)->getCurrentTile();
                if(input=='q'){
                    moveOffset(i,currentCharacterTile,-1,-1);
                }else if(input =='w'){
                    moveOffset(i,currentCharacterTile,-1,+0);
                }else if(input =='e'){
                    moveOffset(i,currentCharacterTile,-1,+1);
                }else if(input =='a'){
                    moveOffset(i,currentCharacterTile,+0,-1);
                }else if(input =='s'){
                    moveOffset(i,currentCharacterTile,+0,+0);
                }else if(input =='d'){
                    moveOffset(i,currentCharacterTile,+0,+1);
                }else if(input =='y'){
                    moveOffset(i,currentCharacterTile,+1,-1);
                }else if(input =='x'){
                    moveOffset(i,currentCharacterTile,+1,+0);
                }else if(input =='c'){
                    moveOffset(i,currentCharacterTile,+1,+1);
                }else if(input =='p'){
                    playing = false;
                }
            }

        }
        // Player Dies
        if(!level->getCharacterVector().at(0)->isAlive()){
            UI->showEndScreen(false);
            playing = false;
        }
        // player finds chest
        if(dynamic_cast<Lootchest*>(level->getCharacterVector().at(0)->getCurrentTile())){
            UI->showEndScreen(true);
            std::cout << "YOU WON!!" << std::endl;
            playing = false;
        }
    }


}

void DungeonCrawler::moveOffset(int i, Tile* currentCharacterTile, int colOffset, int rowOffset)
{
    colOffset = currentCharacterTile->getColumn()+colOffset;
    rowOffset = currentCharacterTile->getRow()+rowOffset;

    if(colOffset>=level->getCol() || colOffset < 0){
        std::cout << "Spielfeld kann nicht verlassen werden" << std::endl;
    }else if(rowOffset>=level->getRow() || rowOffset < 0){
        std::cout << "Spielfeld kann nicht verlassen werden" << std::endl;
    }else{
        Tile* destionationtile = level->getTile(colOffset,rowOffset);
        if(destionationtile->hasCharacter() && destionationtile->getPlayer()->isAlive()){
            if(currentCharacterTile->getPlayer()->getNpc() != destionationtile->getPlayer()->getNpc()){

                fight(currentCharacterTile->getPlayer(), destionationtile->getPlayer());

            }
        }


        currentCharacterTile->moveTo(destionationtile, level->getCharacterVector().at(i));
    }

}

void DungeonCrawler::fight(Character* attacker, Character* defender)
{

    attacker->attack(defender);
    if(defender->isAlive()){
        defender->attack(attacker);
    }

    if(!defender->isAlive()){
        defender->setTexture("DEAD");
    }
    if(!attacker->isAlive()){
        attacker->setTexture("DEAD");
    }


}
