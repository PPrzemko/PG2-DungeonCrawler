#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
#include "passive.h"

class Active
{
public:
    Active();
    virtual ~Active() = 0;
    void attach(Passive* obj);
    void detach(Passive* obj);
    void activate();

private:
    std::vector<Passive*> linkedPassives;
};

#endif // ACTIVE_H
