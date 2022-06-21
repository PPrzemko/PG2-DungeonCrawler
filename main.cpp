#include <main.h>
using namespace std;

    int main()
    {

    startGUIU();




    }
    void main::startGame()
    {

        TerminalUI* n = new TerminalUI();
        Level* k1 = new Level(5,5,n);
        DungeonCrawler* l = new DungeonCrawler(n,k1);
        // Level* k2 = new Level(*k1);
        // *k2=*k1;


        cout << "Hello World!123" << endl;

        while(1){
            l->play();
            system("clear");

        }
    }


    void startGUI(int &argc, char **argv){
        TerminalUI* n = new TerminalUI();
        Level* k1 = new Level(5,5,n);
        DungeonCrawler* l = new DungeonCrawler(n,k1);


        QApplication(argc,argv);



    }
