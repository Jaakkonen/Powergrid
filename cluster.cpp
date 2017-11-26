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
    int heatersOn = 0;
    int heatersConstant = 5;
    for(int i = 0; i < houses.size(); i++){
        std::vector<Appliance*> a = houses[i]->getAppliances();
        for(int j = 0; j < a.size(); j++){
            if(a[j]->getType() == TYPE_HEATING && (a[j]->getPowerState() == POWER_FORCED_ON || a[j]->getPowerState() == POWER_GRANTED_ON )){
                heatersOn++;
                std::cout << heatersOn << "\n";
            }
        }
    }


    for(int i = 0; i < queue.size(); i++)
    {

        /*queue[i]->turnOn(false);
        queue.erase(queue.begin() + i);
        i--;*/
        if(queue[i]->getType() == TYPE_HEATING )
        {
            if(heatersOn < heatersConstant)
            {
                W += queue[i]->getPower();
                queue[i]->turnOn(false);
                queue.erase(queue.begin() + i);
                i--;
                heatersOn++;
                std::cout << "Toimii :O \n";
                continue;
            }
        }

        if(queue[i]->getPowerState() == POWER_QUEUED && abs((maxPower * optimal) - (W + queue[i]->getPower())) < abs((maxPower * optimal) - W))
        {
            W += queue[i]->getPower();
            queue[i]->turnOn(false);
            if(queue[i]->getType() == TYPE_HEATING) heatersOn++;

            queue.erase(queue.begin() + i);
            i--;
        }
        else if(queue[i]->getPowerState() == POWER_FORCED_ON && abs((maxPower * suboptimal) - (W + queue[i]->getPower())) < abs((maxPower * suboptimal) - W))
        {
            queue[i]->turnOn(false);
            if(queue[i]->getType() == TYPE_HEATING) heatersOn++;

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

int Cluster::getPower(TYPE_ENUM type)
{
    int ret = 0;
    for(int i = 0; i < houses.size(); i++)
    {
        ret += houses[i]->getPower(type);
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
