#include "terminalui.h"

TerminalUI::TerminalUI()
{

}

void TerminalUI::draw(Level* s)
{
    for(auto &a: s->getTileVector()){

            for(auto &b : a){

                std::cout << b->getTexture();
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
