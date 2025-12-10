// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   7
// Lab:  7
// Project: 2
// Problem Statement: Animal class
#include "Animal.h"
#include <string>

using namespace std;

// “getter” function for the data member name (make read-only)
string Animal::getName(void) const
{
    return this->name;
}

// “setter” function for the data member name
void Animal::setName(string name)
{
    this->name = name;
}

// a read-only no-argument function named  sleep  which prints a message
void Animal::sleep(void) const
{
    cout << "The Animal " << getName() << " is sleeping.\n";
}

// // another read-only no-argument function named  makeNoise  which prints a message
void Animal::makeNoise(void) const
{
    cout << "The Animal " << getName() << " is making a noise.\n";
}

// a third read-only function named  showInfo  which prints: “The Animal <its name>”
void Animal::showInfo(void) const
{
    cout << "The Animal " << getName() << "\n";
}
