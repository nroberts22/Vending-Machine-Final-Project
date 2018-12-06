#ifndef VENDING_H_
#define VENDING_H_

#include <string>
#include <iostream>

using namespace std;

class Vending{
    protected:  
    // vending object variables
        string _name;
        double _cost;
        string _size;
    
    public:
        Vending(string name, double cost, string size);
        string getName();
        double getCost();
        string getSize();
        virtual string toString()=0;
        void vend();
        void readPayment();
        void createPayment();

};


#endif