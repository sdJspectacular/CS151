/* hw14.cpp - Linked List Operations
 * Author:     Jack Marriott
 * Module:     14
 * Project:    HW, Projects 1-5
 * Problem statement:  Test and demonstrate the LinkedList class with various member functions
 *
 * Algorithm:
   1. Demo the LinkedList class by creating an object with the default constructor
   2. Add nodes with values 7.0, 8.0, and 9.0 using the add function
   3. Use the isMember function to check for the presence of values 9.0, 7.0, and 5.0
   4. Print the contents of the list using the print function
   5. Reverse the list using the reverse function and print the contents
   6. Reverse the list again to restore original order and print the contents
   7. Search for values 8.0, 7.0, and 10.0 using the search function and display their indices
   8. Insert values at various positions (head, middle, end) using the insert function and print the list after each insertion
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    // Create a  LinkedList object using the default constructor
    LinkedList list;

    // Add nodes 7.0, 8.0, and 9.0
    cout << "Adding nodes 7.0, 8.0, and 9.0 to the empty list.\n";
    list.add(7.0);
    list.add(8.0);
    list.add(9.0);

    // Using  isMember,  test to see if 9.0 is in the list (should return  true), 
    cout << "Test 9.0: " << (list.isMember(9.0) ? "true" : "false") << "\n";

    // if 7.0 is in the list (should return  true), and if 5.0 is in the list (should return  false)
    cout << "Test 7.0: " << (list.isMember(7.0) ? "true" : "false") << "\n";
    cout << "Test 5.0: " << (list.isMember(5.0) ? "true" : "false") << "\n";
    
    // Finally, print the list to the console
    cout << "The contents of the list are: ";
    list.print();
    cout << "\n";

    // Test your new function by reversing the contents of a  LinkedList  and displaying its contents
    list.reverse();
    cout << "The contents of the reversed list are: ";
    list.print();
    cout << "\n";

    // Then reverse it again and display its contents (it should be back to the original array).
    list.reverse();
    cout << "The contents of the list after reversing again are: ";
    list.print();
    cout << "\n";

    // Test the new member function by searching for two elements which are in the list,
    // then searching for an element which is not in the list.
    cout << "Searching for 8.0 in the list: Index " << list.search(8.0) << "\n";
    cout << "Searching for 7.0 in the list: Index " << list.search(7.0) << "\n";
    cout << "Searching for 10.0 in the list: Index " << list.search(10.0) << "\n";

    // Test your function by inserting an element at the head of a list
    cout << "Inserting 10.0 at position 0.\n";
    list.insert(10.0, 0);
    cout << "The contents of the list are: ";
    list.print();

    // Test your function by inserting in the middle of a list
    cout << "Inserting 8.5 at position 2.\n";
    list.insert(8.5, 2);
    cout << "The contents of the list are: ";
    list.print();

    // Test your function by inserting at the end of a list
    cout << "Inserting 6 at position 5.\n";
    list.insert(6, 5);
    cout << "The contents of the list are: ";
    list.print();

    cout << "\n";

    return 0;
}
