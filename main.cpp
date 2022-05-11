#include <iostream>
#include <level.h>
#include <abstractui.h>
#include <dungeoncrawler.h>
#include <terminalui.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    TerminalUI* n = new TerminalUI();
    Level* k = new Level(4,4);
    DungeonCrawler(n,k);


}
