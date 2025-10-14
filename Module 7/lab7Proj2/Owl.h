#ifndef _OWL_
#define _OWL_

#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

// The Owl class is a child of the  Animal  class
class Owl : public Animal
{
private:
// has one data member, a  private string named  breed.
    string breed;

public:
// has a single constructor which takes one parameter, 
// a string used to set the data member of its parent (use member initialization list),
// then prints a message
Owl(string name, string breed) : Animal(name), breed(breed)
{
    cout << "A Owl " << getName() << " of breed " << getBreed() << " has been created.\n";
}

    // “getter” and “setter” functions for the data member breed (make the "getter" read-only)
    void setBreed(string breed);
    string getBreed(void) const;
    
// Has a read-only no-argument function named makeNoise which prints the message
void makeNoise(void) const;

// another read-only showInfo function which prints a message
void showInfo(void) const;

};

#endif
