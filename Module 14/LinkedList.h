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

    T removeFirst() throw(runtime_error); // remove an element or clear
    T removeLast() throw(runtime_error);
    void clear();

    // Function prototypes to be written in this lab
    bool contains(T myData) const;
    int lastIndexOf(T myData) const;
    bool remove(T myData);
    T removeAt(int index);
    T set(int index, T myData);
    void display() const;
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
T LinkedList<T>::removeFirst() throw(runtime_error)
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
T LinkedList<T>::removeLast() throw(runtime_error)
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
