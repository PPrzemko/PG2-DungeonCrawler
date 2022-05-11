#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler(AbstractUI* UI, Level* level) : UI(UI), level(level)
{




    for(int i=0;i>level->getCharacterVector().size();++i){
        level->getCharacterVector().at(i)->move();

    }
    UI->draw(level);

}
