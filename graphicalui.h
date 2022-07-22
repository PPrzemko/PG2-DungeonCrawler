#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
#include "abstractui.h"
#include "controller.h"
#include "startscreen.h"
#include "mainwindow.h"
#include "level.h"
#include <QPushButton>
#include <QObject>
#include <QTest>
#include <QCoreApplication>
class Levelchanger;
class Door;
class GraphicalUI : public AbstractUI, public Controller, public QObject
{

private:
    StartScreen* startScreen;
    MainWindow* mainWindow;
    std::map<std::string,QPixmap*> textures;

    void animatePlayer(char movement, Character* currentChar);
    void animateZombie(char movement, Character* currentChar);
    void drawCharacter(Level* s);

public:
    GraphicalUI();
    void draw(Level* s) override;
    void initField(Level* s);
    char move() override;
    void initTextures();
    void showEndScreen(const bool& win);
    void reDrawTexture(const int& col, const int& row);


    StartScreen *getStartScreen() const;
    MainWindow *getMainWindow() const;
    void StartButtonClicked();

public slots:


};

#endif // GRAPHICALUI_H
