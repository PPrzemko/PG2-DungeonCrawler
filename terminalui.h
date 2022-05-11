#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractui.h"
#include "level.h"
#include <vector>
#include <iostream>

class TerminalUI : public AbstractUI
{
public:
    TerminalUI();
    void draw(Level* s) override;
};

#endif // TERMINALUI_H
