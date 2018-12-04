#include <iostream>
#include <string>
#include "Vending.h"

using namespace std;
    
    Vending::Vending(string name, double cost, string size){ //creates a vending object with the specified values
        _name=name;
        _cost=cost;
        _size=size;
    }
    string Vending::getName(){//returns name
        return _name;
    }
    double Vending::getCost(){//returns cost
        return _cost;
    }
    string Vending::getSize(){//returns size
        return _size;
    }
    void vend();
    void readPayment();
    void createPayment();