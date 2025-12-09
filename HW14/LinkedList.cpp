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
#include "LinkedList.h"

// 5. Create a .cpp file which will define the member functions

// The add function adds a new node containing <value> to the head of the list
void LinkedList::add(double value)
{
    // 7. In the  add  function use: head = ListNode(value, head);

    if (head == nullptr)
    {
        // Add to head if list is empty
        head = new ListNode(value);
    }
    else
    {
        // Link the new node to the current head
        head = new ListNode(value, head);
    }
}

bool LinkedList::isMember(double number) const
{
    // 8. Create a  ListNote  pointer and initialize to  head
    ListNode *current = head;

    // 8. Traverse the list
    while (current != nullptr)
    {
        if (current->value == number)
        {
            return true; // If the value found is equal to the parameter passed to  isMember,  then return  true.
        }
        current = current->next;
    }

    return false; //  If at the end of the list, then return  false.
}

// Destructor to free allocated memory
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

// Print all the values in the list, even if empty
void LinkedList::print() const
{
    ListNode *current = head;
    if (head == nullptr)
    {
        // When the list is empty, print something like "(empty)"  or  "(null)".
        cout << "(null)";
        return;
    }

    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}

// The member function rearranges the nodes in the list so that their order is reversed.
// You should do this without creating or destroying nodes.
// (Hint:  Traverse the list just changing node values and/or pointers.)
void LinkedList::reverse()
{
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    head = prev; // Update head to new first element
}

// Returns the position of a number number on the list.  If number is not found on the list,
// the search returns -1. 
int LinkedList::search(double number) const
{
    ListNode *current = head;
    int i = 0;

    while (current != nullptr)
    {
        if (current->value == number)
        {
            return i; // Return the index when found
        }
        current = current->next;
        i++;
    }

    return -1; // Not found, return -1
}

// Function for inserting a new item at a specified position
void LinkedList::insert(double value, int pos)
{
    if (pos < 0)
    {
        return; // Invalid position
    }

    if (pos == 0)
    {
        add(value); // Insert at head
        return;
    }

    // Traverse the list until the position before the insertion point
    ListNode *current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; i++)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        return; // Position is out of bounds
    }

    // Insert new node at the specified position
    current->next = new ListNode(value, current->next);
}

