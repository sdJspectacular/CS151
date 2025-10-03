// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   6
// Lab:  6
// Project: 1
// Problem Statement: Enhanced String class
//
// Algorithm:
//   1. Create an EString class
//   2. Demonstrate default constructor:
//      - with input argument
//      - without input argument
//   3. Demonstrate assignment operator
//   4. Demonstrate copy constructor
//      
//      - shallow copy
//      - double free (as Program 11-7 in the book warns)
//   3. Add copy constructor, demonstrate:
//      - deep copy
//      - no double free run-time error
//
#include <iostream>
#include "EString.h"

using namespace std;

int main()
{
    EString estring1 = "Hello MiraCosta!";  // test default constructor
    EString estring2;  // test default constructor

    estring2 = estring1; // test the assignment operator=
    
    EString estring3 = estring2;  // test copy constructor

    cout << "First string :  " << estring1 << "\n"
         << "Second string:  " << estring2 << "\n"
         << "Third string :  " << estring3 << "\n\n";

    cout << "estring1 : " << ++estring1 << "\n";
    cout << "estring2 : " << estring2++ << "\n";
    cout << "estring2 : " << estring2 << "\n";

    cout << estring3[1] << "\n";

    estring1[1] = estring1[2] = estring1[3];

    cout << estring1 << "\n";

    cout << estring2 + estring3 << "\n";
    
    return 0;
}
