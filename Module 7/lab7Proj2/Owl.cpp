// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   7
// Lab:  7
// Project: 2
// Problem Statement: Owl class
#include "Owl.h"
#include <iostream>
#include <string>

using namespace std;

// a read-only no-argument function named  makeNoise  which prints a message
void Owl::makeNoise(void) const
{
    cout << "The Owl " << getName() << " is hooting.\n";
}

//  another read-only  showInfo  function which prints a message
void Owl::showInfo(void) const
{
    cout << "The Owl " << getName() << " of breed " << getBreed() << "\n";
}

void Owl::setBreed(string breed)
{
    this->breed = breed;
}

string Owl::getBreed(void) const
{
    return this->breed;
}
