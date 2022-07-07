#include "guardcontroller.h"

GuardController::GuardController(const std::string& seq) : sequence(seq)
{

}

char GuardController::move()
{
    static int k=0;
    if(sequence.size()<=k){
        k=0;
    }
    return (sequence.at(k++));
}
