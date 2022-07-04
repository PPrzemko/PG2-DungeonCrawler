#ifndef GUARDCONTROLLER_H
#define GUARDCONTROLLER_H
#include "controller.h"
#include <string>

class GuardController: public Controller
{
public:
    GuardController(const std::string& seq);
    char move() override;

private:
    std::string sequence;
};

#endif // GUARDCONTROLLER_H
