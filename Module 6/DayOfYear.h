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

#endif // _DAY_OF_YEAR_
