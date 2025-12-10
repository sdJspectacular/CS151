// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   5
// Homework:  5
// Project: 1
// Problem Statement: Numbers in English
//
// Algorithm:
//   1. Request a number from the user, in the range 0 - 9999
//      - limit values to this range
//      - exit when input value is zero
//   2. Print the number as a string in the English language
//   3. Repeat until exit condition is met
//
#include <iostream>
#include <string>
#include "Numbers.h"

using namespace std;


int main()

{
    Numbers a;
    int number;
    string token;

    do {
        cout << "Enter a number (0 - 9999): ";
        getline(cin, token);
        number = stoi(token);
        number = (number > 9999)?(9999):(number);
        number = (number < 0)?(0):(number);
        a.setNumber(number);
        a.print();
    } while (number != 0);

    return 0;
}
