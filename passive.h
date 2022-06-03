#ifndef PASSIVE_H
#define PASSIVE_H

class Active;
class Passive
{

private:

public:
    Passive();
    //virtual ~Passive() = 0;
    virtual void notify(Active* source) = 0;


};

#endif // PASSIVE_H
