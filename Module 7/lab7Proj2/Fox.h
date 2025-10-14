#ifndef _FOX_
#define _FOX_

#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

// The Fox class is a child of the  Animal  class
class Fox : public Animal
{
private:
// has no data members

public:
// has a single constructor which takes one parameter, 
// a string used to set the data member of its parent (use member initialization list),
// then prints a message
Fox(string name) : Animal(name)
{
    cout << "A Fox " << getName() << " has been created.\n";
}

// Has a read-only no-argument function named makeNoise which prints the message
void makeNoise(void) const;

// another read-only showInfo function which prints a message
void showInfo(void) const;

};

#endif
