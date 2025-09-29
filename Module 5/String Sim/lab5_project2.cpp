// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   5
// Lab:  5
// Project: 2
// Problem Statement: Copy Constructor
//
// Algorithm:
//   1. Create a String class, initially without copy constructor
//   2. Demonstrate how default copy constructor causes:
//      - shallow copy
//      - double free (as Program 11-7 in the book warns)
//   3. Add copy constructor, demonstrate:
//      - deep copy
//      - no double free run-time error
//
#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    // 1. Create two  String  objects, one using a constructor and one using an initialization statement.

    cout << "Create two strings, one using a constructor, another an assignment statement " << endl;

    String str1("MiraCosta College"); // str1 uses constructor
    String str2 = str1;               // str2 uses copy constructor

    // 2. Print the value of both string on the console using the  print  function.
    //    Identify each string in the output
    cout << "str1: ";
    print(str1);
    cout << "str2: ";
    print(str2);

    // 3. Change the string stored in the second  String  object using the  change  function,
    //    then print both  String  objects again.
    cout << "\nAfter changing str2 using change()" << endl;
    str2.change("Cal State San Marcos");
    cout << "str1: ";
    print(str1);
    cout << "str2: ";
    print(str2);

    // 4. Change the value of the first  String  object using the change function and print
    //    both objects again.
    cout << "\nAfter changing string 1 using change()" << endl;
    str1.change("UCSD");
    cout << "str1: ";
    print(str1);
    cout << "str2: ";
    print(str2);

    return 0;
}
