#ifndef APPLIANCE_H
#define APPLIANCE_H

//#include "house.h"

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

enum TYPE_ENUM {TYPE_FRIDGE = 0, TYPE_BLENDER = 1, TYPE_HEATING = 2, TYPE_SAUNA = 3, TYPE_WASH = 4, TYPE_DISH = 5, TYPE_TV = 6, TYPE_PC = 7, TYPE_LIGHT = 8};
enum POWERED   {POWER_OFF, POWER_QUEUED, POWER_GRANTED_ON, POWER_FORCED_ON};

class Appliance
{
    friend class House;

    POWERED powerState = POWER_OFF;
    int timer = 0;
    int queueAt = 0;

public:
    Appliance(int t, int power);

    POWERED getPowerState();
    void turnOn(bool forced);

    int W;
    TYPE_ENUM type;
};

#endif // APPLIANCE_H
