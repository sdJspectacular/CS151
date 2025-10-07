#include <iostream>
#include <string>
#include "DayOfYear.h"

using namespace std;

int DayOfYear::months = 12;

string DayOfYear::monthNames[] = {"January", "February", "March",
                                  "April", "May", "June",
                                  "July", "August", "September",
                                  "October", "November", "December"};

int DayOfYear::daysPerMonth[] = {
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31};

//
ostream &operator<<(std::ostream &out, const DayOfYear &day)
{
    int remainingDay = day.dayNum;
    int monthIndex = 0;

    // Loop through the months to find which month the day falls into.
    for (size_t i = 0; i < DayOfYear::months; ++i)
    {
        const int daysInCurrentMonth = DayOfYear::daysPerMonth[i];

        if (remainingDay <= daysInCurrentMonth)
        {
            // The day falls in the current month (i).
            monthIndex = i;
            // The remainingDay value is now the day of the month.
            break;
        }
        else
        {
            // The day is after the current month, subtract days and check the next month.
            remainingDay -= daysInCurrentMonth;
        }
    }

    // Output the result in "Month Day_of_Month" format
    out << DayOfYear::monthNames[monthIndex] << " " << remainingDay;
    return out;
}
