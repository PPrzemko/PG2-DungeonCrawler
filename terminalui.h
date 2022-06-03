#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractui.h"
#include "level.h"
#include <vector>
#include <iostream>
#include "controller.h"

class TerminalUI : public AbstractUI, public Controller
{
public:
    TerminalUI();
    void draw(Level* s) override;
    char move() override;
};

#endif // TERMINALUI_H
