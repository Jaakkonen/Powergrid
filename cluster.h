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
    int maxPower;
    float optimal, suboptimal;

    std::vector<Appliance*> queue;

public:
    Cluster(int size, int max, float opt, float sub);
    void tick();

    int getPower();
    int getForced();

    void toQueue(Appliance *a);

    std::vector<House*> houses;
};

#endif // CLUSTER_H
