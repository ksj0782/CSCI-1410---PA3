//
// Created by Sungjoon Kim on 4/22/2019.
//

#ifndef PA3_DEALER_H
#define PA3_DEALER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Car //Car class
{
private:
    string VIN; //VIN number
    string make; //Car company
    string model; //Car model
    int year; //Year when the car was made
    double price; //Car price

public:
    Car(); //Constructor prototype
    Car(string vVin, string vMake, string vModel, int vYear, double vPrice); //Constructor prototype
    string getVIN(){return VIN;} //VIN getter
    string getMake(){return make;} //Make getter
    string getModel(){return model;} //Model getter
    int getYear(){return year;} //Year getter
    double getPrice(){return price;} //Price getter
    void setVIN(string _VIN){VIN = _VIN;} //VIN setter
    void setMake(string _make){make = _make;} //Make setter
    void setModel(string _model){model = _model;} //Model setter
    void setYear(int _year){year = _year;} //Year getter
    void setPrice(double _price){price = _price;} //Price getter

};

class Dealer //Dealer class
{
private:
    string dealerName; //Dealer name
    int dealerNumber; //Dealer number
    int numberOfCars; //Number of cars
    Car *carArrayPtr; // Array pointer of "Car" class

public:
    Dealer(); //Constructor prototype
    Dealer(string dName, int dNumber, int dNumCars); //Constructor prototype
    void setDealerName (string _dealerName){dealerName = _dealerName;} //Dealer name setter
    void setDealerNumber (int _dealerNumber){dealerNumber = _dealerNumber;} //Dealer number setter
    void setCarArrayPtr (Car *_carArrayPtr){carArrayPtr = _carArrayPtr;} //"Car" class array pointer setter
    void setNumberOfCars(int _numberOfCars) {numberOfCars = _numberOfCars;} //Number of cars setter
    string getDealerName() {return dealerName;} //Dealer name getter
    int getDealerNumber() {return dealerNumber;} //Dealer number getter
    int getNumberOfCars() {return numberOfCars;} //Number of cars getter
    Car * getCarArrayPtr(){return carArrayPtr;} //"Car" class array pointer getter

    friend ostream & operator << (ostream &out, Dealer _dealer); //Prototype of the function that gives new definition to "<<" operator
};

#endif //PA3_DEALER_H
