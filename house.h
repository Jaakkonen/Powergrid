#ifndef HOUSE_H
#define HOUSE_H

#include <vector>

#include "appliance.h"
#include "cluster.h"
#include "enums.h"

class House;
class Cluster;
class Appliance;

class House
{
public:
    House();

    std::vector<Appliance*> appliances;


    int getPower();
    int getPower(TYPE_ENUM type);
    int getForced();
    std::vector<Appliance*> getAppliances();
    void tick(Cluster* c);
};

#endif // HOUSE_H
