#include "terminalui.h"

TerminalUI::TerminalUI()
{

}

void TerminalUI::draw(Level* s)
{

    for(int i=0;i<s->getCol();++i){

        for(int j=0;j<s->getRow();++j){

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
