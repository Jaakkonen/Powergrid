#include "appliance.h"

#include <cstdlib>

type types[] =
{
    {100,  300,  5,    10,    30, 120}, //Jääkaappi
    {20,   100,  5,    600,   1,  5}, //Tehosekotin
    {1000, 2000, 75,   120,   10, 60}, //Sähkölämmitys
    {2000, 3000, 1500, 10000, 20, 60}, //Kiuas
    {300,  600,  500,  3000,  60, 120}, //Pesukone
    {200,  700,  500,  3000,  60, 120}, //Tiskikone
    {200,  400,  500,  1500, 180, 240}, //TV
    {50,   500,  60,   1000, 60, 10000}, //Tietone
    {60,   600,  10,   1000, 30, 120}, //Valaistus
};

Appliance::Appliance(int t, int power)
{
    type = (TYPE_ENUM)t;
    W = power;
}

POWERED Appliance::getPowerState()
{
    return powerState;
}

void Appliance::turnOn(bool forced)
{
    powerState = forced ? POWER_FORCED_ON : POWER_GRANTED_ON;
    timer = 0;
    queueAt = types[type].minUseTime + std::rand() % (types[type].maxUseTime - types[type].minUseTime);
}
