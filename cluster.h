#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>

#include "appliance.h"
#include "house.h"
#include "enums.h"

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
    int getPower(TYPE_ENUM type);
    int getForced();

    void toQueue(Appliance *a);

    std::vector<House*> houses;
};

#endif // CLUSTER_H
