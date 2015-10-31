// BounSWE Airlines Reservation System
// Emre Bolat
// 2015719033
// ebolat@boun.edu.tr
// SWE501 - Project 2

#include <iostream>
#include <string>
using namespace std;

class Reservation
{
public:
    string flightNumber; // The Number of Flight (AB123)
    string seatPosition; // Hallway(aisle), middle or window
    bool businessclass; // True if Business Class, false if not.
    int bags;
    double price;

public:
        void makeReservation(string flightNumber, bool longHaul, double basePrice); // Method for reservation details.
        void showReservation(); // Method for showing reservation details.
};

void Reservation::makeReservation(string flightNumber, bool longHaul, double basePrice)
{
    if(longHaul)
    {
        string response;
        cout << "Would you like to fly in business class? (y/n)";
        cin >> response;

        if (response.compare("y")==0)
        {
            businessclass = true;
        }
        else
        {
            businessclass = false;
        }

        if (businessclass)
        {
            cout << "Would you like a hallway (aisle) or window sit? (hallway/window)";
            cin >> seatPosition;
            price = basePrice*2;
            bags = 3;
        }
        else
        {
            cout << "Would you like a hallway (aisle), middle or window sit? (hallway/middle/window)";
            cin >> seatPosition;
            cout << "Your first bag is free of charge. Would you like to carry more bags for 80TL/each? (0-2)";
            cin >> bags;
            price = basePrice + bags*80; // We are charging 50TL for each extra bag.
            cout << "Flight " << flightNumber << " is booked." << endl;
        }
    }

    else
        {
            cout << "Would you like a hallway (aisle), middle or window seat? (hallway/middle/window)";
            cin >> seatPosition;
            cout << "Would you like to carry some bags for 30TL/each? (x)";
            cin >> bags;
            price = basePrice + bags*30;
            cout << "Flight " << flightNumber << " is booked."<<endl;
            businessclass = false;
        }
}

void Reservation::showReservation()
{
    cout << "===================================" << endl;
    cout << "BounSWE Airlines Reservation Status" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Seat Position: " << seatPosition << endl;
    if(businessclass)
    {
        cout << "Business Class: Yes";
    }
    else
    {
        cout << "Business Class: No";
    }
    cout << endl;
    cout << "Bags: " << bags << endl;
    cout << "Price: " << price << "TL" << endl;
    cout << "===================================" << endl;
}
