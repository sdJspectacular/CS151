// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   7
// Lab:  7
// Project: 2
// Problem Statement: Fox class
#include "Fox.h"
#include <iostream>
#include <string>

using namespace std;

// a read-only no-argument function named  makeNoise  which prints a message
void Fox::makeNoise(void) const
{
    cout << "The Fox " << getName() << " is yelping.\n";
}

//  another read-only  showInfo  function which prints a message
void Fox::showInfo(void) const
{
    cout << "The Fox " << getName() << "\n";
}
