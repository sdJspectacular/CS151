// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   5
// Homework:  5
// Project: 1
// Problem Statement: Numbers in English
//
// Algorithm:
//   1. Get the thousands value and output
//   2. Get the hundreds value and output
//   3. If remaining value is less than 20, output
//   4. Get the tens value and output
//   5. Get the ones value and output
//
#include "Numbers.h"
#include <string>
#include <iostream>

// This function prints a number as a string in English
void Numbers::print()
{
    // How many thousands?
    int rem = this->number % 1000;
    int thousands = (this->number - rem) / 1000;
    if (thousands != 0)
        std::cout << lessThan20[thousands] << " " << thousand << " ";

    // How many hundreds?
    int hundreds = (rem - rem % 100) / 100;
    rem %= 100;
    if (hundreds != 0)
        std::cout << lessThan20[hundreds] << " " << hundred << " ";

    if (rem < 20)
    {
        // If remaining value is less than 20, what is it?
        if ((rem != 0) || (this->number == 0))
            std::cout << lessThan20[rem] << " ";
    }
    else
    {
        // How many tens?
        int deca = (rem - rem % 10) / 10;
        rem %= 10;
        if (deca != 0)
            std::cout << tens[deca - 1] << " ";

        // How many ones?
        if (rem != 0)
            std::cout << lessThan20[rem] << " ";
    }
    std::cout << "\n";
}

// static members should be declared inside the class and initialized outside of it
// since they are constants, they should be made  static  so that they appear in memory only once.
const std::string Numbers::lessThan20[20] = {"zero", "one", "two", "three", "four", "five", "six",
                                        "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                                        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

const std::string Numbers::tens[9] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const std::string Numbers::hundred = "hundred";
const std::string Numbers::thousand = "thousand";

int Numbers::getNumber(void) const
{
    return number;
}
