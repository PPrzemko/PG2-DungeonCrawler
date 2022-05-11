#include "terminalui.h"

TerminalUI::TerminalUI()
{

}

void TerminalUI::draw(Level* s)
{
// s->getCharacterVector();
// s->getTileVector();



for(size_t i=0;i<=s->getTileVector().size();++i){

    for(int j=0;i<=s->getTileVector().at(i).size();++i){

    std::cout << s->getTileVector().at(i).at(j);

    }


}




}
