#ifndef MAIN_H
#define MAIN_H


#include <iostream>
#include "level.h"
#include "abstractui.h"
#include "dungeoncrawler.h"
#include "terminalui.h"
#include <QApplication>


class main{

private:

public:
    void startGame();
    void startGUI(int &argc, char **argv);


};


#endif // MAIN_H
