#include "dungeoncrawler.h"

void DungeonCrawler::moveOfset(int i, Tile* currentCharacterTile, int colOfset, int rowOfset)
{
    Tile* destionationtile = level->getTile(currentCharacterTile->getColumn()+colOfset,currentCharacterTile->getRow()+rowOfset);
    //std::cout << currentCharacterTile->getColumn() << currentCharacterTile->getRow() << std::endl;
    //std::cout << currentCharacterTile->getColumn()+colOfset << currentCharacterTile->getRow()+rowOfset << std::endl;

    if(currentCharacterTile->moveTo(destionationtile, level->getCharacterVector().at(i))){
        currentCharacterTile->setPlayer(nullptr);
    }

}

DungeonCrawler::DungeonCrawler(AbstractUI* UI, Level* level) : UI(UI), level(level)
{

    UI->draw(level);


    while(1){
        for(size_t i=0;i<level->getCharacterVector().size();++i){
            char input = level->getCharacterVector().at(i)->move();

            Tile* currentCharacterTile = level->getCharacterVector().at(i)->getCurrentTile();
            if(input=='q'){
                moveOfset(i,currentCharacterTile,-1,-1);
            }else if(input =='w'){
                moveOfset(i,currentCharacterTile,-1,+0);
            }else if(input =='e'){
                moveOfset(i,currentCharacterTile,-1,+1);
            }else if(input =='a'){
                moveOfset(i,currentCharacterTile,+0,-1);
            }else if(input =='s'){


            }else if(input =='d'){
                moveOfset(i,currentCharacterTile,+0,+1);
            }else if(input =='y'){
                moveOfset(i,currentCharacterTile,+1,-1);
            }else if(input =='x'){
                moveOfset(i,currentCharacterTile,+1,+0);
            }else if(input =='c'){
                moveOfset(i,currentCharacterTile,+1,+1);
            }else if(input =='p'){
                exit(0);
            }


        }
        UI->draw(level);
    }


}
