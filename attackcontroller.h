#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H
#include "controller.h"

class AttackController: public Controller
{
public:
    AttackController();

    // Controller interface
public:
    char move() override;
};

#endif // ATTACKCONTROLLER_H
