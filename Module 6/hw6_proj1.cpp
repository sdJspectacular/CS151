// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   6
// HW:  6
// Project: 1
// Problem Statement: Days of the year
//
// Algorithm:
//   1. Write DayOfYear class with two constructors
//      - one that takes a number
//      - one that takes a string and a number
//   2. Demonstrate both constructors with arrays of days
//   3. Demonstrate prefix -- operator
//   4. Demonstrate prefix ++ operator
//   5. Demonstrate postfix -- operator
//   6. Demonstrate postfix ++ operator
//   7. Demonstrate error handling for a bad date
//
#include <iostream>
#include "DayOfYear.h"

using namespace std;

int main()
{
    const int NDAYS = 5;
    // Demonstrate the DayOfYear class by writing a main function which
    // uses the first constructor to show the appropriate month-day dates
    // for days numbered 15, 31, 59, 180, and 360.  E.G., pass "15" to
    // the constructor that takes a number and show the month and day
    // number ("January 15").
    DayOfYear days[NDAYS] = {DayOfYear(15), DayOfYear(31), DayOfYear(59), DayOfYear(180), DayOfYear(360)};

    for (auto day : days)
    {
        cout << day << "\n";
    }
    cout << "\n";

    // demonstrate the second constructor by displaying the appropriate day number
    // for "January 1", "March 4", "July 25", and "December 31".  E.G., pass
    // "January" and "1" to the constructor that takes a string and an int, then show
    // the resulting day number (1).
    DayOfYear days2[NDAYS] = {DayOfYear("January", 1),
                              DayOfYear("March", 4),
                              DayOfYear("July", 25),
                              DayOfYear("December", 31),
                              DayOfYear("November", 2)};
                            
    for (auto day : days2)
    {
        cout << day << "\n";
    }
    cout << "\n";

    // Create an object with day number 1 (January 1).  Demonstrate how the prefix-- operator works.
    // Use separate cout statements to show the original value of the object (in month-day format),
    // the object using the prefix -- operator, and the final value of the object on three separate lines.
    DayOfYear day3(1);
    cout << "Using January 1 (day 1):\n";
    cout << "The original value: " << day3 << "\n";
    cout << "Using prefix--    : " << --day3 << "\n";
    cout << "After prefix--    : " << day3 << "\n";
    cout << "\n";

    // Demonstrate how the prefix ++ operator works on the object created using the second date above (March 4).
    cout << "Using March 4 (day 63):\n";
    cout << "The original value: " << days2[1] << "\n";
    cout << "Using prefix++    : " << ++days2[1] << "\n";
    cout << "After prefix++    : " << days2[1] << "\n";
    cout << "\n";

    // Also demonstrate how the postfix version of the  --  and  ++  operators work by doing the
    // same thing on the third (July 25) and fourth (December 31) objects above
    cout << "Using July 25 (day 206):\n";
    cout << "The original value: " << days2[2] << "\n";
    cout << "Using postfix--   : " << days2[2]-- << "\n";
    cout << "After postfix--   : " << days2[2] << "\n";
    cout << "\n";

    cout << "Using December 31 (day 365):\n";
    cout << "The original value: " << days2[3] << "\n";
    cout << "Using postfix++   : " << days2[3]++ << "\n";
    cout << "After postfix++   : " << days2[3] << "\n";
    cout << "\n";

    // Demonstrate what happens when an invalid month/day combination is entered using the
    // second constructor
    DayOfYear badDay("February", 30);
    cout << "\n";

    return 0;
}