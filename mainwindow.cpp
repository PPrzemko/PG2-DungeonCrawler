#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createGridTemplateForLabels();
    initQStatusbar();

    //QWidget::setStyleSheet("background-color: black;");
    // Background Label color (not working because character is below background label after lower)
    //ui->backgroundColorLabel->setStyleSheet("background-color : white");
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
        characterLabelVector.at(0)->setParent(label);
        characterLabelVector.at(0)->show();
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

void MainWindow::addCharacter(std::map<std::string, QPixmap *> textures)
{
    QLabel* currentCharLabel = new QLabel();
    currentCharLabel->setMaximumSize(64,64);
    currentCharLabel->setMinimumSize(64,64);
    currentCharLabel->setScaledContents(true);
    currentCharLabel->setStyleSheet("background-color: rgba(0,0,0,0%);color: rgba(150, 30, 30, 90%)");
    characterLabelVector.push_back(currentCharLabel);
    //setCharacterParent(3,3,false,characterLabelVector.size()-1);



}


void MainWindow::setCharacterParent(int col, int row, bool isPit, int characterIndex)
{

    if(isPit){
        characterLabelVector.at(characterIndex)->setParent(this);
        // Add QPoint to center char
        characterLabelVector.at(characterIndex)->move(labelVector.at(col).at(row)->pos() + QPoint(10,20));
        characterLabelVector.at(characterIndex)->lower();
        labelVector.at(col).at(row)->raise(); // does not do anything
    }else{
        characterLabelVector.at(characterIndex)->setParent(labelVector.at(col).at(row));
        characterLabelVector.at(characterIndex)->move(col,0);
    }
    // need move col, row=0 if not player shifts down

    characterLabelVector.at(characterIndex)->show();
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

const std::vector<QLabel *> &MainWindow::getCharacterLabelVector() const
{
    return characterLabelVector;
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


void MainWindow::setPlayerLabelTexture(QPixmap *texture, int col, int row)
{
    labelVector.at(col).at(row)->setPixmap(*texture);
}
void MainWindow::setPlayerLabelTexture(QPixmap *texture)
{
    characterLabelVector.at(0)->setPixmap(*texture);
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



void MainWindow::updateStausbarLabels(const std::string &strength, const std::string &stamina, const std::string &hitpoint)
{
    strengthStatusLabel->setText(QString::fromStdString(strength));
    staminaStatusLabel->setText(QString::fromStdString(stamina));
    hitPointStatusLabel->setText(QString::fromStdString(hitpoint));
}


void MainWindow::initQStatusbar()
{
    // add Statusbar
    // Add Stregth,stamina,hitpoint label and store pointer in attribute
     QLabel* strengthStatusLabelText = new QLabel();
     strengthStatusLabelText->setText("Strength");
     statusBar()->addWidget(strengthStatusLabelText);

     strengthStatusLabel = new QLabel();
     strengthStatusLabel->setText("0");
     statusBar()->addWidget(strengthStatusLabel);
     // Stamina
     QLabel* staminaText = new QLabel();
     staminaText->setText("Stamina");
     statusBar()->addWidget(staminaText);

     staminaStatusLabel = new QLabel();;
     staminaStatusLabel->setText("0");
     statusBar()->addWidget(staminaStatusLabel);
    // HP
     QLabel* HitpointText = new QLabel();
     HitpointText->setText("Hitpoints");
     statusBar()->addWidget(HitpointText);

     hitPointStatusLabel = new QLabel();
     hitPointStatusLabel->setText("0");
     statusBar()->addWidget(hitPointStatusLabel);
}

void MainWindow::createGridTemplateForLabels()
{
    int gridRow = 8;
    int gridCol = 16;
    QGridLayout* tempGridGame = new QGridLayout();
    QGridLayout* tempGridControll = new QGridLayout();
    ui->gridGame->addLayout(tempGridGame,gridRow-1,gridCol-1);
    ui->gridControl->addLayout(tempGridControll ,2,2);
}

