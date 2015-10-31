// BounSWE Airlines Reservation System
// Emre Bolat
// 2015719033
// ebolat@boun.edu.tr
// SWE501 - Project 2

#include "date.h"
#include <iostream>
#include <string>

class Flight
{
    string departureCity;
    string arrivalCity;
    int departureTime;
    int arrivalTime;
    Date departureDate;
    Date arrivalDate;

public:
    string flightNumber;
    bool longHaul;
    int capacity;
    int seatsLeft;
    double basePrice;

public:
    void createFlight();
    void cancelFlight();
    void showFlight();
};

void Flight::createFlight()
{
    int day;
    int month;
    int year;

    cout << "Enter departure city: " << endl;
    cin >> departureCity;
    cout << "Enter arrival city: " << endl;
    cin >> arrivalCity;

    cout << "Enter departure time(HH:MM) : " << endl;
    cin >> departureTime;
    cout << "Enter arrival time(HH:MM) : " << endl;
    cin >> arrivalTime;

    cout << "Enter departure date (dd.mm.yyy)" << endl;
    cout << "Departure day (dd) : " << endl;
    cin >> day;
    cout << "Departure month (mm) : " << endl;
    cin >> month;
    cout << "Departure year (yyyy) : " << endl;
    cin >> year;
    departureDate.make(day, month, year);

    cout << "Enter arrival date (dd.mm.yyy) : " << endl;
    cout << "Arrival day (dd) : " << endl;
    cin >> day;
    cout << "Arrival month (mm) : " << endl;
    cin >> month;
    cout << "Arrival year (yyyy) : " << endl;
    cin >> year;
    arrivalDate.make(day, month, year);

    cout << "Enter flight number (XY123): " << endl;
    cin >> flightNumber;

    string result;
    cout << "Is this flight long haul? (y/n)";
    cin >> result;
    if(result.compare("y")==0)
    {
        longHaul = true;
        capacity = 300;
        seatsLeft = capacity;
    }
    else
    {
        longHaul = false;
        capacity = 120;
        seatsLeft = capacity;
    }
    cout << "Enter base price for this flight (XXX.XX): " << endl;
    cin >> basePrice;
}

void Flight::showFlight()
{
    cout << "-----------------------------------" << endl;
    cout << departureCity << " to " << arrivalCity << endl;
    cout << "-----------------------------------" << endl;
    cout << "Departing at: " << departureTime << " " <<endl;
    departureDate.showDate();
    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "Arriving at: " << arrivalTime << " " << endl;
    arrivalDate.showDate();
    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Base Price: " << basePrice << endl;
    cout << seatsLeft << "/" << capacity << " seats left." << endl;
    cout << "-----------------------------------" << endl;

}
