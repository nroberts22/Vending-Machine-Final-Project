#ifndef SNACKS_H_
#define SNACKS_H_

#include <string>
#include "Vending.h"
#include "Flavor.h"

class Snacks : public Flavor {
    public: 
        Snacks(string name, double cost, string size, string flavor): Flavor(name, cost, size, flavor){} 
        //creates a vending object for snacks with data including a flavor
};

#endif