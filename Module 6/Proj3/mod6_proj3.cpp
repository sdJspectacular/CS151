// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   6
// Lab:  6
// Project: 3
// Problem Statement: Composition Object Demonstration
//
// Algorithm:
//   1. Create a TimeDate class
//   2. Create an Event class that uses TimeDate objects
//   3. Give two examples of TimeDate objects being used indirectly
//      through the Event object, with their lifetime being limited by composition
//
#include <iostream>
#include "Event.cpp" // Only including Event because this is an example of composition
                     // Note that there is no TimeDate class included in this file

using namespace std;

int main()
{
    // 6. In  main, create two events ...
    Event party(17, 30, 14, "Oct.", 20, 30, 14, "Oct.", "My Birthday Party");
    Event cs151Final(10, 0, 12, "Dec.", 13, 0, 12, "Dec.", "CS 151 final examination");

    // ... and print
    cout << party.getEvent() << "\n\n";
    cout << cs151Final.getEvent() << "\n\n";

    return 0;
}
