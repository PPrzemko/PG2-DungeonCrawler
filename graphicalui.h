#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
#include "abstractui.h"
#include "controller.h"
#include "startscreen.h"

class GraphicalUI : public AbstractUI, public Controller
{
public:
    GraphicalUI();
    void draw(Level* s) override;
    char move() override;
};

#endif // GRAPHICALUI_H
