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

void GraphicalUI::initField(Level* s)
{
    initTextures();

    //QPixmap* texturePath1 = new QPixmap("://texture/floor/floor1.png");
    //for(int i=0;i<128;++i){
    //   mainWindow->addTile(texturePath1);

   //}


    for(auto &a: s->getTileVector()){

            for(auto &b : a){



                //std::cout << textures.find(b->getTexture())->first;

                QPixmap* texturePath = textures.find(b->getTexture())->second;
                mainWindow->addTile(texturePath);




            }

              std::cout << std::endl;
    }
}

char GraphicalUI::move()
{

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


    QPixmap* player = new QPixmap("://texture/char/front/char_front_1.png");
    textures.insert(std::make_pair("Player",player));

}

void GraphicalUI::StartButtonClicked()
{
    startScreen->hide();
    mainWindow->show();
}
