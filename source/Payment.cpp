#include "Payment.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

Payment::Payment(double amount){//creates payment object with specified amount: payment object functions like a debit card
    _file.open("_file.txt", ios::out);
    _file<< amount;
    _file.close();
}   

void Payment::addValue(double value){// adds value to the file
    _file.open("_file.txt", ios::in);
    double amount;
    _file>>amount;
    _file.close();
    value+=amount;
    _file.open("_file.txt", ios::out);
    _file<< value;
    _file.close();
}

void Payment::subtractValue(double value){//subtracts value from the file
    _file.open("_file.txt", ios::in);
    double amount;
    _file>>amount;
    _file.close();
    value=amount-value;
    _file.open("_file.txt", ios::out);
    _file<< value;
    _file.close();
}

double Payment::getValue(){//gets value from the file
    _file.open("_file.txt", ios::in);
    double value;
    _file>>value;
    _file.close();
    return value;
}

void Payment::deleteFile(){//deletes the payment method
    remove("_file.txt");
}