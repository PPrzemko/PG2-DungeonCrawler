#include "floor.h"

Floor::Floor(const int& col, const int& row, Character* player)
    : Tile(player, col, row)

{
    //texture="floorType0";
    int rand = std::rand()%5;
    if(rand==0){
        texture="floorType0";
    }else if(rand==1){
        texture="floorType1";
    }else if(rand==2){
        texture="floorType2";
    }else if(rand==3){
        texture="floorType3";
    }else if(rand==4){
        texture="floorType4";
    }


}

Tile* Floor::onEnter(Tile* fromTile, Character* who){
    if(hasCharacter()){
        return nullptr;
    }
    return this;
}
Tile* Floor::onLeave(Tile* destTile, Character* who){

    return this;
}
