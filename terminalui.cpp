#include "terminalui.h"

TerminalUI::TerminalUI()
{

}

void TerminalUI::draw(Level* s)
{

    for(size_t i=0;i<s->getCol();++i){

        for(size_t j=0;j<s->getCol();++j){

        std::cout << s->getTileVector().at(i).at(j)->getTexture();

        }
        std::cout << std::endl;

    }
}

char TerminalUI::move()
{
// input getten
char input;
std::cout << "Bewege dich...";
std::cin >> input;
return input;

}
