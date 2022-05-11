#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler(AbstractUI* UI, Level* level) : UI(UI), level(level)
{

    UI->draw(level);

}
