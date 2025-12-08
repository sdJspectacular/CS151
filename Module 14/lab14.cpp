/* lab14.h - Generic class allowing representation of a linked list
 * Author:     Jack Marriott
 * Module:     14
 * Project:    Lab
 * Problem statement:  This file demonstrates a generic linked list class.
 *                     The class itself is defined in LinkedList.h
 *                     Demonstrate usage of functions: display(), remove(T myData), removeAt(int index),
 *                     lastIndexOf(T myData), contains(T myData), set(int index, T myData).
 *
 * Algorithm:
  1. Declare a new empty list and demonstrate display() and getSize()
  2. Demonstrate what happens when removing from an empty list
  3. Initialize the list with random values
  4. Demonstrate display and getSize() for a non-empty list
  5. Demonstrate remove
  6. Demonstrate removing another element
  7. Demonstrate removeAt with invalid index
  8. Demonstrate removeAt head node
  9. Demonstrate set at head node
  10. Demonstrate lastIndexOf
  11. Demonstrate contains with and without contained elements
 */
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

int main()
{
    const int NELEMS = 20;
    LinkedList<int> list;

    // Declare a new empty list and demonstrate display() and getSize()
    cout << "Declaring new list...\n";
    cout << "Contents (index, value): ";
    list.display();cout << "\n";
    cout << "Size: " << list.getSize() << "\n\n";

    // Demonstrate what happens when removing from an empty list
    cout << "Removing a node...\n";
    try
    {
        list.removeAt(0);
    }
    catch (const runtime_error &e)
    {
        cerr << "Runtime error: " << e.what() << "\n";
    }
    
    // Initialize the list with random values
    cout << "\nInitializing with random values...\n";
    for (int i = 0; i < NELEMS; ++i)
    {
        list.add(i, (rand() % 10));
    }
    
    // Demonstrate display() and getSize() for a non-empty list
    cout << "Contents (index, value): ";
    list.display();cout << "\n";
    cout << "Size: " << list.getSize() << "\n\n";

    // Demonstrate remove(T myData)
    cout << "Remove the first element with a value of 0...\n";
    list.remove(0);
    cout << "Contents (index, value): ";
    list.display();cout << "\n";
    cout << "Size: " << list.getSize() << "\n\n";

    // Demonstrate removing another element
    cout << "Remove the first element with a value of 3...\n";
    list.remove(3);
    cout << "Contents (index, value): ";
    list.display();cout << "\n";
    cout << "Size: " << list.getSize() << "\n\n";

    // Demonstrate removeAt with invalid index
    cout << "Remove an element at invalid index -1...\n";
    try
    {
        list.removeAt(-1);
    }
    catch(const std::exception& e)
    {
            cerr << "Runtime error: " << e.what() << "\n";
    }

    // Demonstrate removeAt head node
    int value = list.removeAt(0);
    cout << "\nRemoved element at index 0 with value: " << value << "\n";
    cout << "Contents (index, value): ";
    list.display();cout << "\n";
    cout << "Size: " << list.getSize() << "\n\n";

    // Demonstrate set at head node
    cout << "Set element at index 0 to value -99...\n";
    list.set(0, -99);
    cout << "Contents (index, value): ";
    list.display();cout << "\n";
    cout << "Size: " << list.getSize() << "\n\n";

    // Demonstrate lastIndexOf
    cout << "\nFind last element with value of 6...\n";
    value = list.lastIndexOf(6);
    cout << "Value Index: " << value << "\n";

    // Demonstrate contains
    cout << "\nCheck if list contains value of 5...\n";
    bool found = list.contains(5);
    cout << "Contains 5: " << (found ? "true" : "false") << "\n";
    cout << "\nCheck if list contains value of -99...\n";
    found = list.contains(-99);
    cout << "Contains -99: " << (found ? "true" : "false") << "\n";

    cout << "\n";

    return 0;
}
