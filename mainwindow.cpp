#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setStyleSheet("background-color: black;");
    int gridRow = 8;
    int gridCol = 16;
    QGridLayout* tempGridGame = new QGridLayout();
    QGridLayout* tempGridControll = new QGridLayout();
    ui->gridGame->addLayout(tempGridGame,gridRow-1,gridCol-1);
    ui->gridControl->addLayout(tempGridControll ,2,2);

}

void MainWindow::addTile(QPixmap* texturePath)
{
    QLabel* label = new QLabel();
    label->setPixmap(*texturePath);
    label->setMinimumSize(64,64);
    label->setScaledContents(true);
    ui->gridGame->addWidget(label);
    label->show();
}

void MainWindow::addControl(std::map<std::string,QPixmap*> textures)
{

    DirectionButton *arrowUPLEFT = new DirectionButton(textures.find("arrowUPLEFT")->second,'q');
    ui->gridControl->addWidget(arrowUPLEFT);
    DirectionButton *arrowUP = new DirectionButton(textures.find("arrowUP")->second,'w');
    ui->gridControl->addWidget(arrowUP);
    DirectionButton *arrowUPRIGHT = new DirectionButton(textures.find("arrowUPRIGHT")->second,'e');
    ui->gridControl->addWidget(arrowUPRIGHT);
    DirectionButton *arrowLEFT = new DirectionButton(textures.find("arrowLEFT")->second,'a');
    ui->gridControl->addWidget(arrowLEFT);
    DirectionButton *arrowMID = new DirectionButton(textures.find("arrowMID")->second,'s');
    ui->gridControl->addWidget(arrowMID);
    DirectionButton *arrowRIGHT = new DirectionButton(textures.find("arrowRIGHT")->second,'d');
    ui->gridControl->addWidget(arrowRIGHT);
    DirectionButton *arrowDOWNLEFT = new DirectionButton(textures.find("arrowDOWNLEFT")->second,'y');
    ui->gridControl->addWidget(arrowDOWNLEFT);
    DirectionButton *arrowDOWN = new DirectionButton(textures.find("arrowDOWN")->second,'x');
    ui->gridControl->addWidget(arrowDOWN);
    DirectionButton *arrowDOWNRIGHT = new DirectionButton(textures.find("arrowDOWNRIGHT")->second,'c');
    ui->gridControl->addWidget(arrowDOWNRIGHT);

    connect(arrowUPLEFT, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
    connect(arrowUP, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
    connect(arrowUPRIGHT, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
    connect(arrowLEFT, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
    connect(arrowMID, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
    connect(arrowRIGHT, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
    connect(arrowDOWNRIGHT, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
    connect(arrowDOWN, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
    connect(arrowDOWNLEFT, &DirectionButton::charButtonClicked, this, &MainWindow::charButtonClickedSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::charButtonClickedSlot(char direction)
{
    this->direction=direction;
    std::cout << direction;
}
char MainWindow::getDirection() const
{
    return direction;
}
