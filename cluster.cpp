#include <iostream>

#include "house.h"

#include "cluster.h"

Cluster::Cluster(int size, int max, float opt, float sub)
{
    for(int i = 0; i < size; i++)
    {
        houses.push_back(new House());
    }

    maxPower = max;
    optimal = opt;
    suboptimal = sub;
}

void Cluster::toQueue(Appliance* a)
{
    queue.push_back(a);
}

void Cluster::tick()
{
    int W = getPower();

    for(int i = 0; i < queue.size(); i++)
    {
        if(queue[i]->getPowerState() == POWER_QUEUED && abs((maxPower * optimal) - (W + queue[i]->getPower())) < abs((maxPower * optimal) - W))
        {
            W += queue[i]->getPower();
            queue[i]->turnOn(false);
            queue.erase(queue.begin() + i);
            i--;
        }
        else if(queue[i]->getPowerState() == POWER_FORCED_ON && abs((maxPower * suboptimal) - (W + queue[i]->getPower())) < abs((maxPower * suboptimal) - W))
        {
            queue[i]->turnOn(false);
            queue.erase(queue.begin() + i);
            i--;
        }

    }

    for(int i = 0; i < houses.size(); i++)
    {
        houses[i]->tick(this);
    }

    std::cout << getPower() << ", " << getForced() << std::endl;
}

int Cluster::getPower()
{
    int ret = 0;
    for(int i = 0; i < houses.size(); i++)
    {
        ret += houses[i]->getPower();
    }
    return ret;
}

int Cluster::getForced()
{
    int ret = 0;
    for(int i = 0; i < houses.size(); i++)
    {
        ret += houses[i]->getForced();
    }
    return ret;
}
