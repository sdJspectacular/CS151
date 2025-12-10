/* lab15.cpp - Sets
 * Author:     Jack Marriott
 * Module:     15
 * Project:    Lab
 * Problem statement:  Demonstration of sets using linked lists
 *
 * Algorithm:
   1. Complete the provided SetLinkedList class
    *      - implement the minus, size, equals, and clear member functions
    2. Write a tester program to demonstrate the SetLinkedList class
    3. Demonstrate with four test cases
    - Note: Use the same sets for test cases 1 and 2
    - Note: Use the same sets for test cases 3 and 4
    4. Write a runTests function to perform the tests on two sets
    5. Test cases:
    - Test case 1: calling set = {“C”, “G”, “E”, “A”} and other(parameter) set = {“E”, “C”, “F”}
    - Test case 2: calling set = {“Carlos”, “John”, “Alice”} and other set = {“John”, “Henry”, “Maria”}
    - Test case 3: calling set = {15, 11, 13} and other set = {11, 13, 15, 17, 19}
    - Test case 4: calling set = {9} and other set = { }
 */
#include <iostream>
#include "SetLinkedList.h"

using namespace std;

template <typename T>
void runTests(Set<T> A, Set<T> B);

int main()
{
    // Test case 1: calling set = {“C”, “G”, “E”, “A”} and other(parameter) set = {“E”, “C”, “F”}
    Set<string> caller;
    caller.insert("C");
    caller.insert("G");
    caller.insert("E");
    caller.insert("A");
    Set<string> other;
    other.insert("E");
    other.insert("C");
    other.insert("F");

    cout << "\nTest case #1:\n";
    runTests(caller, other);
    cout << "\n";

    // Test case 2: calling set = {“Carlos”, “John”, “Alice”} and other set = {“John”, “Henry”, “Maria”}
    // Note: Use the same sets for test cases 1 and 2
    caller.clear();
    other.clear();
    caller.insert("Carlos");
    caller.insert("John");
    caller.insert("Alice");
    other.insert("John");
    other.insert("Henry");
    other.insert("Maria");
    cout << "\nTest case #2:\n";
    runTests(caller, other);
    cout << "\n";

    // Test case 3: calling set = {15, 11, 13} and other set = {11, 13, 15, 17, 19}
    Set<int> callerInt;
    Set<int> otherInt;
    callerInt.insert(15);
    callerInt.insert(11);
    callerInt.insert(13);
    otherInt.insert(11);
    otherInt.insert(13);
    otherInt.insert(15);
    otherInt.insert(17);
    otherInt.insert(19);
    cout << "\nTest case #3:\n";
    runTests(callerInt, otherInt);
    cout << "\n";

    // Test case 4: calling set = {9} and other set = { }
    // Note: Use the same sets for test cases 3 and 4
    callerInt.clear();
    otherInt.clear();
    callerInt.insert(9);
    cout << "\nTest case #4:\n";
    runTests(callerInt, otherInt);
    cout << "\n";

    return 0;
}

template <typename T>
void runTests(Set<T> A, Set<T> B)
{
    cout << "Set A: ";
    A.display();
    cout << "Set B: ";
    B.display();
    cout << "A int B: ";
    A.setIntersect(B).display();
    cout << "A - B: ";
    A.minus(B).display();
    cout << "(A - B) U (A int B): ";
    Set<T> temp = A.minus(B).setUnion(A.setIntersect(B));
    temp.display();
    cout << "Equal?: " << (A.equals(temp) ? "Yes" : "No") << "\n";
    cout << "Set A has " << A.size() << " elements\n";
}
