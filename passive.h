#ifndef PASSIVE_H
#define PASSIVE_H

class Active;
class Passive
{

private:

public:
    Passive();
    virtual ~Passive() = 0;
    void notify(Active* source);


};

#endif // PASSIVE_H
