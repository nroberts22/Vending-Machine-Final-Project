#ifndef SWEETS_H_
#define SWEETS_H_

#include <string>
#include "Vending.h"

class Sweets : public Vending{
    public: 
        Sweets(string name, double cost, string size) : Vending(name, cost, size){}
        //creates vending object for a sweet that only tracks the name, cost, and size: does not track type or flavor
};

#endif