#ifndef FLAVOR_H_
#define FLAVOR_H_

#include <string>
#include "Vending.h"

class Flavor : public Vending{
    protected:
        string _flavor;// variable to tell what flavor the drinks or snacks are; only drinks and snacks have flavor variable

    public:
        Flavor(string name, double cost, string size, string flavor) : Vending(name, cost, size){//creates a vending object with given data, and also initializes flavor variable
            _flavor=flavor;
        }
        string getFlavor(){//returns flavor
            return _flavor;
        }
        string toString(){
            string str=_size + " "+ _flavor + " " + _name + ". Cost: $"+ to_string(_cost);
            //string str="Name: "+ _name + " Cost: $" + to_string(_cost) + " Size: " + _size + " Flavor: " + _flavor; 
            return str;
        }

};

#endif