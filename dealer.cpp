//
// Created by Sungjoon Kim on 4/22/2019.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "dealer.h"

using namespace std;

Dealer::Dealer() //Dealer class constructor definition
{
    dealerName = "";
    dealerNumber = 0;
    numberOfCars = 0;
    carArrayPtr = nullptr;
}

Dealer::Dealer(string dName, int dNumber, int dNumCars) //Dealer class constructor definition
{
    dealerName = dName;
    dealerNumber = dNumber;
    numberOfCars = dNumCars;
}


Car::Car() //Car class construction
{
    VIN = "";
    make = "";
    model = "";
    year = 0;
    price = 0;
}

Car::Car(string vVin, string vMake, string vModel, int vYear, double vPrice) //Car class construction
{
    VIN = vVin;
    make = vMake;
    model = vModel;
    year = vYear;
    price = vPrice;
}

ostream & operator << (ostream &out, Dealer _dealer) //Operator "<<" definition with "Dealer" class
{
    auto carPtr = _dealer.getCarArrayPtr(); //"carPtr" gets the array pointer of "Dealer" class, which has information about cars

    out << "Dealer: " << _dealer.dealerName << endl;
    out << "Dealer Number: " << _dealer.dealerNumber << endl;
    out << "Number of Cars: " << _dealer.numberOfCars << endl << endl;
    //Print or write out the information about the dealer into screen or a file

    for(int i = 0; i < _dealer.numberOfCars; i++)
    {
        out << "VIN: " << carPtr[i].getVIN() << endl;
        out << "Make: " << carPtr[i].getMake() << endl;
        out << "Model: " << carPtr[i].getModel() << endl;
        out << "Year: " << carPtr[i].getYear() << endl;
        out << "Price: " << carPtr[i].getPrice() << endl << endl;
    }
    //By using the array pointer or cars. print or write out the information about the cars into screen or a file

    return out;
}

