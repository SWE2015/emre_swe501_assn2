// BounSWE Airlines Reservation System
// Emre Bolat
// 2015719033
// ebolat@boun.edu.tr
// SWE501 - Project 2

#include "passenger.h"
#include "flight.h"
#include <iostream>
#include <list>

list<Passenger> passengers;
list<Flight> flights;
list<Passenger>::iterator i;
list<Flight>::iterator j;

bool flightExist(string flightNumber)
{
    for(j=flights.begin(); j!=flights.end(); j++)
    {
        Flight flt = *j;
        if(flightNumber.compare(flt.flightNumber)==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool passengerExist(string passengerNumber)
{
    for(i=passengers.begin(); i!=passengers.end(); i++)
    {
        Passenger psg = *i;
        if (passengerNumber.compare(psg.passengerNumber)==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main() // main method!
{
     int response;
     cout << "==================================================" << endl;
     cout << "Welcome to BounSWE Airlines" << endl;
     while(response != 0)
     {
         string passengerNumber;
         string flightNumber;
         cout << "==================================================" << endl;
         cout << "Main Menu: " << endl;
         cout << "Please select options (1-7) or select (0) to exit." << endl;
         cout << endl;
         cout << "1. Create a new flight" << endl;
         cout << "2. Cancel an existing flight" << endl;
         cout << "3. See details of a flight" << endl;
         cout << "4. Create a new passenger" << endl;
         cout << "5. Book a passenger onto a flight" << endl;
         cout << "6. Show all reservations for a passenger" << endl;
         cout << "7. Cancel a passenger's reservation" << endl;
         cout << "0. EXIT" << endl;
         cout << "==================================================" << endl;

         cin >> response;
         switch(response)
         {
             case 1:
                 {
                     Flight f;
                     f.createFlight();
                     flights.push_back(f);
                     break;
                 }
             case 2:
                 {
                     cout << "Enter flight number (XY123) : ";
                     cin >> flightNumber;
                     if(flightExist(flightNumber))
                     {
                         j = flights.erase(j);
                         cout << "Flight number " << flightNumber << " has been removed." << endl;
                     }
                     else
                     {
                         cout << "Flight " << flightNumber << " not found." << endl;
                     }
                     break;
                 }
             case 3:
                {
                     cout << "Enter flight number (XY123) : ";
                     cin >> flightNumber;
                     if(flightExist(flightNumber))
                     {
                         Flight flt = *j;
                         flt.showFlight();
                     }
                     else
                     {
                         cout << "Flight " << flightNumber << " not found." << endl;
                     }
                     break;
                }
             case 4:
                {
                    Passenger p; // Takes the passenger information and saves it to a list.
                    p.getInfo();
                    passengers.push_back(p);
                    break;
                }
             case 5:
                {
                    cout << "Enter passenger number (A123) : ";
                    cin >> passengerNumber;
                    cout << "Enter flight number (XY123) : ";
                    cin >> flightNumber;
                    if(passengerExist(passengerNumber)) // Checks if passenger exist.
                    {
                        if (flightExist(flightNumber)) // Checks if flight exist.
                        {
                            Passenger p = *i;
                            Flight f = *j;
                            if(f.longHaul && f.seatsLeft>0) // Checks if requirements are met.
                            {
                                p.makeReservation(flightNumber,f.longHaul,f.basePrice);
                                f.seatsLeft--; // Available seats decreased 1.
                                *i = p; // Update lists.
                                *j = f;
                            }
                            else if(f.seatsLeft>0) // For short haul flights.
                            {
                                p.makeReservation(flightNumber,f.longHaul,f.basePrice);
                                f.seatsLeft--;
                                *i =p;
                                *j=f;
                            }
                            else
                            {
                                cout << "Flight is full!" << endl;
                            }
                        }
                        else
                        {
                           cout << "Flight " << flightNumber << " is not found." << endl;
                        }
                    }
                    else
                    {
                        cout << "Passenger with passenger number: " << passengerNumber << " is not found." << endl;
                    }
                    break;
                }
             case 6:
                {
                    cout << "Enter passenger number (A123): ";
                    cin >> passengerNumber;
                    if (passengerExist(passengerNumber))
                    {
                        Passenger p = *i;
                        p.printInfo();
                    }
                    else
                    {
                        cout << "Passenger with passenger number: " << passengerNumber << "not found." << endl;
                    }
                    break;
                }
             case 7:
                 {
                     cout << "Enter passenger number (A123): ";
                     cin >> passengerNumber;
                     cout << "Enter flight number (XY123) : ";
                     cin >> flightNumber;
                     if(passengerExist(passengerNumber))
                     {
                         if(flightExist(flightNumber))
                         {
                             Passenger p = *i;
                             Flight f = *j;
                             p.cancelReservation(flightNumber);
                             f.seatsLeft++; // Available seats increase 1 after a reservation cancel.
                         }
                         else
                         {
                             cout << "Flight number: " << flightNumber << " is not found." << endl;
                         }
                     }
                     else
                     {
                         cout << "Passenger number: " << passengerNumber << " is not found." << endl;
                     }
                     break;
                 }
         }
     }
     return 0;
}
