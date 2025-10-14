// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   7
// Lab:  7
// Project: 2
// Problem Statement: Animal, Fox, and Owl classes
//
// Algorithm:
//   1. 
//   2. 
//   3. 
//
#include <iostream>
#include "Fox.h"
#include "Owl.h"
#include "Animal.h"

using namespace std;

int main()
{
    // creates an  Animal  object with a name “Oscar”
    Animal *Oscar = new Animal("Oscar");
    
    // creates a  Owl  object with a name “Errol” and a breed “Great Grey”
    Owl *Errol = new Owl("Errol", "Great Grey");
    
    // creates a  Fox  object with a name “Foxy".
    Fox *Foxy = new Fox("Foxy");
    
    // uses the  showInfo  function to print Oscar, Errol, and Foxy
    Oscar->showInfo();
    Errol->showInfo();
    Foxy->showInfo();
    
    // causes Oscar, Errol, and Foxy each to make a noise
    Oscar->makeNoise();
    Errol->makeNoise();
    Foxy->makeNoise();
    
    // causes Oscar, Errol, and Foxy each to  sleep
    Oscar->sleep();
    Errol->sleep();
    Foxy->sleep();
    
    return 0;
}
