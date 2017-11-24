#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>

#include "appliance.h"
#include "house.h"

class Appliance;
class House;
class Cluster;

class Cluster
{
    std::vector<House*> houses;
    std::vector<Appliance*> appliances;

public:
    Cluster(int size);
    void tick();

    void toQueue(Appliance *a);
};

#endif // CLUSTER_H
