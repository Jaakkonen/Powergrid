#include "house.h"

#include <cstdlib>
#include <iostream>

House::House()
{
    for(int i = 0; i < 9; i++)
    {
        appliances.push_back(new Appliance((TYPE_ENUM)i, std::rand() % (types[i].maxE - types[i].minE) + types[i].minE));
        appliances[i]->queueAt = types[i].minUseInterval + std::rand() % (types[i].maxUseInterval - types[i].minUseInterval);
    }

}

int House::getPower()
{
    int ret = 0;
    for(int i = 0; i < 9; i++)
    {
        if(appliances[i]->powerState == POWER_FORCED_ON || appliances[i]->powerState == POWER_GRANTED_ON)
            ret += appliances[i]->W;
    }
    return ret;
}

int House::getForced()
{
    int ret = 0;
    for(int i = 0; i < 9; i++)
    {
        if(appliances[i]->powerState == POWER_FORCED_ON)
            ret += appliances[i]->W;
    }
    return ret;
}

void House::tick(Cluster* c)
{
    //std::cout << appliances[0]->type << ", " << appliances[0]->powerState << "," << appliances[0]->timer << ", " << appliances[0]->queueAt << std::endl;
    for(int i = 0; i < 9; i++)
    {
        appliances[i]->timer++;

        if(appliances[i]->timer > appliances[i]->queueAt && appliances[i]->powerState == POWER_OFF)
        {
            c->toQueue(appliances[i]);
            appliances[i]->powerState = POWER_QUEUED;
        }

        if(appliances[i]->timer > types[appliances[i]->type].maxUseInterval && (appliances[i]->powerState == POWER_QUEUED || appliances[i]->powerState == POWER_OFF))
        {
            appliances[i]->turnOn(true);
        }

        if(appliances[i]->timer > appliances[i]->queueAt && (appliances[i]->powerState == POWER_FORCED_ON || appliances[i]->powerState == POWER_GRANTED_ON))
        {
            appliances[i]->powerState = POWER_OFF;
            appliances[i]->queueAt = types[appliances[i]->type].minUseInterval + std::rand() % (types[appliances[i]->type].maxUseInterval - types[appliances[i]->type].minUseInterval);
            appliances[i]->timer = 0;
        }
    }
}
