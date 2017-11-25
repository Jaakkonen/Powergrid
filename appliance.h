#ifndef APPLIANCE_H
#define APPLIANCE_H

#include "house.h"
#include "enums.h"

class House;
class Appliance;

struct type
{
    int minE; //W
    int maxE; //W
    int minUseInterval; //min
    int maxUseInterval; //min
    int minUseTime; //min
    int maxUseTime; //min
};

extern type types[];


class Appliance
{
    friend class House;

    POWERED powerState = POWER_OFF;
    int timer = 0;
    int queueAt = 0;

    int W;
    TYPE_ENUM type;

public:
    Appliance(int t, int power);

    POWERED getPowerState();
    void turnOn(bool forced);

    int getPower();
    TYPE_ENUM getType();
};

#endif // APPLIANCE_H
