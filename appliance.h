#ifndef APPLIANCE_H
#define APPLIANCE_H

struct type
{
    int minE; //W
    int maxE; //W
    int minUseInterval; //min
    int maxUseInterval; //min
    int minUseTime; //min
    int maxUseTime; //min
};

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

enum TYPE_ENUM {TYPE_FRIDGE = 0, TYPE_BLENDER = 1, TYPE_HEATING = 2, TYPE_SAUNA = 3, TYPE_WASH = 4, TYPE_DISH = 5, TYPE_TV = 6, TYPE_PC = 7, TYPE_LIGHT = 8};

class Appliance
{
public:
    Appliance(TYPE_ENUM t, int power);

    int W;
    TYPE_ENUM type;
    bool on = false;
};

#endif // APPLIANCE_H
