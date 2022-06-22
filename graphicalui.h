#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
#include "abstractui.h"
#include "controller.h"
#include "startscreen.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QObject>

class GraphicalUI : public AbstractUI, public Controller, public QObject
{

private:
    StartScreen* startScreen;
    MainWindow* mainWindow;



public:
    GraphicalUI();
    void draw(Level* s) override;
    char move() override;


public slots:
    void StartButtonClicked();

};

#endif // GRAPHICALUI_H
