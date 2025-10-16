// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   7
// Lab:  7
// Project: 2
// Problem Statement: Animal, Fox, and Owl classes
//
// Algorithm:
//   1. Create an Animal object
//   2. Create an Owl object
//   3. Create a Fox object
//   4. Demonstrate showInfo() for all 3 animals
//   5. Demonstrate makeNoise() for all 3 animals
//   6. Demonstrate sleep() for all 3 animals
//
#include <iostream>
#include "Fox.h"
#include "Owl.h"
#include "Animal.h"

using namespace std;

// answers to the following review questions for Project #2
// 1. What is/are the names of the base classes?
//      The base class is Animal
//
// 2. What is/are the names of the derived classes?
//      The derived classes are Fox and Owl
//
// 3. Does  Animal  have a parent class?
//      Animal does not have a parent class
//
// 4. Is the function  showInfo  overridden?  Is  makeNoise?  Is  sleep?
//      showInfo() is overriden in both Fox and Owl
//      makeNoise() is overriden in both Fox and Owl
//      sleep() is not overriden by either derived class
//
// 5. If the data member name in the Animal class were made protected (instead of private), 
//    would you need to use getters in the showInfo function of the child classes Fox and Owl?
//      No
//
// 6. What if the class data members were left private, but the base access modifiers to the Animal
//    class in both child classes were made protected, would you need to use getters in the showInfo
//    function of the child classes Fox and Owl? 
//      Yes

int main()
{
    // creates an Animal object with a name “Oscar”
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

    cout << "\n";
    
    return 0;
}
