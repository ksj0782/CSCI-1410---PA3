//
// Created by Sungjoon Kim on 4/22/2019.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <typeinfo>
#include "functions.h"
#include "dealer.h"

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;

    int menu = 0; //Menu option initialization

    bool menuBool = false;

    vector<Dealer> dealers; //Define a "Dealer" class object


    while(!menuBool) //while loop until "menuBool" changes to true
    {
        menuOption(); //Call "menuOption" function which prints out the menu options

        cin >> menu; //Choose a menu option

        switch (menu)
        {
            case 1: //When user chooses menu option 1
                    infile.open("Dealer.txt"); //Open the file that has information of dealers and cars
                    ReadDealers(dealers, infile); //Call "ReadDealers" function which reads information from the file
                    infile.close(); //Close the file after reading information
                break;

            case 2: //When user chooses menu option 2
                DisplayDealers(dealers); //Call "DisplayDealers" function which print out information of dealers
                break;

            case 3: //When user chooses menu option 3
                DisplayCars(dealers); //Call "DisplayCars" function which will print out information of cars of a dealer
                break;

            case 4: //When user chooses menu option 4
                AddCars(dealers); //Call "AddCars" function which will let user add cars
                break;

            case 5: //When user chooses menu option 5
                SortCars(dealers); //Call "SortCars" function which sorts out the cars depending on the VIN numbers in ascending order
                break;

            case 6: //When user chooses menu option 6
                outfile.open("Dealer_Output.txt"); //Open the file where information of dealers and cars will be written
                WriteDealers(dealers, outfile); //Call "WriteDealers" function which writes the information of dealers and cars into the file
                outfile.close(); //Close the file
                break;

            case 7: //When user chooses menu option 7
                menuBool = true; //Escape the while loop by changing "menuBool" value to true
                break;

            default:
            {
                cout << "*Wrong option* Please choose correct option number!" << endl;
            }
            break;
        }
    }


    return 0; //end the program by returning 0;
}