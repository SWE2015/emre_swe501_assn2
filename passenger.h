// BounSWE Airlines Reservation System
// Emre Bolat
// 2015719033
// ebolat@boun.edu.tr
// SWE501 - Project 2

#include "reservation.h"
#include <iostream>
#include <string>
#include <list>

class Passenger
{
    string name;
    string contactInfo;

public:
    string passengerNumber; // Unique 4-digit number (A123)
    list<Reservation> reservations; // A list for passenger's reservations
    list<Reservation>::iterator i;

public:
    void getInfo();
    void makeReservation(string flightNumber, bool longHaul, double basePrice);
    void cancelReservation(string flightNumber); // Business class passengers can cancel their reservations.
    void printInfo();
};

void Passenger::getInfo()
{
    cout << "Enter passenger name: " << endl;
    cin >> name;
    cout << "Enter passengers contact number: " << endl;
    cin >> contactInfo;
    cout << "Enter passenger number (A123) : " << endl;
    cin >> passengerNumber;
}

void Passenger::makeReservation(string flightNumber, bool longHaul, double basePrice)
{
    Reservation r;
    r.makeReservation(flightNumber,longHaul,basePrice);
    reservations.push_back(r);
}

void Passenger::cancelReservation(string flightNumber)
{
	for(i = reservations.begin();i!=reservations.end();i++)
	{
		Reservation r = *i;
		if(r.flightNumber.compare(flightNumber)==0)
		{
			if(r.businessclass)
            {
                cout << "Flight Canceled, " << r.price << "TL refunded." << endl;
            }
			else
            {
                cout<<"Flight Canceled" << endl;
            }
			i=reservations.erase(i);

			break;
		}
	}
}

void Passenger::printInfo()
{
    cout << "===================================" << endl;
    cout << "BounSWE Airlines Passenger Status" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Contact: " << contactInfo << endl;
    cout << "-----------------------------------" << endl;
    cout << "Reservation Details" << endl;
    for(i = reservations.begin();i!=reservations.end();i++)
	{
		Reservation r = *i;
		r.showReservation();
	}
	cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "===================================" << endl;
}
