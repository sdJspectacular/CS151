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
//   5. Demonstrate prefix ++
//   6. Demonstrate postfix ++
//   7. Demonstrate operator+
//   8. Demonstrate operator[]
//   9. Demonstrate ++ and operator[]

#include <iostream>
#include <iomanip>
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

    EString testStr1 = "New Year's Party at 8:30.";
    EString testStr2 = "Be at my house at 5:00 PM";

    // Demonstrate prefix operator
    cout << "Original string:         " << setw(30) << right << testStr1 << "\n";
    cout << "Using prefix operator:   " << setw(30) << right << ++testStr1 << "\n";
    cout << "After using prefix:      " << setw(30) << right << testStr1 << "\n";

    // Demonstrate postfix operator
    cout << "\n";
    cout << "Original string:         " << setw(30) << right << testStr2 << "\n";
    cout << "Using postfix operator:  " << setw(30) << right << testStr2++ << "\n";
    cout << "After using postfix:     " << setw(30) << right << testStr2 << "\n";
   
    // Demonstrate operator+
    EString testStr3;
    testStr3 = testStr1 + " " + testStr2;
    cout << "\n" << testStr3 << "\n\n";

    // 4. On a single line of output, use a loop and the overloaded [] to extract
    // each character in one of the  EString  objects and print each character
    // separated by a space. 
    int i = 0;
    cout << "Original: ";
    while (testStr1[i++])
        cout << testStr1[i-1] << " ";

    cout << "\n";

    // Again using both the overloaded ++ and [  ] operators, make another loop
    // to increment each character's value using the same EString object and print
    // that character.  Again separate characters with a space.
    i = 0;
    cout << "Updated:  ";
    while (testStr1[i++])
        cout << ++testStr1[i-1] << " ";

    cout << "\n\n";

    return 0;
}
