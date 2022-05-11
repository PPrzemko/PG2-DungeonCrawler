#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractui.h"

class TerminalUI : AbstractUI
{
public:
    TerminalUI();
    void draw(Level*) override;
};

#endif // TERMINALUI_H
