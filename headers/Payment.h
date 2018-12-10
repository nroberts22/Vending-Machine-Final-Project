#ifndef PAYMENT_H_
#define PAYMENT_H_

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Payment{
    private: 
        fstream _file;

    public:
        Payment(double amount);
        void addValue(double value);
        double getValue();
        void deleteFile();



};

#endif