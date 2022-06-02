#include <iostream>
#include <level.h>
#include <abstractui.h>
#include <dungeoncrawler.h>
#include <terminalui.h>

using namespace std;

int main()
{

    TerminalUI* n = new TerminalUI();
    Level* k = new Level(5,5,n);
    DungeonCrawler* l = new DungeonCrawler(n,k);
    //Level* das = new Level(*k);
    Level k2(*k);

    cout << "Hello World!" << endl;

    while(1){
        l->play();
        system("clear");
    }

}
