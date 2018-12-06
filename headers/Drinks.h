#ifndef DRINKS_H_
#define DRINKS_H_

#include <string>
#include "Vending.h"
#include "Flavor.h"

class Drinks : public Flavor{
    private:
        string _type;// variable to tell what type of drink container: bottle or can
    
    public: 
        Drinks(string name, double cost, string size, string flavor, string type): Flavor(name, cost, size, flavor){
            _type=type;// creates a Vending object with given data and initializes the type variable as well
        }
        string getType(){
            return _type;//returns type of drink container
        }
        string toString(){
            string str=_size + " "+ _type + " of " + _flavor + " " + _name+ ". Cost: $"+ to_string(_cost);
            return str;
        }//overrides flavor's toString function, and converts drink objects into a string line
};

#endif