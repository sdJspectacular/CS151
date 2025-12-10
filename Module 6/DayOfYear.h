// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   6
// HW:  6
// Project: 1
// Problem Statement: Days of the year
//
#ifndef _DAY_OF_YEAR_
#define _DAY_OF_YEAR_

#include <iostream>
#include <string>

using namespace std;

// Takes an interger representing day number and translates it
// into a string consisting of the month followed by the day of
// the month
class DayOfYear
{
private:
    // 2. a private integer member variable to store the parameter
    int dayNum; // 1 - 365

    // 5. static constants which will assist in the conversion
    // from an integer to a month-day format, for example, a
    // collection of month names and days in each month.
    static string monthNames[];
    static int daysPerMonth[];
    static int months;

public:
    // 1. a constructor for the class which takes as a
    // parameter an integer representing the day number
    // of the year
    DayOfYear(int day) : dayNum(day)
    {
        // Check for valid day
        if ((dayNum < 1) || (dayNum > 365))
        {
            cout << "ERROR: Invalid day of year.\n";
            exit(1);
        }
    }

    // a second constructor that takes two parameters:
    // - a string representing a month name
    // - an integer in the range 1 through 31 representing the day of the month
    // - handle error cases of bad month/day inputs
    DayOfYear(string mon, int day)
    {
        int i = 0;
        int totDays = 0;

        // Find the month
        do
        {
            // Handle bad months
            if (i == DayOfYear::months)
            {
                cout << "ERROR: Invalid month of " << mon << "\n\n";
                exit(1);
            }

            // break when the month is found
            if (mon == DayOfYear::monthNames[i])
                break;
        } while (i++ < DayOfYear::months);

        // Handle bad day number
        if (day > DayOfYear::daysPerMonth[i])
        {
            cout << "ERROR: " << day << " days invalid for the month of " << mon << "\n\n";
            exit(1);
        }

        // Cummulative sum of days starting at current month
        for (int k = 0; k < i; ++k)
        {
            totDays += DayOfYear::daysPerMonth[k];
        }

        cout << "Creating date: " << mon << " " << day << "\n";
        dayNum = totDays + day;
    }

    // 3. a "getter" to return the value of the member variable
    int getDayNum() const
    {
        return dayNum;
    }

    // prefix and postfix ++ (increment) operators
    DayOfYear &operator++();    // prefix
    DayOfYear operator++(int); // postfix

    // prefix and posfix -- (decrement) operators
    DayOfYear &operator--();    // prefix
    DayOfYear operator--(int); // postfix

    // 4. the header of a "friend" function which overloads the
    // stream insertion operator ( << ) to print the day in month-day
    // format
    friend ostream &operator<<(ostream &, const DayOfYear &);
};

#endif // _DAY_OF_YEAR_
