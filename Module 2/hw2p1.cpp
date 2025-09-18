// CS151 Fall 2025, Decimal to Binary Converter
// Author:   Jack Marriott
// Module:   2
// Project:  1
// Problem Statement: A program that converts a positive decimal value into
// its binary representation.
//
// Algorithm:
//   1. Prompt user for value
//   2. If value is zero, return the string zero and stop
//   3. Initialize an empty string
//   3. Otherwise loop until reaching zero:
//      - compute remainder as modulo between value and 2
//      - Update value as value - remainder
//      - Update value as value / 2 (interger division)
//      - Prepend remainder to beginning of binary string
//   4. Return binary string
//   5. Go back to step 1 until input value is negative, at which point exit

#include <iostream>
#include <string>

using namespace std;

// Prototypes
string dec2bin(int val);

int main()
{
    string num;
    int val;

    // Input a value for conversion (Note: no error checking in input data type)
    // Continue looping asking for conversion values until a negative value is entered
    do
    {
        cout << "Enter a decimal value to convert: ";
        getline(cin, num);
        val = stoi(num);
        if (val >= 0)  // Process positive values
            cout << dec2bin(val) << "\n";
        else          // else exit
            cout << "Stopping\n";

    } while (val >= 0);

    return 0;
}

// This function will convert an input integer value in decimal and return its
// equivalent binary value as a string.
string dec2bin(int val)
{
    int rem;
    string result = "";

    if (val == 0)
        return "0";

    while (val > 0)
    {
        rem = val % 2;
        val -= rem; // not quite necessary in binary because division below will truncate
        val /= 2;
        result = to_string(rem) + result; // prepend, because LSB is computed first and MSB last
    }

    return result;
}
