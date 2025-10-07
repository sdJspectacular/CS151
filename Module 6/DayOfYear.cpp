// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   6
// HW:  6
// Project: 1
// Problem Statement: Days of the year
//
#include <iostream>
#include <string>
#include "DayOfYear.h"

using namespace std;

// 5. static constants which will assist in the conversion
//    from an integer to a month-day format, for example, a
//    collection of month names and days in each month.

int DayOfYear::months = 12;

string DayOfYear::monthNames[] = {"January", "February", "March",
                                  "April", "May", "June",
                                  "July", "August", "September",
                                  "October", "November", "December"};

// Might have been easier to state this as a cummulative array, e.g.: 31, 59, 90, ...
int DayOfYear::daysPerMonth[] = {
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31};

// prefix ++
DayOfYear &DayOfYear::operator++()
{
    dayNum = (dayNum + 1) % 365;
    return *this;
}

// postfix ++
DayOfYear DayOfYear::operator++(int)
{
    DayOfYear temp = *this;
    dayNum = (dayNum + 1) % 365;
    return temp;
}

// prefix --
DayOfYear &DayOfYear::operator--()
{
    if (--dayNum == 0)
        dayNum = 365;

    return *this;
}

// postfix --
DayOfYear DayOfYear::operator--(int)
{
    DayOfYear temp = *this;

    if (--dayNum == 0)
        dayNum = 365;

    return temp;
}

// 4. A friend function which overloads the stream insertion operator<<
//    to print the day in month-day format
ostream &operator<<(ostream &out, const DayOfYear &day)
{
    int i = 0;
    int totDays = DayOfYear::daysPerMonth[0];

    // Find out if current day is greater than cummulative number of
    // days for all past months
    while (day.dayNum > totDays)
    {
        totDays += DayOfYear::daysPerMonth[++i];
    }

    if (i > 0)
        totDays -= DayOfYear::daysPerMonth[i];

    // Output date as string
    out << DayOfYear::monthNames[i] << " ";
    if ((day.dayNum % totDays) == 0)
        out << day.dayNum;
    else
        out << (day.dayNum % totDays);

    return out;
}
