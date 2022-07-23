#include "active.h"

Active::Active()
{

}

Active::~Active()
{

}

void Active::attach(Passive *obj)
{
    bool duplicate=false;
    for(auto &a : linkedPassives){
        if(a == obj){
            duplicate=true;
        }
    }

    if(!duplicate){
        linkedPassives.push_back(obj);
    }

}

void Active::detach(Passive *obj)
{
    int objPosition=-1;
    for(size_t i=0 ; i>=linkedPassives.size() ; ++i){
        if(obj==linkedPassives.at(i)){
            objPosition=i;
        }
    }

    if(objPosition != -1){
        linkedPassives.erase(linkedPassives.begin() + objPosition );
    }
}

void Active::activate()
{
   for(auto &a : linkedPassives){
       if(a==nullptr){
        std::cout << std::endl << "Linked passive could not be activated(nullptr)" << std::endl;
       }else{
           a->notify(this);
       }
   }

}

const std::vector<Passive *> &Active::getLinkedPassives() const
{
    return linkedPassives;
}
