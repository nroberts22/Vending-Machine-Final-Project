#include "Drinks.h"
#include "Flavor.h"
#include "Snacks.h"
#include "Sweets.h"
#include "Vending.h"
#include "Payment.h"
#include <string>
#include <iostream>
#include <vector>
#include <math.h>


using namespace std;


void printMachine(vector<Vending*> VM){//prints out representation of vending machine of a max of 9 objects
    double test=VM.size();
    double rows=ceil(test/3);
    int count=0;
    
    for(int i=0;i<rows;i++){
        if(count==0||count==1||count==2)
        {
            cout<< "A:: ";
        }
        if(count==3||count==4||count==5){
            cout<< "B:: ";
        }
        if(count==6||count==7||count==8){
            cout<< "C:: ";
        }
        for(int z=0; z<3;z++){
            if(count<VM.size()){
                cout<< (z+1)<< ": "<<"["<< VM[count]->getName()<< "] ";
                count++;
            }
        }
        cout<< ""<< endl;
    }
    cout<<"Vending List: "<< endl;
    for(int q=0;q<VM.size();q++){
        cout<< VM[q];
    }

}

int main(){
    vector< Vending* > VM;
    Vending* mms=new Sweets("M&Ms", 1.75, "King Size");
    VM.push_back(mms);
    Vending* doritos=new Snacks("Doritos", 1.50, "Snack Size", "Nacho Cheese");
    VM.push_back(doritos);
    Vending* coke=new Drinks("Coke", 1.50, "16 oz", "Classic", "Bottle");
    VM.push_back(coke);
    Vending* pretzels=new Snacks("Pretzels", 1.50, "Snack Size", "Salted");
    VM.push_back(pretzels);


    bool check=false;
    printMachine(VM);
    // while(check==false){
        
    // }
    


    // string str=doritos->toString();
    // cout<< str<< endl;
    // cout<< doritos<< endl;

    // Payment p1(420.69);
    // p1.addValue(100.31);
    // cout<< p1.getValue()<< endl;
    // p1.deleteFile();
    // return 0;







}