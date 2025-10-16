// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   7
// Lab:  7
// Project: 2
// Problem Statement: Animal class
#ifndef _ANIMAL_
#define _ANIMAL_

#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
//protected:
    // The Animal class has one data member, a private string variable named name
    string name;

public:
    // A single constructor which takes one parameter (a string) used to set the
    // data member by using a member initialization list, then prints the message
    Animal(string name) : name(name)
    {
        cout << "The Animal " << name << " has been created.\n";
    }

    // “getter” and “setter” functions for the data member name (make the "getter" read-only)
    string getName(void) const;
    void setName(string name);

    // a read-only no-argument function named  sleep  which prints a message
    void sleep(void) const;

    // another read-only no-argument function named  makeNoise  which prints a message
    void makeNoise(void) const;

    // a third read-only function named  showInfo  which prints: “The Animal <its name>”
    void showInfo(void) const;
};

#endif
