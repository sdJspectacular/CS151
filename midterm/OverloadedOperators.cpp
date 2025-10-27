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
using namespace std ;

class Time {

    private:
        int hours,                    // hours from 0 - 23
            minutes ;                 // minutes from 0 - 59

    public:
        // These three functions should be defined inside the Time class
        // (fill in the dots)
        Time(int hours, int minutes) ...
            { }
        int getHours() const
            { ... }
        int getMinutes() const
            { ... }

        // These functions and operators should be defined outside of the Time class
        // The copy constructor (fill in the dots and complete the function)
        Time( ... )

        // The overloaded = operator (assignment operator)
        Time & operator=( ... )

        // The postfix overloaded ++ operator must support rolling over of hours
        // and minutes
        Time ...

        // The overloaded << operator must be a friend and return a pointer to
        // the ostream item to support cascading
        friend ...
} ;

// The copy constructor

// The overloaded assignment operator

// The overloaded postfix ++ operator

// The overloaded << operator

int main() {

    // This version of main should work "as-is" (please do not change this code)

    // When did I have to get up this morning?
    Time wake_up(6, 30) ;
    cout << "When did I wake up?         " << wake_up << endl << endl ;
    cout << "The hour was:               " << wake_up.getHours() << endl ;
    cout << "And the minutes:            " << wake_up.getMinutes() << endl ;

    // What was the time one hour later?
    Time start_work(0, 0) ;
    start_work = wake_up ;
    for (int i = 1 ; i <= 60 ; i++) {
        start_work++ ;
    }
    cout << "Time to start working:      " << start_work << endl << endl ;

    // One minute before the midnight starts (11:59pm)
    Time before_midnight(23, 59) ;
    cout << "One minute before midnight: " << before_midnight++ << endl ;
    cout << "And the next day starts at: " << before_midnight << endl ;

    return 0 ;
}
