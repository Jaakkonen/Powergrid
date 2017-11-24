#include "house.h"

#include <cstdlib>

House::House()
{
    for(int i = 0; i < 9; i++)
    {
        appliances.push_back(new Appliance((TYPE_ENUM)i, std::rand() % (types[i].maxE - types[i].minE) + types[i].minE));
        appliances[i]->queueAt = types[i].minUseInterval + std::rand() % (types[i].maxUseInterval - types[i].minUseInterval);
    }

}

void House::tick(Cluster c)
{
    for(int i = 0; i < 9; i++)
    {
        appliances[i]->timer++;

        if(appliances[i]->timer > appliances[i]->queueAt && appliances[i]->powerState == POWER_OFF)
        {
            c.toQueue(appliances[i]);
            appliances[i]->powerState = POWER_QUEUED;
        }

        if(appliances[i]->timer > types[appliances[i]->type].minUseInterval && (appliances[i]->powerState == POWER_QUEUED || appliances[i]->powerState == POWER_OFF))
        {
            appliances[i]->turnOn(true);
        }

        if(appliances[i]->timer > appliances[i]->queueAt && (appliances[i]->powerState == POWER_FORCED_ON || appliances[i]->powerState == POWER_GRANTED_ON))
        {
            appliances[i]->powerState = POWER_OFF;
            appliances[i]->queueAt = types[appliances[i]->type].minUseInterval + std::rand() % (types[appliances[i]->type].maxUseInterval - types[appliances[i]->type].minUseInterval);
        }

    }
}
