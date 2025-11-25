/* SimpleVector.h - Simple Vector with added functionality
 * Author:     Jack Marriott
 * Module:     13
 * Project:    Homework #2
 */

#pragma once

#include <iostream>
using namespace std;

template <class T>
class SimpleVector
{

protected:
    T *aptr;
    int size = 0;     // number of elements in vector
    int capacity = 0; // size of underlying array

public:
    SimpleVector(int = 0);              // Constructor
    SimpleVector(const SimpleVector &); // Copy constructor
    ~SimpleVector();                    // Destructor

    int getCapacity() const
    {
        return capacity;
    }

    int getSize() const
    {
        return size;
    }

    // Add element to the end of the vector
    void push_back(const T &value);

    // Removes the last element in the vector
    T pop_back();
};

//*************************************************************
//         Constructor for EnhancedSimpleVector class         *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int new_capacity)
{
    size = 0;                // size is 0 initially, meaning no elements
    capacity = new_capacity; // the number of elements in the underlying array
    aptr = new T[capacity];  // allocate memory for the array

    // Clear the contents of the array
    for (int count = 0; count < capacity; count++)
    {
        *(aptr + count) = T();
    }
}

//**************************************************
//     Copy Constructor for SimpleVector class     *
//**************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{

    capacity = obj.capacity;
    aptr = new T[capacity];
    for (int count = 0; count < capacity; count++)
    {
        *(aptr + count) = *(obj.aptr + count);
    }
}

//***********************************************
//     Destructor for SimpleVector class        *
//***********************************************
template <class T>
SimpleVector<T>::~SimpleVector()
{

    if (capacity > 0)
    {
        delete[] aptr;
    }
}

// The push_back function should throw an exception if the array is full
// (size of the vector equals the capacity of the array).  Otherwise it
// accepts an argument and inserts that element into the next available
// position in the array, increasing the vector's size by 1.
template <class T>
void SimpleVector<T>::push_back(const T &value)
{
    if (size >= capacity)
    {
        throw out_of_range("push_back() called on full vector");
    }

    // Add the new element
    aptr[size] = value;
    size++;
}

// Removes the last element in the vector,
// effectively reducing the container size by one.
// The pop_back function takes no parameter and removes the last
// element from the array, decrements the size, and returns the
// value popped from the vector.  It should throw an exception if the
// size is 0, meaning that the vector is empty.
template <class T>
T SimpleVector<T>::pop_back()
{
    T val;
    if (size == 0)
    {
        throw out_of_range("pop_back() called on empty vector");
    }
    else
    {
        val = aptr[--size];
    }

    return val;
}
