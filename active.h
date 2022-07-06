#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
#include "passive.h"

class Active
{
public:
    Active();
    virtual ~Active();
    void attach(Passive* obj);
    void detach(Passive* obj);
    void activate();

    const std::vector<Passive *> &getLinkedPassives() const;

private:
    std::vector<Passive*> linkedPassives;
};

#endif // ACTIVE_H
