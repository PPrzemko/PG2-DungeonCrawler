#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //QWidget::setStyleSheet("background-color: black;");
    int gridRow = 8;
    int gridCol = 16;
    QGridLayout* tempGridGame = new QGridLayout();
    QGridLayout* tempGridControll = new QGridLayout();
    ui->gridGame->addLayout(tempGridGame,gridRow-1,gridCol-1);
    ui->gridControl->addLayout(tempGridControll ,2,2);






    for(int i=0; i<8;++i){
         labelVector.push_back(std::vector<QLabel*>(16));
    }



}

void MainWindow::addTile(QPixmap* texturePath, bool hasPlayer)
{

    QLabel* label = new QLabel();
    //label->setStyleSheet("background-color: rgba(0,0,0,0%);color: rgba(150, 30, 30, 90%)");
    //label->raise();
    label->setPixmap(*texturePath);
    label->setMinimumSize(64,64);
    label->setScaledContents(true);
    ui->gridGame->addWidget(label);
    label->show();
    if(hasPlayer){
        currentCharLabel->setParent(label);
        currentCharLabel->show();
    }

    static int col = 0;
    static int row = 0;

    labelVector.at(col).at(row) = label;

    if(row < 15){
         ++row;
     }else{
         row = 0;
         ++col;
     }




}
void MainWindow::addPlayer(std::map<std::string, QPixmap *> textures)
{
    currentCharLabel = new QLabel();
    currentCharLabel->setPixmap(*textures.find("Player")->second);
    currentCharLabel->setMaximumSize(64,64);
    currentCharLabel->setScaledContents(true);
    setCharacterParent(3,3,false);
    //currentCharLabel->setAutoFillBackground(false);
    currentCharLabel->setStyleSheet("background-color: rgba(0,0,0,0%);color: rgba(150, 30, 30, 90%)");
    currentCharLabel->hide();

}


void MainWindow::setLabelTexture(QPixmap *texture, int col, int row)
{
    labelVector.at(col).at(row)->setPixmap(*texture);
}
void MainWindow::setLabelTexture(QPixmap *texture)
{
    currentCharLabel->setPixmap(*texture);
}

void MainWindow::setCharacterParent(int col, int row, bool isPit)
{

    if(isPit){
        //labelVector.at(col).at(row)->setParent(currentCharLabel);
        //currentCharLabel->setParent(this);

        currentCharLabel->setParent(this);
        // Add QPoint to center char
        currentCharLabel->move(labelVector.at(col).at(row)->pos() + QPoint(10,20));
        currentCharLabel->lower();
        labelVector.at(col).at(row)->raise(); // does not do anything

    }else{
        currentCharLabel->setParent(labelVector.at(col).at(row));
        currentCharLabel->move(col,0);
    }
    // need move col, row=0 if not player shifts down

    currentCharLabel->show();
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
    hasInputReady=true;

}


const std::vector<std::vector<QLabel *> > &MainWindow::getLabelVector() const
{
    return labelVector;
}


char MainWindow::getDirection() const
{
    return direction;
}

bool MainWindow::getHasInputReady() const
{
    return hasInputReady;
}

void MainWindow::setHasInputReady(bool newHasInputReady)
{
    hasInputReady = newHasInputReady;
}

QPoint MainWindow::getQPosOfLabel(int col, int row)
{
    return labelVector.at(col).at(row)->pos();
}

QLabel *MainWindow::getCurrentCharLabel() const
{
    return currentCharLabel;
}



