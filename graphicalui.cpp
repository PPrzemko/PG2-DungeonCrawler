#include "graphicalui.h"


GraphicalUI::GraphicalUI()
{
    mainWindow = new MainWindow();
    startScreen = new StartScreen(mainWindow);
    QObject::connect(startScreen->getButtonStartGame(), &QPushButton::clicked, this, &GraphicalUI::StartButtonClicked);
    startScreen->show();

}




void GraphicalUI::draw(Level* s){

    std::string tmpStrength = std::to_string(s->getCharacterVector().at(0)->getStrength());
    std::string tmpStamina = std::to_string(s->getCharacterVector().at(0)->getStamina());
    std::string tmpHitpoints = std::to_string(s->getCharacterVector().at(0)->getHitpoints());
    mainWindow->updateStausbarLabels(tmpStrength,tmpStamina,tmpHitpoints);

    drawCharacter(s);

    int col = s->getCol();
    int row = s->getRow();
    for(int i = 0; i < col;++i){
        for(int j = 0; j < row;++j){

            Tile* currentTile = s->getTile(i,j);

            // Update Door Status
            if(typeid (*currentTile) == typeid (Door)){
                Door *door = dynamic_cast<Door*>(currentTile);
                if(door->getOpen()){
                    mainWindow->setPlayerLabelTexture(textures.find("DoorOpen")->second,i,j);
                }else if(!door->getOpen()){
                    mainWindow->setPlayerLabelTexture(textures.find("DoorClose")->second,i,j);
                }
            }

        }
    }



}

void GraphicalUI::drawCharacter(Level* s)
{
    for(int i=0 ; i < s->getCharacterVector().size() ; i++){


        //std::cout << i << "Texture: " << s->getCharacterVector().at(i)->getTexture() << std::endl;

        char movement = s->getCharacterVector().at(i)->getLastMoveDirection();
        if(s->getCharacterVector().at(i)->getNpc() && s->getCharacterVector().at(i)->isAlive()){
            animateZombie(movement,s->getCharacterVector().at(i));
            std::cout << "Animate Zombie Movement:" << i << std::endl;
        }else if(!s->getCharacterVector().at(i)->getNpc() && s->getCharacterVector().at(i)->isAlive()){
            animatePlayer(movement, s->getCharacterVector().at(i));
            std::cout << "Animate Player Movement"<< std::endl;
        }
        // Updates all pixmapes based on character texture attribute
        mainWindow->getCharacterLabelVector().at(i)->setPixmap(*textures.find(s->getCharacterVector().at(i)->getTexture())->second);

        Tile* currentTile = s->getCharacterVector().at(i)->getCurrentTile();
        bool isPit=false;
        if(typeid (*currentTile) == typeid (Pit)){
           isPit=true;
        }
        int col = currentTile->getColumn();
        int row = currentTile->getRow();
        mainWindow->setCharacterParent(col,row,isPit,i);
    }

}

char GraphicalUI::move()
{
    char c = 'o';
    while(c=='o'){
        QTest::qWait(100);
        QCoreApplication::processEvents(QEventLoop::AllEvents);
        if(mainWindow->getHasInputReady()){
            c = mainWindow->getDirection();
            mainWindow->setHasInputReady(false);
        }
    }

     return c;
}



void GraphicalUI::initField(Level* s)
{
    initTextures();
    mainWindow->addControl(textures);
    // TODO CharacterVector Add loop shit qlabel
    mainWindow->addCharacter(textures);
    mainWindow->addCharacter(textures);
    mainWindow->addCharacter(textures);
    // create tiles with QPixmap texures
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
    }


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
    QPixmap* player1 = new QPixmap("://texture/char/front/char_front_2.png");
    textures.insert(std::make_pair("Player1",player1));
    QPixmap* player2 = new QPixmap("://texture/char/front/char_front_3.png");
    textures.insert(std::make_pair("Player2",player2));

    QPixmap* playerUP = new QPixmap("://texture/char/back/char_back_1.png");
    textures.insert(std::make_pair("PlayerUP",playerUP));
    QPixmap* playerUP1 = new QPixmap("://texture/char/back/char_back_2.png");
    textures.insert(std::make_pair("PlayerUP1",playerUP1));
    QPixmap* playerUP2 = new QPixmap("://texture/char/back/char_back_3.png");
    textures.insert(std::make_pair("PlayerUP2",playerUP2));

    QPixmap* playerRIGHT = new QPixmap("://texture/char/right/char_right_1.png");
    textures.insert(std::make_pair("PlayerRIGHT",playerRIGHT));
    QPixmap* playerRIGHT1 = new QPixmap("://texture/char/right/char_right_2.png");
    textures.insert(std::make_pair("PlayerRIGHT1",playerRIGHT1));
    QPixmap* playerRIGHT2 = new QPixmap("://texture/char/right/char_right_3.png");
    textures.insert(std::make_pair("PlayerRIGHT2",playerRIGHT2));

    QPixmap* playerLEFT = new QPixmap("://texture/char/left/char_left_1.png");
    textures.insert(std::make_pair("PlayerLEFT",playerLEFT));
    QPixmap* playerLEFT1 = new QPixmap("://texture/char/left/char_left_2.png");
    textures.insert(std::make_pair("PlayerLEFT1",playerLEFT1));
    QPixmap* playerLEFT2 = new QPixmap("://texture/char/left/char_left_3.png");
    textures.insert(std::make_pair("PlayerLEFT2",playerLEFT2));

    QPixmap* zombieRIGHT = new QPixmap("://texture/zombie/zombie_right.png");
    textures.insert(std::make_pair("zombieRIGHT",zombieRIGHT));
    QPixmap* zombieLEFT = new QPixmap("://texture/zombie/zombie_left.png");
    textures.insert(std::make_pair("zombieLEFT",zombieLEFT));

    QPixmap* DEAD = new QPixmap();
    textures.insert(std::make_pair("DEAD",DEAD));
}

void GraphicalUI::StartButtonClicked()
{
    startScreen->hide();
    mainWindow->show();
}

void GraphicalUI::animatePlayer(char movement, Character* currentChar)
{

    if(movement=='w' || movement=='q' || movement=='e'){
        static int zahl=0;
        if(zahl==0){
            currentChar->setTexture("PlayerUP");
            ++zahl;
        }else if(zahl==1){
             currentChar->setTexture("PlayerUP1");
            ++zahl;
        }else if(zahl==2){
             currentChar->setTexture("PlayerUP2");
            zahl=0;
        }
    }else if(movement=='x' ||	movement=='s' || movement=='y' ||	movement=='c'){
        static int zahl=0;
        if(zahl==0){
            currentChar->setTexture("Player");
            ++zahl;
        }else if(zahl==1){
            currentChar->setTexture("Player1");
            ++zahl;
        }else if(zahl==2){
            currentChar->setTexture("Player2");
            zahl=0;
        }

    }else if(movement=='a'){
        static int zahl=0;
        if(zahl==0){
                    currentChar->setTexture("PlayerLEFT");
            ++zahl;
        }else if(zahl==1){
                    currentChar->setTexture("PlayerLEFT1");
            ++zahl;
        }else if(zahl==2){
                    currentChar->setTexture("PlayerLEFT2");
            zahl=0;
        }

    }else if(movement=='d'){
        static int zahl=0;
        if(zahl==0){
            currentChar->setTexture("PlayerRIGHT");
            ++zahl;
        }else if(zahl==1){
            currentChar->setTexture("PlayerRIGHT1");
            ++zahl;
        }else if(zahl==2){
            currentChar->setTexture("PlayerRIGHT2");
            zahl=0;
        }

    }else{
        currentChar->setTexture("Player");

    }
}

void GraphicalUI::animateZombie(char movement, Character* currentChar)
{
    if(movement=='a' || movement=='q' || movement=='y'){
        currentChar->setTexture("zombieLEFT");
    }else if(movement=='d'||movement=='e'||movement=='c'){
        currentChar->setTexture("zombieRIGHT");
    }else{
        currentChar->setTexture("zombieLEFT");
    }

}
