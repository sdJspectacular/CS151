/* hw13_proj2.cpp - SimpleVector
 * Author:     Jack Marriott
 * Module:     13
 * Project:    HW, Project 2
 * Problem statement:  SimpleVector with push_back and pop_back exception handling
 *
 * Algorithm:
 *  1. Create a SimpleVector class template that manages a dynamic array
 *     - the class behaves like a simplified version of std::vector, except with fixed capacity
 *     - include a constructor, copy constructor, and destructor to manage memory
 *     - include member functions push_back and pop_back
 *     - push_back adds an element to the end of the vector, throwing an exception if full
 *     - pop_back removes the last element from the vector, throwing an exception if empty
 *  2. Write a tester program to demonstrate the SimpleVector class and exception handling
 *     - create SimpleVector objects for int and string types
 *     - test push_back and pop_back functions, including cases that trigger exceptions
 *  3. Display appropriate messages when exceptions are caught
 */
#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
    SimpleVector<int> intVect(5); // Create a SimpleVector with capacity 5

    cout << "Demonstrates SimpleVector<int> push_back and pop_back with exceptions\n";
    cout << "Initial size: " << intVect.getSize() << ", capacity: " << intVect.getCapacity() << "\n";
    try
    {
        // Remove elements from empty vector to trigger exception
        cout << "Popping back from empty vector:\n";
        intVect.pop_back();
    }
    catch (const out_of_range &e)
    {
        cout << "Exception caught: " << e.what() << "\n";
    }

    try
    {
        // Add elements to the vector
        for (int i = 0; i < 6; ++i)
        {
            cout << "Pushing back: " << i;
            intVect.push_back(i);
            cout << "\tSize after push: " << intVect.getSize() << "\n";
        }
    }
    catch (const out_of_range &e)
    {
        cout << "\tException caught: " << e.what() << "\n";
    }

    cout << "\n";

    SimpleVector<string> strVect(5); // Create a SimpleVector with capacity 5
    
    cout << "Demonstrates SimpleVector<string> push_back and pop_back with exceptions\n";
    cout << "Initial size: " << strVect.getSize() << ", capacity: " << strVect.getCapacity() << "\n";

    try
    {
        // Add elements to the vector
        for (int i = 0; i < 6; ++i)
        {
            cout << "Pushing back: " << "abc" + to_string(i);
            strVect.push_back("abc"+to_string(i));
            cout << "\tSize after push: " << strVect.getSize() << "\n";
        }
    }
    catch (const out_of_range &e)
    {
        cout << "\tException caught: " << e.what() << "\n";
    }

    try
    {
        // Remove elements from the vector
        for (int i = 0; i < 6; ++i)
        {
            cout << "Popping back: " << strVect.pop_back();
            cout << "\tSize after pop: " << strVect.getSize() << "\n";
        }
    }
    catch (const out_of_range &e)
    {
        cout << "Exception caught: " << e.what() << "\n";
    }

    cout << "\n";

    return 0;
}
