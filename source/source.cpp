#include "Drinks.h"
#include "Flavor.h"
#include "Snacks.h"
#include "Sweets.h"
#include "Vending.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector< Vending* > VM;
    Vending* mms=new Sweets("M&Ms", 1.75, "King Size");
    VM.push_back(mms);
    Vending* doritos=new Snacks("Doritos", 1.50, "Snack Size", "Nacho Cheese");
    VM.push_back(doritos);
    Vending* coke=new Drinks("Coke", 1.50, "16 oz", "Classic", "Bottle");
    VM.push_back(coke);


    string str=doritos->toString();
    cout<< str<< endl;
    cout<< doritos<< endl;
    return 0;
}