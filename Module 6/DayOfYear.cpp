#ifndef _DAY_OF_YEAR_
#define _DAY_OF_YEAR_
#include <iostream>
#include <string>

using namespace std;

class DayOfYear
{
private:
    int dayNum; // 1 - 365

    //
    static string monthNames[];
    static int daysPerMonth[];
    static int months;

public:
    // Constructor
    DayOfYear(int day) : dayNum(day)
    {
        // Check for valid day
        if ((dayNum < 1) || (dayNum > 365))
        {
            cout << "Invalid day of year error\n";
            exit(1);
        }
    }

    // Accessor function
    int getDayNum() const
    {
        return dayNum;
    }

    // operator<<
    friend std::ostream &operator<<(std::ostream &, const DayOfYear &);
};

int months = 12;

string monthNames[] = {"January", "February", "March",
                                  "April", "May", "June",
                                  "July", "August", "September",
                                  "October", "November", "December"};

int daysPerMonth[] = {
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

#endif // _DAY_OF_YEAR_
