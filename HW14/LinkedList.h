/*
   1. Project 1: design a linked list class with two member functions: add and isMember
      - The add function adds a new node containing a double value to the head of the list
      - The isMember function checks whether a given double value is present in the list


*/
#include <iostream>

using namespace std;

// Definition of the LinkedList class based on Gaddis book, page 1149
class LinkedList
{
private:
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
    ListNode *head;
public:
    LinkedList()
    {
        head = nullptr;
    }
    ~LinkedList();
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

// The add function adds a new node containing <value> to the head of the list
void LinkedList::add(double value)
{
    // Create the new node
    ListNode *newNode = new ListNode(value);

    if (head == nullptr)
    {
        // Add to head if list is empty
        head = newNode;
    }
    else
    {
        // Link the new node to the current head
        newNode->next = head;
        head = newNode;
    }
}

bool LinkedList::isMember(double number) const
{
    ListNode *current = head;

    // Walk the list
    while (current != nullptr)
    {
        if (current->value == number)
        {
            return true;  // found it
        }
        current = current->next;
    }

    return false;  // did not find it
}
