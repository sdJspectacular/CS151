#ifndef _TIMEDATE_
#define _TIMEDATE_

#include <iostream>
#include <string>
using namespace std;

// 1. Create a new C++ project or repl, then create a class named  TimeDate
// with the following four private instance members, consisting of three ints
// and one string
class TimeDate
{
private:
    int hour, minute, day;
    string month;

public:
    // 2. Inside the  TimeDate  class, create a constructor which uses member lists to
    // initialize each of the five instance members of the class:
    TimeDate(int hr, int min, int dday, string mon) : hour(hr), minute(min), day(dday), month(mon) {}

    // 3. Also in the  Timedate  class, create a function which returns the  TimeDate  as a string
    string getTimeDate()
    {
        string print_hour = to_string(hour);
        string am_pm = (hour < 12 ? "am" : "pm");
        if (hour == 0)
          print_hour = "12" ;
        else if (hour > 12)
            print_hour = to_string(hour - 12);

        return month + " " + to_string(day) +
               " at " + print_hour + ":" +
               (minute < 10 ? "0" : "") + to_string(minute) + am_pm;
    }
};

#endif // _TIMEDATE_
