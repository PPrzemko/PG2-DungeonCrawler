#include "graphicalui.h"

GraphicalUI::GraphicalUI()
{
    mainWindow = new MainWindow();
    startScreen = new StartScreen(mainWindow);
    QObject::connect(startScreen->getButtonStartGame(), &QPushButton::clicked, this, &GraphicalUI::StartButtonClicked);

    startScreen->show();



}
void GraphicalUI::draw(Level* s){

}

char GraphicalUI::move()
{

}

void GraphicalUI::StartButtonClicked()
{
    startScreen->hide();
    mainWindow->show();
}
