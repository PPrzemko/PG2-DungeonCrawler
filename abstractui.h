#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H
class Level;

class AbstractUI
{
public:
    AbstractUI();
    virtual void draw(Level*) = 0;


};

#endif // ABSTRACTUI_H
