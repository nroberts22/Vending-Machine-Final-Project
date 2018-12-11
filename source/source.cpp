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
    double rows=ceil(test/3);//finds row amount by rounding up after dividing by 3
    int count=0;
    cout<< ""<< endl;
    cout<< "Nik's Dynamic Vending Machine"<< endl;
    cout<< ""<< endl;
    for(int i=0;i<rows;i++){//checks what the prefix should be based off of order(first 3 are a, second 3 are b, third 3 are c)
        if(count==0||count==1||count==2)
        {
            cout<< "A) ";
        }
        if(count==3||count==4||count==5){
            cout<< "B) ";
        }
        if(count==6||count==7||count==8){
            cout<< "C) ";
        }
        for(int z=0; z<3;z++){//prints out names
            if(count<VM.size()){
                cout<< (z+1)<< ": "<<"["<< VM[count]->getName()<< "] ";
                count++;
            }
        }
        cout<< ""<< endl;
    }
    cout<< ""<< endl;
    cout<<"Vending List: "<< endl;
    for(int q=0;q<VM.size();q++){//checks what the prefix should be (same as above)
        if(q==0||q==1||q==2)
        {
            cout<< "A"<< (q+1)<<": ";
        }
        if(q==3||q==4||q==5){
            cout<< "B"<<(q-2)<<": ";
        }
        if(q==6||q==7||q==8){
            cout<< "C"<<(q-5)<<": ";
        }//prints out full description of each vending object to let the user know the price and any additional info such as flavor
        cout<< VM[q];
    }
    cout<< ""<< endl;
}

void runMachine(vector<Vending*> VM){// runs the Vending machine
    bool check=false;
    cout<< "Welcome to Nik's Dynamic Vending Machine! "<< endl;
    double value;
    cout<< "How much money would you like on your Vending Card(In Dollars)? You can use this card to purchase Vending objects. ";
    cin>>value;
    if(value>0){//checks the user input for a positive value
        cout<< "Your card balance is $"<< value<< endl;
    }
    else{
        cout<< "Invalid Input"<< endl;
        check=true;
    }
    Payment p1(value);//creates a payment object to keep track of the user's "card"
    while(check==false && VM.size()>0){
        char charCheck;
        cout<< "If you would like to continue, please type y, otherwise type any other key: ";
        cin>> charCheck;
        if(charCheck=='y'||charCheck=='Y'){//entry answer to be able to continue to use vending machine
            printMachine(VM);
            char row;//keeps track of the row
            int number;//keeps track of the number part of the index ie. A{1}
            int buyValue;//index of vending machine used to search through vector
            cout<< "What would you like to buy?(ex. 'A1'): " << endl;
            cin>>row;
            cin>>number;
            if(number>3||number<1){//checks if the number is valid, otherwise breaks out of loop
                cout<< "Invalid Input"<< endl;
                break;
            }
            if(row=='a'||row=='A'){//checks if the row value is valid, otherwise breaks out of loop
                buyValue=number-1;
            }else if(row=='b'||row=='B'){
                buyValue=number+2;
            } else if(row=='c'||row=='C'){
                buyValue=number+5;
            }else {
                cout<< "Invalid Input"<< endl;
                break;
            }
            double cost=VM[buyValue]->getCost();
            if(cost<p1.getValue()){//checks if there is enough value on card to purchase vending object
                p1.subtractValue(cost);//charges the card for the object
                cout<< "Here is your item: " << VM[buyValue]->getName()<< endl;
                VM.erase(VM.begin()+buyValue);//deletes vending object from vector
                cout<< "You have $"<< p1.getValue()<< " left on your card"<< endl;//prints out balance left on card
            }
            else{
                cout<< "Sorry, you do not have enough value on your card to purchase this item"<< endl;
            }
        }
        else{
            check=true;
        }
    }
    p1.deleteFile();
    cout<< "Thank you for visiting Nik's Dynamic Vending Machine!"<< endl;
}

int main(){
    // Vending object pointers
    vector< Vending* > VM;
    Vending* mms=new Sweets("M&Ms", 1.75, "King Size");
    VM.push_back(mms);
    Vending* doritos=new Snacks("Doritos", 1.50, "Snack Size", "Nacho Cheese");
    VM.push_back(doritos);
    Vending* coke=new Drinks("Coke", 1.50, "16 oz", "Classic", "Bottle");
    VM.push_back(coke);
    Vending* pretzels=new Snacks("Pretzels", 1.50, "Snack Size", "Salted");
    VM.push_back(pretzels);
    Vending* juicyFruit=new Sweets("Juicy Fruit", 1.00, "5 Pack");
    VM.push_back(juicyFruit);
    Vending* drPepper=new Drinks("Dr.Pepper", 1.50, "16 oz", "Cherry", "Can");
    VM.push_back(drPepper);
    Vending* chexMix=new Snacks("Chex Mix", 2.00, "Snack Size", "Bold");
    VM.push_back(chexMix);
    Vending* snickers=new Sweets("Snickers", 1.25, "Regular Size");
    VM.push_back(snickers);
    Vending* trailMix=new Snacks("Trail Mix", 1.50, "Share Size", "Classic");
    VM.push_back(trailMix);
    

    runMachine(VM);//calls run function
    return 0;
}