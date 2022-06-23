#include "graphicalui.h"


GraphicalUI::GraphicalUI()
{
    mainWindow = new MainWindow();
    startScreen = new StartScreen(mainWindow);
    QObject::connect(startScreen->getButtonStartGame(), &QPushButton::clicked, this, &GraphicalUI::StartButtonClicked);



    startScreen->show();



}
void GraphicalUI::draw(Level* s){

    int col = s->getCol();
        int row = s->getRow();
        for(int i = 0; i < col;++i){
            for(int j = 0; j < row;++j){

                Tile* currentTile = s->getTile(i,j);
                //Tempfix reloadtextures
                //mainWindow->setLabelTexture(textures.find(currentTile->getTexture())->second,i,j);

                if(currentTile->hasCharacter()){
                    mainWindow->setCharacterParent(i,j);

                    //mainWindow->setLabelTexture(textures.find("Player")->second,i,j);



                }

                if(typeid (*currentTile) == typeid (Door)){
                    std::cout << "TEST";
                    Door *door = dynamic_cast<Door*>(currentTile);
                    if(door->getOpen()){
                        mainWindow->setLabelTexture(textures.find("DoorOpen")->second,i,j);
                    }else if(!door->getOpen()){
                        mainWindow->setLabelTexture(textures.find("DoorClose")->second,i,j);
                    }
                }
            }
        }



}

char GraphicalUI::move()
{
    char c = 'o';

     QTest::qWait(100);
     QCoreApplication::processEvents(QEventLoop::AllEvents);
     if(mainWindow->getHasInputReady()){
         std::cout << "Direction: " << c << std::endl;
         mainWindow->setHasInputReady(false);
         c = mainWindow->getDirection();
     }
     return c;



}



void GraphicalUI::initField(Level* s)
{
    initTextures();

    //QPixmap* texturePath1 = new QPixmap("://texture/floor/floor1.png");
    //for(int i=0;i<128;++i){
    //   mainWindow->addTile(texturePath1);

   //}
    mainWindow->addControl(textures);
    mainWindow->addPlayer(textures);
    for(auto &a: s->getTileVector()){
            for(auto &b : a){
                bool hasPlayer=false;
                // std::cout << textures.find(b->getTexture())->first;
                QPixmap* texturePath = textures.find(b->getTexture())->second;

                if(b->hasCharacter()){
                   hasPlayer=true;
                }

                mainWindow->addTile(texturePath, hasPlayer);
            }

              // std::cout << std::endl;
    }





    /* DEBUG HIDE ALL
    for(auto &a: mainWindow->getLabelVector()){
        for(auto &b:a){
            b->hide();
        }
    }
    */



}



void GraphicalUI::initTextures()
{

    QPixmap* floorType0 = new QPixmap("://texture/floor/floor1.png");
    textures.insert(std::make_pair("floorType0",floorType0));

    QPixmap* floorType1 = new QPixmap("://texture/floor/floor2.png");
    textures.insert(std::make_pair("floorType1",floorType1));

    QPixmap* floorType2 = new QPixmap("://texture/floor/floor3.png");
    textures.insert(std::make_pair("floorType2",floorType2));

    QPixmap* floorType3 = new QPixmap("://texture/floor/floor4.png");
    textures.insert(std::make_pair("floorType3",floorType3));

    QPixmap* floorType4 = new QPixmap("://texture/floor/floor5.png");
    textures.insert(std::make_pair("floorType4",floorType4));

    QPixmap* pit = new QPixmap("://texture/pit.png");
    textures.insert(std::make_pair("pit",pit));

    QPixmap* doorOpen = new QPixmap("://texture/doors/door2.png");
    textures.insert(std::make_pair("DoorOpen",doorOpen));

    QPixmap* doorClose = new QPixmap("://texture/doors/door1.png");
    textures.insert(std::make_pair("DoorClose",doorClose));

    QPixmap* ramp = new QPixmap("://texture/ramp.png");
    textures.insert(std::make_pair("Ramp",ramp));

    QPixmap* switch1 = new QPixmap("://texture/switch.png");
    textures.insert(std::make_pair("Switch",switch1));

    QPixmap* PBlau = new QPixmap("://texture/portal/portal1.png");
    textures.insert(std::make_pair("Blau",PBlau));

    QPixmap* PRot = new QPixmap("://texture/portal/portal2.png");
    textures.insert(std::make_pair("Rot",PRot));

    QPixmap* PGelb = new QPixmap("://texture/portal/portal3.png");
    textures.insert(std::make_pair("Gelb",PGelb));

    QPixmap* wall = new QPixmap("://texture/wall/wall1.png");
    textures.insert(std::make_pair("Wall",wall));

    QPixmap* arrowUPLEFT = new QPixmap("://texture/arrows/arrow_up_left.png");
    textures.insert(std::make_pair("arrowUPLEFT",arrowUPLEFT));

    QPixmap* arrowUP = new QPixmap("://texture/arrows/arrow_up.png");
    textures.insert(std::make_pair("arrowUP",arrowUP));

    QPixmap* arrowUPRIGHT = new QPixmap("://texture/arrows/arrow_up_right.png");
    textures.insert(std::make_pair("arrowUPRIGHT",arrowUPRIGHT));

    QPixmap* arrowLEFT = new QPixmap("://texture/arrows/arrow_left.png");
    textures.insert(std::make_pair("arrowLEFT",arrowLEFT));

    QPixmap* arrowMID = new QPixmap("://texture/arrows/arrow_skip.png");
    textures.insert(std::make_pair("arrowMID",arrowMID));

    QPixmap* arrowRIGHT = new QPixmap("://texture/arrows/arrow_right.png");
    textures.insert(std::make_pair("arrowRIGHT",arrowRIGHT));

    QPixmap* arrowDOWNLEFT = new QPixmap("://texture/arrows/arrow_down_left.png");
    textures.insert(std::make_pair("arrowDOWNLEFT",arrowDOWNLEFT));

    QPixmap* arrowDOWN = new QPixmap("://texture/arrows/arrow_down.png");
    textures.insert(std::make_pair("arrowDOWN",arrowDOWN));

    QPixmap* arrowDOWNRIGHT = new QPixmap("://texture/arrows/arrow_down_right.png");
    textures.insert(std::make_pair("arrowDOWNRIGHT",arrowDOWNRIGHT));

    QPixmap* player = new QPixmap("://texture/char/front/char_front_1.png");
    textures.insert(std::make_pair("Player",player));


}

void GraphicalUI::StartButtonClicked()
{
    startScreen->hide();
    mainWindow->show();
}
