#ifndef HOUSE_H
#define HOUSE_H

#include <vector>

#include "appliance.h"
#include "cluster.h"

class House
{
public:
    House();

    std::vector<Appliance*> appliances;

    int getPower();
    int getForced();

    void tick(Cluster c);
};

#endif // HOUSE_H
