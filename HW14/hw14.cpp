#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    // Create a  LinkedList  object using the default constructor
    LinkedList list;

    // Add nodes 7.0, 8.0, and 9.0
    list.add(7.0);
    list.add(8.0);
    list.add(9.0);

    // Using  isMember,  test to see if 9.0 is in the list (should return  true), 
    cout << "Test 9.0: " << (list.isMember(9.0) ? "true" : "false") << "\n";

    // if 7.0 is in the list (should return  true), and if 5.0 is in the list (should return  false)
    cout << "Test 7.0: " << (list.isMember(7.0) ? "true" : "false") << "\n";
    cout << "Test 5.0: " << (list.isMember(5.0) ? "true" : "false") << "\n";
    
    return 0;
}
