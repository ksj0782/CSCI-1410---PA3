//
// Created by Sungjoon Kim on 4/22/2019.
//

#ifndef PA3_FUNCTIONS_H
#define PA3_FUNCTIONS_H
#include "dealer.h"

void menuOption() //menu option function
{
    cout << "1. Read Dealers and Cars from a file." << endl
         << "2. Display Dealers." << endl
         << "3. Choose a Dealer Number, Display Cars." << endl
         << "4. Choose a Dealer Number, Add Car." << endl
         << "5. Choose a Dealer, Sort cars by VIN." << endl
         << "6. Write Dealers and Cars to file." << endl
         << "7. Exit." << endl;
    cout << "Choose a menu: ";
}

void ReadDealers(vector<Dealer> & dealers, ifstream & infile) //Functions definition for menu option 1
{
    if(!infile || !infile.is_open())
    {
        cout << "Error opening the file.\n";
        exit(-1);
    }

    Dealer tempDealer; // Call temporary "Dealer" class

    string tempDealerName;
    int tempDealerNumber;
    int tempNumberOfCars;
    //Temporary information of dealer

    string tempVIN;
    string tempMake;
    string tempModel;
    int tempYear;
    double tempPrice;
    //Temporary information of car


    while(!infile.eof())
    {
        Car DynamicCar; //Call temporary "Car" class

        getline(infile, tempDealerName);
        infile >> tempDealerNumber;
        infile >> tempNumberOfCars;
        infile.ignore();
        //Read information of a dealer from the file

        tempDealer.setDealerName(tempDealerName);
        tempDealer.setDealerNumber(tempDealerNumber);
        tempDealer.setNumberOfCars(tempNumberOfCars);
        //Set the values about dealer by using setters

        Car *cars = new Car [tempNumberOfCars];
        //Dynamic array pointer which will save information of cars

        for (int i = 0; i < tempNumberOfCars; i++) //'for' loop until read all the cars' information
        {
            getline(infile, tempVIN);
            getline(infile, tempMake);
            getline(infile, tempModel);
            infile >> tempYear;
            infile >> tempPrice;
            infile.ignore();
            //Read information of a car

            DynamicCar.setVIN(tempVIN);
            DynamicCar.setMake(tempMake);
            DynamicCar.setModel(tempModel);
            DynamicCar.setYear(tempYear);
            DynamicCar.setPrice(tempPrice);
            //Set the values about car by using setters

            cars[i] = DynamicCar;
            //Save the temporary "Car" class into dynamic array
        }

        tempDealer.setCarArrayPtr(cars);
        //Save the new dynamic array pointer by using setter

        dealers.push_back(tempDealer);
        //Append the temporary "Dealer" class, which has the information of cars now, into the vector from main function

    }
    cout << "Read Completely!" << endl;
}

void DisplayDealers(vector<Dealer> & dealers) //Functions definition for menu option 2
{
    if(dealers.empty())
    {
        cout << "Please read dealers and cars first!\n" << endl;
    }

    int size = dealers.size(); //The number of dealers
    for(int i = 0; i < size; i++) //Print out all dealers by using for loop
    {
        cout << "Dealer" << i+1 << ": " << dealers[i].getDealerName() << endl;
        cout << "Dealer Number: " << dealers[i].getDealerNumber() << endl;
        cout << "Number of Cars: " << dealers[i].getNumberOfCars() << endl << endl;
    }

}

void DisplayCars(vector<Dealer> & dealers) //Functions definition for menu option 3
{
    int dealerNum;
    int size = dealers.size();
    cout << "Choose a dealer number: ";
    cin >> dealerNum; //Get the dealer number from console



    for(int i = 0; i < size ;i++)
    {
        if(dealerNum == dealers[i].getDealerNumber())
        {
            auto cars = dealers[i].getCarArrayPtr(); //Give the pointer value to "cars"
            auto numberOfCars = dealers[i].getNumberOfCars(); //The number of cars

            cout << dealers[i].getDealerName() << " has" << endl;

            for(int j = 0; j < numberOfCars; j++)
            {
                cout << j+1 << ".";
                cout << " VIN Number: " << cars[j].getVIN() << endl;
                cout << "   Made by: " << cars[j].getMake() << endl;
                cout << "   Model: " << cars[j].getModel() << endl;
                cout << "   Year: " << cars[j].getYear() << endl;
                cout << "   Price: " << cars[j].getPrice() << endl;
            }
            //Print out cars' information by using the pointer and for loop
        }
    }
}

void AddCars(vector<Dealer> & dealers) //Function definition for menu option 4
{
    int dealerNum;
    int size = dealers.size();

    string tempVIN;
    string tempMake;
    string tempModel;
    int tempYear;
    double tempPrice;
    //Temporary information of cars

    for(int i = 0; i < size; i++)
    {
        cout << "Dealer" << i + 1 << ": " << dealers[i].getDealerName() << endl;
        cout << "Dealer Number: " << dealers[i].getDealerNumber() << endl;

    }
    //Print out dealers information

    cout << "Which dealer do you want to add a car? Please enter the number of the dealer: ";
    cin >> dealerNum; //Choose a dealer

    for(int i = 0; i < size ;i++)
    {
        if (dealerNum == dealers[i].getDealerNumber())
        {
            auto cars = dealers[i].getCarArrayPtr(); //Get the array pointer
            auto CarNum = dealers[i].getNumberOfCars(); //The number of cars


            Car DynAddCars; //Temporary "Car" class which will have the information of new car

            cout << "You are going to add a car." << endl;
            cout << "Please enter the information of the new car." << endl << endl;
            cin.ignore();

            cout << "What is the VIN number of the car?: ";
            getline(cin, tempVIN);
            //New car VIN number

            cout << "Which company made the car?: ";
            getline(cin, tempMake);
            //New car company

            cout << "What is the model of the car?: ";
            getline(cin, tempModel);
            //New car model

            cout << "When was the car made?: ";
            cin >> tempYear;
            //New car yaer

            cout << "How much is the car?: ";
            cin >> tempPrice;
            //New car price
            cin.ignore();

            DynAddCars.setVIN(tempVIN);
            DynAddCars.setMake(tempMake);
            DynAddCars.setModel(tempModel);
            DynAddCars.setYear(tempYear);
            DynAddCars.setPrice(tempPrice);
            //Set the values into the temporary "Car" class (DynAddCars) by using setters


            Car * AddCars = new Car[CarNum+1];
            //Make a new dynamic array which will have the information of both old cars and the new car
            //Size increases by 1 because one new car will be added

            for(int k = 0; k < CarNum ; k++)
            {
                AddCars[k] = cars[k];
            }
            //Add old cars

            AddCars[CarNum] = DynAddCars;
            //Add the new car

            dealers[i].setCarArrayPtr(AddCars); //Set the new array pointer
            dealers[i].setNumberOfCars(CarNum+1); //The number of cars increases by 1

        }
    }
}

void SortCars(vector<Dealer> & dealers) //Function definition for menu option 5
{
    int dealerNum;
    int size = dealers.size();
    cout << "Choose a dealer that you want to sort out. Enter the delaer number: ";
    cin >> dealerNum; //Choose a dealer


    for(int i = 0; i < size ; i++)
    {
        if(dealerNum == dealers[i].getDealerNumber())
        {
            auto cars = dealers[i].getCarArrayPtr(); //Get array pointer of cars
            auto size = dealers[i].getNumberOfCars();

            for (int j = 0; j < size; j++)
            {
                for (int k = j + 1; k < size; k++) {
                    if (cars[k].getVIN() < cars[j].getVIN())
                    {
                        auto temp = cars[k];
                        cars[k] = cars[j];
                        cars[j] = temp;
                    }
                    //Sort the cars' information depending on VIN numbers in ascending order
                }
            }

            dealers[i].setCarArrayPtr(cars); //Modify the array pointer because the order was changed
        }
    }

    cout << "Sorted completely." << endl;
}

void WriteDealers(vector<Dealer> & dealers, ofstream & outfile) //Function definition for menu option 6
{
    int size = dealers.size();

    for(int i = 0; i < size; i++)
    {
        outfile << dealers[i];
    }
    //Using "<<" operator which was newly defined
    //Write information of each dealer including cars into the file

    cout << "Wrote Completely." << endl;
}

#endif //PA3_FUNCTIONS_H
