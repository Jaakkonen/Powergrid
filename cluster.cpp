#include <iostream>

#include "house.h"

#include "cluster.h"

Cluster::Cluster(int size)
{
    for(int i = 0; i < size; i++)
    {
        houses.push_back(new House());
    }
}

void Cluster::toQueue(Appliance* a)
{

}

void Cluster::tick()
{
    int W = 0, F = 0;

    for(int i = 0; i < houses.size(); i++)
    {
        houses[i]->tick(this);
        W += houses[i]->getPower();
        F += houses[i]->getForced();
    }

    std::cout << W << ", " << F << std::endl;
}
