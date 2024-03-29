#include "dungeoncrawler.h"
#include "terminalui.h"

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
        currentCharacterTile->moveTo(destionationtile, level->getCharacterVector().at(i));
    }


}

void DungeonCrawler::play()
{
    UI->draw(level);

    for(size_t i=0;i<level->getCharacterVector().size();++i){

        //char input = dynamic_cast<TerminalUI*>(UI)->move();
        char input = level->getCharacterVector().at(i)->move();

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
            exit(0);
        }


    }

}

DungeonCrawler::DungeonCrawler(AbstractUI* UI, Level* level) : UI(UI), level(level)
{
}
