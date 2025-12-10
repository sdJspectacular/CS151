/* OverloadedOperators.cpp - Overloaded operator problem in midterm
 * Author:     <your name>
 * Module:     10
 * Project:    Problem 5
 * Problem statement: Complete the Time class by providing a
 *    definition for several functions and operators.
 *
 * Algorithm:
 *   1. For the first constructor, provide an initialization list for
 *      the two data members (hours and minutes)
 *   2  Also provide a copy constructor which copies both data members
 *   3. For the two getters, provide an in-line assignment statement
 *   4. For the three overloaded operators (=, postfix ++,  and <<) provide
 *      a definition outside of the class which allows main to work properly
 */

#include <iostream>
#include <sstream>
using namespace std;

class Time
{

private:
    int hours,   // hours from 0 - 23
        minutes; // minutes from 0 - 59

public:
    // These three functions should be defined inside the Time class
    // (fill in the dots)
    Time(int hours, int minutes)
    {
        this->hours = hours;
        this->minutes = minutes;
    }
    
    int getHours() const
    {
        return hours;
    }
    int getMinutes() const
    {
        return minutes;
    }

    // These functions and operators should be defined outside of the Time class
    // The copy constructor (fill in the dots and complete the function)
    Time(const Time &rhs);

    // The overloaded = operator (assignment operator)
    Time &operator=(const Time &rhs);

    // The postfix overloaded ++ operator must support rolling over of hours
    // and minutes
    Time operator++(int); // dummy argument for postfix

    // The overloaded << operator must be a friend and return a pointer to
    // the ostream item to support cascading
    friend ostream &operator<<(ostream &out, const Time &time);
};

// The copy constructor
Time::Time(const Time &rhs)
{
    hours = rhs.hours;
    minutes = rhs.minutes;
}

// The overloaded assignment operator
Time &Time::operator=(const Time &rhs)
{
    if (this != &rhs)
    {
        hours = rhs.hours;
        minutes = rhs.minutes;
    }

    return *this;
}

// The overloaded postfix ++ operator
Time Time::operator++(int)
{
    Time temp = *this;
    minutes++;

    if (minutes == 60)
    {
        minutes %= 60;
        hours += 1;
    }

    if (hours == 24)
    {
        hours %= 24;
    }

    return temp; // old value
}

// The overloaded << operator
ostream &operator<<(ostream &out, const Time &time)
{
    out << time.hours << ":";

    if (time.minutes < 10)
        out << "0" ;

    out << time.minutes ;

    return out ;
}

int main()
{

    // This version of main should work "as-is" (please do not change this code)

    // When did I have to get up this morning?
    Time wake_up(6, 30);
    cout << "When did I wake up?         " << wake_up << endl
         << endl;
    cout << "The hour was:               " << wake_up.getHours() << endl;
    cout << "And the minutes:            " << wake_up.getMinutes() << endl;

    // What was the time one hour later?
    Time start_work(0, 0);
    start_work = wake_up;
    for (int i = 1; i <= 60; i++)
    {
        start_work++;
    }
    cout << "Time to start working:      " << start_work << endl
         << endl;

    // One minute before the midnight starts (11:59pm)
    Time before_midnight(23, 59);
    cout << "One minute before midnight: " << before_midnight++ << endl;
    cout << "And the next day starts at: " << before_midnight << endl;

    return 0;
}
