/* LinkedList.h - Generic class allowing representation of a linked list
 * Author:     Chris Merrill
 * Module:     14
 * Project:    Lab
 * Problem statement:  This file contains the definition for a generic
 *    Node class and a generic LinkedList class.  Enhance an generic LinkedList.h
 *    class with several functions to make the class more usable.
 *
 *    Functions should throw a run-time exception if there would be confusion between
 *    what is returned (successful) and something couldn't be returned.
 *
 * Algorithm:
 *    Classes already included are Node<T> and LinkedList<T>
 *    Functions already given are:  full constructor, addFirst, addLast, add,
 *        getFirst, getLast(), get, indexOf, getSize, isEmpty, removeFirst,
 *        removeLast, and clear
 *
 *    Functions to be written are:
 *        display, remove, removeAt, lastIndexOf, contains, and set
 *
 *    Requirements:
 *    1. Place these new functions at the bottom of the file.
 *    2. This LinkList is generic, so each of your functions should be a template.
 *    3. Add function display() to display the contents of the list on the console
 *        - print "(null)" if the list is empty
 *    4. Add function remove(T myData) to remove a node with a specific data value
 *       - return  false  if the element is not found,  true  if removed 
 *       - don't forget to delete the removed node
 *    5. Add function removeAt(int index) to remove a node at a specific index or position in the list
 *       - return the element removed if successful, throw and catch an exception if invalid location
 *       - don't forget to delete the removed node
 *    6. Add function lastIndexOf(T myData) to find the last index of a specific data element which appears more than once in the list
 *       - return -1 if element is not found
 *    7. Add function contains(T myData) to determine if the list contains a specific data element
 *       - return  true  if found,  false  if not found
 *    8. Add function set(int index, T myData) to modify or set the data value of a node at a specific index
 *       - return the old element at that index (if replaced) or T( ) if unsuccessful
 */

#pragma once

#include <iostream>
#include <stdexcept> // catch run-time errors
using namespace std;

/******************************
 *                            *
 *  Template for Node class   *
 *                            *
 ******************************/
template <class T>
class Node
{
public:
    T data;        // value or object stored in the node
    Node<T> *next; // pointer to the next node

    // No-arg constructor
    Node()
    {
        this->data = T();
        next = nullptr;
    }

    // Constructor with one parameter
    Node(T myData)
    {
        this->data = myData; // stores value in node's data field
        next = nullptr;
    }
};

/*****************************************
 *                                       *
 *   Template for the LinkedList class   *
 *                                       *
 *****************************************/
template <class T>
class LinkedList
{

private:
    Node<T> *head, *tail; // pointers to first and last nodes
    int size;             // number of nodes in this list

public:
    // Prototypes of functions already present
    LinkedList(); // constructor

    void addFirst(T myData); // add an element to the list
    void addLast(T myData);
    void add(int index, T myData);

    T getFirst() const; // accessors
    T getLast() const;
    T get(int index) const;
    int indexOf(T myData) const;
    int getSize() const;
    bool isEmpty() const;

    // T removeFirst() throw(runtime_error);  // this is not allowed in C++17 and later
    // T removeLast() throw(runtime_error);   // this is not allowed in c++17 and later
    T removeFirst() noexcept(false); // indicates that the function can throw exceptions
    T removeLast() noexcept(false);
    void clear();

    // Function prototypes to be written in this lab
    void display() const;
    bool remove(T myData);
    T removeAt(int index);
    int lastIndexOf(T myData) const;
    bool contains(T myData) const;
    T set(int index, T myData);
};

/************************************
 *                                   *
 *     Function implementations      *
 *                                   *
 *************************************/

// Constructor
template <typename T>
LinkedList<T>::LinkedList()
{ // An empty list
    head = tail = nullptr;
    size = 0;
}

// Add node to beginning of the list
template <typename T>
void LinkedList<T>::addFirst(T myData)
{
    Node<T> *newNode = new Node<T>(myData); // Create new node and ptr
    newNode->next = head;                   // Assign value of head ptr to next ptr of new node
    head = newNode;                         // Set head to point at new node
    size++;                                 // increment size of LinkedList

    if (tail == nullptr)
        tail = head; // set tail ptr to new node if list was empty
}

// Add node to the end of the list
template <typename T>
void LinkedList<T>::addLast(T myData)
{
    if (tail == nullptr)
    {                                      // list is empty
        head = tail = new Node<T>(myData); // point head and tail to new node
    }
    else
    {
        tail->next = new Node<T>(myData); // create new node
        tail = tail->next;                // set tail ptr to new node
    }
    size++;
}

// Add node at specific index
template <typename T>
void LinkedList<T>::add(int index, T myData)
{
    if (index == 0)
    { // add node at beginning of list
        addFirst(myData);
    }
    else if (index >= size)
    { // add node at end of list
        addLast(myData);
    }
    else
    {                            // insert this element between two nodes
        Node<T> *current = head; // loop to node before this one
        for (int i = 1; i < index; i++)
            current = current->next;
        Node<T> *temp = current->next; // one after this one
        current->next = new Node<T>(myData);
        (current->next)->next = temp;
        size++;
    }
}

// Get data from first node
template <typename T>
T LinkedList<T>::getFirst() const
{
    if (size == 0)
        throw runtime_error("Index out of range"); // no nodes in the list
    return head->data;                             // retrieve value in first node
}

// Get data from last node
template <typename T>
T LinkedList<T>::getLast() const
{
    if (size == 0)
        throw runtime_error("Index out of range"); // no nodes in this list
    return tail->data;                             // retrieve value in last node
}

// Get node at the specified index
template <typename T>
T LinkedList<T>::get(int index) const
{
    if (index < 0 || index > size - 1)
        throw runtime_error("Index out of range");

    Node<T> *ptr = head; // walk list
    for (int i = 0; i < index; i++)
        ptr = ptr->next; // point to next node

    return ptr->data; // get value if found
}

// Get the index of a specific node
template <typename T>
int LinkedList<T>::indexOf(T myData) const
{
    Node<T> *ptr = head;
    for (int i = 0; i < size; i++)
    {
        if (ptr->data == myData) // walk list to find value
            return i;
        ptr = ptr->next;
    }
    return -1; // return -1 if value not found
}

// Get the number of nodes in the list (number added - number removed)
template <typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

// Remove first node from list
template <typename T>
T LinkedList<T>::removeFirst() noexcept(false)
{
    if (size == 0)
        throw runtime_error("No nodes in the list");

    Node<T> *temp = head; // create new ptr temp - point to same place as head
    head = head->next;    // point to the next object beyond the first
    size--;
    if (head == nullptr)
    {
        tail = nullptr;
    }
    T myData = temp->data;
    delete temp;   // delete node temp is pointing to
    return myData; // may or may not use this value
}

// Remove last node from the list
template <typename T>
T LinkedList<T>::removeLast() noexcept(false)
{
    if (size == 0)
    {
        throw runtime_error("No nodes in the list");
    }
    else if (size == 1)
    {
        Node<T> *temp = head;
        head = tail = nullptr;
        size = 0;
        T myData = temp->data;
        delete temp;   // delete node temp is pointing to
        return myData; // may or may not use this value
    }
    else
    {
        Node<T> *current = head;           // set current to point at what head points at
        for (int i = 0; i < size - 2; i++) // walk list moving current ptr to end
            current = current->next;

        Node<T> *temp = tail;
        tail = current;
        tail->next = nullptr;
        size--;
        T myData = temp->data;
        delete temp;
        return myData;
    }
}

// Clear the list - takes time but frees up memory
template <typename T>
void LinkedList<T>::clear()
{
    while (head != nullptr)
    {                        // if still a node in list
        Node<T> *ptr = head; // set ptr to what head points at
        head = head->next;   // point head at next node
        delete ptr;          // delete the node ptr is pointing to
    }
    head = tail = nullptr; // the empty list
    size = 0;
}

// See if the list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == nullptr; // no nodes in list
}

// display the contents of the list on the console
// print "(null)" if the list is empty
template <typename T>
void LinkedList<T>::display() const
{
    if ((size == 0) || (head == nullptr))
    {
        cout << "(null)";
        return;
    }

    int i = 0;
    Node<T> *current = head;
    while (current)
    {
        cout << "(" << i++ << ", " << current->data << ") ";
        current = current->next;
    }
}

// remove a node with a specific data element (e.g., 25.0)
// return  false  if the element is not found,  true  if removed
// don't forget to delete the removed node
template <typename T>
bool LinkedList<T>::remove(T myData)
{
    if (size == 0)
        return false; // if list is empty, value is not found

    // Are we removing the head node?
    if (head->data == myData)
    {
        removeFirst();
        return true;
    }

    // Removing any other node
    Node<T> *prev = head;
    Node<T> *current = head->next;

    // Walk the list
    while (current != nullptr)
    {
        // Stop if we find the value
        if (current->data == myData)
        {
            prev->next = current->next;
            if (current == tail)
            {
                tail = prev;
            }
            delete current; // delete the node to be removed
            size--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false; // default return value if not found
}

// remove a node at a specific index or position in the list
//  return the element removed if successful, throw and catch an exception if invalid location
//  don't forget to delete the removed node
template <typename T>
T LinkedList<T>::removeAt(int index)
{
    // Empty list or invalid index
    if ((index < 0) || (index >= size))
        throw runtime_error("Invalid index");

    T exData;

    if (index == 0) // Remove head node
    {
        // Removing head node (list size >= 1 because of check above)
        Node<T> *garbage = head;
        exData = garbage->data;
        head = head->next;
        delete garbage;

        // If list is empty, both head and tail should point to null
        if (head == nullptr)
            tail = nullptr;
    }
    else // Remove all other nodes
    {
        Node<T> *prev = head;

        // Walk up to to node preceding the one to be removed
        for (int i = 0; i < (index - 1); i++)
            prev = prev->next;

        Node<T> *garbage = prev->next;
        exData = garbage->data;
        prev->next = garbage->next; // re-connect nodes
        delete garbage;             // delete the node to be removed

        // Update tail if we removed the last node
        if (prev->next == nullptr)
            tail = prev;
    }

    // reduce size by 1
    --size;
    return exData;
}

// find the last index of a specific data element which appears more than once in the list
// return -1 if element is not found
template <typename T>
int LinkedList<T>::lastIndexOf(T myData) const
{
    int idx = 0;
    int indexOf = -1;

    Node<T> *current = head;

    // Walk the complete list
    while (current != nullptr)
    {
        if (current->data == myData)
            indexOf = idx; // Found it, grab the index

        current = current->next;
        idx++;
    }

    return indexOf;
}

// determine if the list contains a specific data element
// return  true  if found,  false  if not found
template <typename T>
bool LinkedList<T>::contains(T myData) const
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        if (current->data == myData)
            return true;

        current = current->next;
    }

    return false;
}

// modify or set the data value of a node at a specific index
// return the old element at that index (if replaced) or T() if unsuccessful
template <typename T>
T LinkedList<T>::set(int index, T myData)
{
    // Validate index
    if (index < 0 || index >= size)
        return T(); // unsuccessful

    // Walk to the specified index
    Node<T> *current = head;
    for (int i = 0; i < index; i++)
        current = current->next;

    // Save the old data
    T oldData = current->data;

    // Set the new data
    current->data = myData;

    // Return the old data
    return oldData;
}
