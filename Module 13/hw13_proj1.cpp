/* hw13_proj1.cpp - String Bound Exceptions
 * Author:     Jack Marriott
 * Module:     13
 * Project:    HW, Project 1
 * Problem statement:  String bound exceptions
 *
 * Algorithm:
 *   1. Create a BCheckString class that extends the C++ string class
 *     - include a constructor that takes a string argument
 *     - overload the [] operator to check for bounds
 *       - if the index is out of bounds, throw a BoundsException
 *   2. Create a BoundsException class that extends the C++ exception class
 *      - include a constructor that takes the bad index value
 *      - override the what() function to return an appropriate error message
 *   3. Write a tester program to demonstrate the BCheckString class and exception handling
 *      - create a BCheckString object with a test string
 *      - access valid and invalid indices to show normal operation and exception handling
 * 
 */
#include <iostream>

using namespace std;

// The  BoundsException class extends the C++ exception class as
// demonstrated in slides for this module.
class BoundsException : public exception
{
private:
    int badIndex;
    string message;

public:
    BoundsException(int n) : badIndex(n)
    {
        // In the exception message, include the value of the index which caused the exception
        message = "Index " + to_string(badIndex) + " is out of bounds.";
    }

    virtual const char *what() const noexcept override
    {
        // objects of the BCheckString class work like strings themselves
        return message.c_str();
    }
};

class BCheckString : public string
{

public:
    // A constructor that receives a string object passed by value and
    // passes it on to the base class constructor.
    BCheckString(string s) : string(s) {}

    // A  function that throws a BoundsException object if the index k
    // is negative or is greater than or equal to the length of the string.
    // If k is within the bounds of the string, this function should return
    // the character at position k in the string.
    char operator[](int k)
    {
        int n = getVal().length();

        try
        {
            if ((k < 0) || (k >= n))
                throw BoundsException(k);
            else
                return getVal()[k];
        }
        catch (BoundsException &e)
        {
            cout << e.what();
            return '\0';
        }
    }

    // A getter function to retrieve the contents of the string in the
    // base class
    string getVal(void)
    {
        return *this;
    }
};

// Demonstrate the BCheckString class in a tester program
int main()
{

    // Test string being used
    BCheckString a("Now is the time for all the young coders to come to the aid of their country.");

    // Show the test string being used, then access at least two characters inside the string.
    // Also demonstrate the exceptions thrown when a negative index and when an index that
    //is too large are used.  In all four cases, indicate the the value of the index  k.
    cout << "Test string: " << a.getVal() << "\n";
    cout << "String length: " << a.getVal().length() << "\n";
    cout << "Character at position 0: " << a[0] << "\n";
    cout << "Character at position 76: " << a[76] << "\n";
    cout << "Character at position 77: " << a[77] << "\n";
    cout << "Character at position -1: " << a[-1] << "\n";
    cout << "\n";

    return 0;
}
