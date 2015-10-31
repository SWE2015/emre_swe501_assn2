// BounSWE Airlines Reservation System
// Emre Bolat
// 2015719033
// ebolat@boun.edu.tr
// SWE501 - Project 2

#include <iostream>

class Date
{
    int day;
    int month;
    int year;

public:
    void make(int,int,int);
    bool lessThan24(Date);
    void showDate();
};

void Date::make(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date::showDate()
{
    cout << day << "." << month << "." << year; // Format of the date (dd.mm.yyyy)
}
