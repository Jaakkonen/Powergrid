#ifndef HOUSE_H
#define HOUSE_H

#include <vector>

#include "appliance.h"

class House
{
public:
    House();

    std::vector<Appliance> appliances;
};

#endif // HOUSE_H
