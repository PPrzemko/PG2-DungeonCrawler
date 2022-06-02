#include <iostream>
#include <level.h>
#include <abstractui.h>
#include <dungeoncrawler.h>
#include <terminalui.h>

using namespace std;

int main()
{

    TerminalUI* n = new TerminalUI();
    Level* k1 = new Level(5,5,n);
    DungeonCrawler* l = new DungeonCrawler(n,k1);
    Level* k2 = new Level(*k1);
    *k2=*k1;


    cout << "Hello World!" << endl;

    while(1){
        l->play();
        system("clear");
    }

}
