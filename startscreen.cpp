#include "startscreen.h"
#include "ui_startscreen.h"

StartScreen::StartScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);

    //QWidget::setStyleSheet("background-color: black;");
    ui->LabelBackgroundImage->setScaledContents(true);
    QPixmap bg = QPixmap("://texture/startscreen.png");
    ui->LabelBackgroundImage->setPixmap(bg);

    QPixmap buttonIcon = QPixmap("://texture/new_game_button.png");
    ui->ButtonStartGame->setIcon(buttonIcon);
    ui->ButtonStartGame->setIconSize(QSize(270,200));
}

QPushButton* StartScreen::getButtonStartGame()
{
    return ui->ButtonStartGame;
}

StartScreen::~StartScreen()
{
    delete ui;
}

QPushButton *StartScreen::getLoadGameButton() const
{
    return this->ui->loadGameButton;
}



