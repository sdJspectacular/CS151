// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   6
// Lab:  6
// Project: 2
// Problem Statement: More operator overloading
//
// Algorithm:
//   1. Create a Money class to demonstrate
//      - copy constructor
//      - move constructor
//      - assignment operator
//      - operator overloading
//   2. Add a message to each constructor each time it's executed
//   3. Demonstrate default constructor
//   4. Demonstrate operator+
//   5. Demonstrate operator>=
//   6. Demonstrate assignment operator and copy constructor in a single line
//   7. Demonstrate the move constructor
//
#include <iostream>
#include <iomanip>
#include "Money.cpp"

using namespace std;

// 8. Above main, create a prototype for a function which takes and returns a Money object.
Money testMove(Money);

int main()
{
    // 1. Create four Money objects with values 4.90, 1.27, 5.24, and 0.99,  assigning to four  Money  variables
    Money mon1("4.90"), mon2("1.27"), mon3("5.24"), mon4("0.99");

    // 2. Add the first and second  Money  objects using the overloaded  +  operator, put the sum in a new Money variable,
    // and print the results.  Your output might look like:
    Money mon5 = mon1 + mon2;
    cout << mon1 << " + " << mon2 << " = " << mon5 << "\n";

    // 3. Add the third and fourth  Money  objects, store in another  Money  variable, and print the results.
    Money mon6 = mon3 + mon4;
    cout << mon3 << " + " << mon4 << " = " << mon6 << "\n";

    // 4. Compare the values of the two "sum" objects and print the larger of the two objects using the
    // overloaded >= operator (should be the second sum)
    cout << "The larger of those two values is: ";
    if (mon5 >= mon6)
        cout << mon5;
    else
        cout << mon6;

    cout << "\n\n";

    // 5. Re-assign the first Money variable to a new Money object with a value of 5.00, then recalculate
    // the first "sum" using the (updated) first and second  Money  object
    mon1 = Money("5.00");
    mon5 = mon1 + mon2;
    cout << mon1 << " + " << mon2 << " = " << mon5 << "\n";

    // 6. Compare the values of the two "sum" objects again and print the larger of the two
    // (now should be the new first "sum").
    cout << "The larger of the last two values is: ";
    if (mon5 >= mon6)
        cout << mon5;
    else
        cout << mon6;

    cout << "\n\n";

    // 9. At the bottom of  main, invoke the testMove function
    Money returned = testMove(Money("8.36"));
    cout << "Returned: " << returned << "\n\n";

    return 0;
}

// This function will be used to ensure that the move constructor is invoked when needed.  Use this prototype:
Money testMove(Money in)
{
    return in;
}
