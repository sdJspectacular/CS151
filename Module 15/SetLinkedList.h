/* SetLinkedList.h - Emulates a set in C++
 * Author:     Chris Merrill
 * Module:     15
 * Project:    Lab
 * Problem statement:  Use a linked list to create a class template which
 *      performs the following set functions:
 *
 *    constructor - creates an empty set
 *    contains - returns true if an item is in the set (uses = operator)
 *    insert - adds an item (in sorted order) to the set (duplicates not allowed)
 *    display - shows the contents of the set on the screen
 *    toVector - returns a vector with the elements contained in the set
 *    setUnion - returns another set containing all items from two sets
 *    setIntersect - returns another set containing items only in both sets
 *
 *  Functions to be added in this lab:
 *      size - returns the number of elements in this (the calling) set
 *      minus - returns another set containing all elements in calling set that
 *              aren't in the parameter set
 *      equals - returns true if both sets contain the same elements
 *      clear - empties the contents of a set
 *
 */

#pragma once

#include <vector>
using namespace std;

// Node for each element in the set
template <typename T>
struct SetNode
{

    T data;
    SetNode *next;

    SetNode(T new_data, SetNode *link)
    { // full constructor
        data = new_data;
        next = link;
    }
};

template <class T>
class Set
{

private:
    SetNode<T> *head;

public:
    Set(); // no-arg constructor
    bool contains(T search_item) const;
    bool insert(T new_item);
    Set<T> setIntersect(const Set<T> other_set) const;
    Set<T> setUnion(const Set<T> other_set) const;
    void display() const;
    vector<T> *toVector() const;
    /*************** Add your functions below this line **************/
    int size() const;
    Set<T> minus(const Set<T> other_set) const;
    bool equals(const Set<T> other_set) const;
    void clear();
};

// No-argument constructor creates an empty set (linked list)
template <class T>
Set<T>::Set()
{
    head = nullptr;
}

// Returns true if the set contains a specified data element
template <typename T>
bool Set<T>::contains(T search_item) const
{
    SetNode<T> *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->data == search_item)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Add a data element to a sorted list.
template <typename T>
bool Set<T>::insert(T new_item)
{

    if (contains(new_item))
        return false; // already in the list

    // Add to front of the list of if the list is empty or comes before first item.
    if (head == nullptr || (head->data > new_item))
    {
        head = new SetNode<T>(new_item, head);
        return true; // item was added
    }

    // Find the position to insert.  Keep pointers before and after insertion point.
    SetNode<T> *after = head;     // will come after the new node
    SetNode<T> *before = nullptr; // node prior to the insertion point
    while (after != nullptr && after->data <= new_item)
    {
        before = after;
        after = after->next;
    }
    before->next = new SetNode<T>(new_item, after);
    return true;
}

// Create a third set which is the intersection of two other sets.
// Intersection will contain only those elements in both sets.
template <typename T>
Set<T> Set<T>::setIntersect(const Set<T> other_set) const
{

    Set<T> common_set; // New set to return
    SetNode<T> *pos = head;
    while (pos != nullptr)
    {
        if (other_set.contains(pos->data))
            common_set.insert(pos->data);
        pos = pos->next;
    }
    return common_set;
}

// Return the union of this set with another set.
template <typename T>
Set<T> Set<T>::setUnion(const Set<T> other_set) const
{

    Set<T> union_set; // new set to be returned

    // Add contents of calling object set to the new set
    SetNode<T> *pos = head;
    while (pos != nullptr)
    {
        union_set.insert(pos->data);
        pos = pos->next;
    }

    // Add the elements of the "other_set", avoid duplicates.
    pos = other_set.head;
    while (pos != nullptr)
    {
        union_set.insert(pos->data);
        pos = pos->next;
    }
    return union_set;
}

// Display the contents of this set on the console.
template <typename T>
void Set<T>::display() const
{
    SetNode<T> *ptr = head;
    if (ptr == nullptr)
    {
        cout << "(null)";
    }
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Return the contents of this set in a vector.
template <typename T>
vector<T> *Set<T>::toVector() const
{
    vector<T> *items = new vector<T>();
    SetNode<T> *ptr = head;
    while (ptr != nullptr)
    {
        items->push_back(ptr->data);
        ptr = ptr->next;
    }
    return items;
}

/*************** Add your functions below this line **************/
/*
Functions to be added in this lab:
 *      size - returns the number of elements in this (the calling) set
 *      minus - returns another set containing all elements in calling set that
 *              aren't in the parameter set
 *      equals - returns true if both sets contain the same elements
 *      clear - empties the contents of a set
 */

// 1. Create a new template function named minus, returns new set
// containing every element in calling set which is not in  other_set
template <typename T>
Set<T> Set<T>::minus(const Set<T> other_set) const
{
    Set<T> new_set;
    SetNode<T> *current = head;

    // Traverse the calling set
    while (current)
    {
        // Check each element in the calling set, one at a time, to see if it is in other_set
        if (!other_set.contains(current->data))
        {
            // Not in other_set, thus part of the difference
            new_set.insert(current->data);
        }
        current = current->next;
    }
    return new_set;
}

// 2. Create a size template function which returns the number of elements (nodes) in the calling set
template <typename T>
int Set<T>::size() const
{
    int size = 0;
    SetNode<T> *current = head;

    // Traverse the list until reaching nullptr
    while (current)
    {
        current = current->next;
        ++size;
    }

    return size;
}

// 3. Create an equals template function which returns true if every element in
// the calling set is also in the set passed as a parameter.
template <typename T>
bool Set<T>::equals(const Set<T> other_set) const
{
    SetNode<T> *current = head;

    // Traverse the calling set
    while (current)
    {
        // Check if each element in the calling set is in other_set
        if (!other_set.contains(current->data))
        {
            return false; // False because one element does not match
        }
        current = current->next;
    }
    return true; // True because all elements matched
}
// 4. Create a clear template function which removes all elements from the calling set
template <typename T>
void Set<T>::clear()
{
    SetNode<T> *current = head;
    SetNode<T> *next_node;

    // Traverse the list and delete each node
    while (current)
    {
        next_node = current->next;
        delete current; // Don't forget to return all allocated memory
        current = next_node;
    }
    head = nullptr; // The calling set should be empty (the  head  pointer equal to  nullptr)
}
