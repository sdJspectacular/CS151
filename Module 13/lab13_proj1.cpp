/* lab13_proj1.cpp - Arithmetic exception
 * Author:     Jack Marriott
 * Module:     13
 * Project:    Lab, Project 1
 * Problem statement:  Handle arithmetic exception with exception class
 *
 * Algorithm:
 *   1. Write a function that finds the integer square root of a number, if it exists
 *      - if the square root does not exist, throw an error of a new class type
 *   2. Write a new error class type that gets caught from main when exception is thrown
 *      - the class contains a getter function to allow retrieving the bad value
 */
#include <iostream>
#include <iomanip>

using namespace std;

// Make the exception a new exception class which your program creates
class notPerfectSquare
{
private:
    int badValue;

public:
    notPerfectSquare(int val) : badValue(val) {}
    int getBadValue(void)
    {
        return badValue;
    }
};

// Function to compute the integer square root of an integer argument
// throws an error if the square root does not exist
int wholeSqrt(int n);

int main()
{
    int sqrtVal;

    // Demonstrate the function with a "tester" program that uses a loop to pass to your
    // function the numbers from 0 through 25, then prints whether or not that number is a
    // perfect square.

    cout << setw(5) << "Value" << " " << setw(15) << "Square Root" << "\n";
    cout << setw(5) << "-----" << " " << setw(15) << "-----------" << "\n";

    for (int i = 0; i <= 25; ++i)
    {
        try
        {
            // If the number is a perfect square, then print its square root returned from the
            // function.
            sqrtVal = wholeSqrt(i);
            cout << setw(5) << right << i << " " << setw(5) << right << sqrtVal << "\n";
        }
        catch (notPerfectSquare &val)
        {
            // If not, then print a message indicating that number is not a perfect square.
            cout << setw(5) << right << val.getBadValue() << " " << setw(25) << left << "    Not a perfect square" << "\n";
        }
    }
    cout << "\n";
}

// Write a function which accepts an integer parameter and returns its integer square root
// (if one exists).  Do not handle the exception in the function
int wholeSqrt(int n)
{
    if (n < 0)
        return -1;
    else if ((n == 0) || (n == 1))
        return n;

    int i = 1;
    while (i < n / 2)
    {
        if (i * i == n)
            return i;
        ++i;
    }
    // The function should throw an exception if it is passed an number that is not a perfect square.
    throw notPerfectSquare(n);
}
