/* LinkedList.h - Linked List Operations
 * Author:     Jack Marriott
 * Module:     14
 * Project:    HW, Projects 1-5
 * Problem statement:  Test and demonstrate the LinkedList class with various member functions
 *
 * Algorithm:
   1. Project 1: design a linked list class with two member functions: add and isMember
      - The add function adds a new node containing a double value to the head of the list
      - The isMember function checks whether a given double value is present in the list
    2. Project 2: add a print member function to display the contents of the list
    3. Project 3: add a reverse member function to reverse the order of the nodes in the list
    4. Project 4: add a search member function to find the index of a given value in the list
    5. Project 5: add an insert member function to insert a new node at a specified position in the list
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// Definition of the LinkedList class based on Gaddis book, page 1135
// 1. Create a new class  LinkedList.h
class LinkedList
{
private:
// 2. Add a structure  ListNode  from the textbook
    struct ListNode
    {
        double value;
        ListNode *next;

        // Constructor
        ListNode(double value1, ListNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    // 3. Add a LinkNode pointer named  head
    ListNode *head;
public:
    // 6. In the constructor, initialize the  head  variable to  nullptr
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList();

    // 4. Create definitions for the constructor,  add,  and  isMember  functions
    void add(double value);
    bool isMember(double number) const;

    // 5.  Modify the list class you created in the previous challenge to add a  print  member function
    void print() const;

    // Project 3: List Reverse
    void reverse();

    // Project 4: List Search
     int search(double number) const;

    // Project 5: Member insertion by position
    void insert(double value, int pos);
};


#endif
