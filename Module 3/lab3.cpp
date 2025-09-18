// CS151 Fall 2025, Decimal to Binary Converter
// Author:   Jack Marriott
// Module:   3
// Lab:  3
// Problem Statement: Detailed investigation of three ways to create a dangling pointer.
//
// Algorithm:
//   1. Point to the address of a variable which was allocated inside a block of code and then went out of scope
//   2. Point to memory originally allocated from the heap using new that has been de-allocated using  delete
//   3. Point to the address of local variable allocated inside a function and returned from that function

#include <iostream>

using namespace std;

// Prototypes
int *badReturn(void);

int main()
{
    // Dangling pointer issue #1
    //
    // Point to the address of a variable which was allocated inside a block of code and then went out of scope

    cout << "Part #1" << endl;
    int *ptr1; // This is the pointer which will be left dangling

    if (true)
    {
        int square = 36;
        ptr1 = &square; // point it to "square" which will go out of scope
    }
    // "square" is now out of scope and ptr1 is left pointing to the stack

    *ptr1 = 49; // Now use the pointer, which was left dangling
    cout << "Dangling pointer: " << *ptr1 << endl
         << endl;

    // Dangling pointer issue #2
    //
    // Point to memory originally allocated from the heap using new that has been de-allocated using  delete

    cout << "Part #2" << endl;
    int *ptr2 = new int(11); // Allocate from heap

    // Now free that memory and try to use it
    delete ptr2; // De-allocate from heap
    *ptr2 = 85;  // But now we use the pointer anyway
    cout << "Dangling pointer: " << *ptr2 << endl
         << endl;

    // Dangling pointer issue #3
    //
    // Point to the address of local variable allocated inside a function and returned from that function

    cout << "Part #3" << endl;
    int *ptr3 = badReturn();                       // returns 0x00 if badReturn uses local variables
    cout << "Dangling pointer: " << *ptr3 << endl; // This doesn't work when ptr3 is 0x00

    // Will the value in ptr3 be re-initialized?
    *ptr3 = 45;         // This doesn't work when ptr3 is 0x00
    ptr3 = badReturn(); // returns 0x00 if badReturn uses local variables
    cout << "When called again:   " << *ptr3 << endl;

    cout << "Conclusion: cases 1-2 still work with this compiler, g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0.\n"
         << "Per Gemini: Accessing this dangling pointer results in undefined behavior. It is good practice\n"
         << "to set the pointer to nullptr after deletion to prevent this.\n\n";

    return 0;
}

// Return the address of a local variable
int *badReturn(void)
{
    // int x = 19; // Local variable, only exists in stack and for duration of function call
    static int x = 19; // static variable, now exists in static memory area
    return &x;         // returns address of local variable
}
