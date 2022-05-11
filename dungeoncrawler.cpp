#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler(AbstractUI* UI, Level* level) : UI(UI), level(level)
{



    UI->draw(level);
    for(size_t i=0;i<level->getCharacterVector().size();++i){
        char input = level->getCharacterVector().at(i)->move();
        if(input=='q'){

        }else if(input =='w'){

        }else if(input =='e'){

        }else if(input =='a'){

        }else if(input =='s'){

        }else if(input =='d'){

        }else if(input =='y'){

        }else if(input =='x'){

        }else if(input =='c'){

        }


    }


}
