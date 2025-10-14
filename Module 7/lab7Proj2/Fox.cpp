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
