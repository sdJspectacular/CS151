/*
   1. Project 1: design a linked list class with two member functions: add and isMember
      - The add function adds a new node containing a double value to the head of the list
      - The isMember function checks whether a given double value is present in the list


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
};

LinkedList::~LinkedList()
{
    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
#endif
