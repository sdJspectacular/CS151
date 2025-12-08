
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

    // Demonstrate removeAt with a valid index
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
