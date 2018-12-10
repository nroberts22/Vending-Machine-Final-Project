#include "Payment.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

Payment::Payment(double amount){
    _file.open("_file.txt", ios::out);
    _file<< amount;
    _file.close();
}   

void Payment::addValue(double value){
    _file.open("_file.txt", ios::in);
    double amount;
    _file>>amount;
    _file.close();
    value+=amount;
    _file.open("_file.txt", ios::out);
    _file<< value;
    _file.close();
}

double Payment::getValue(){
    _file.open("_file.txt", ios::in);
    double value;
    _file>>value;
    _file.close();
    return value;
}

void Payment::deleteFile(){
    remove("_file.txt");

}