/* hw11_proj2.cpp - Recursive Member Test
 * Author:     Jack Marriott
 * Module:     11
 * Project:    HW, Project 2
 * Problem statement:  Binary search variation to check if item is in sorted array
 *
 * Algorithm:
 *   1. Write a function using recursive binary search to find an element in an ordered array
 *      - base case: check mid point in array, stop if found
 *      - check remaining upper half if mid point is lower than search value
 *      - check remaining lower half if mid point is less than or equal to search value
 *   2. Write a wrapper function that uses binary search to check if a value is a member of an array
 *      - Only arguments are the array, it's size, and the value to search for
 *   3. Allow user to input an array and values to search for, returning true if found and false otherwise
 */
#include <iostream>
#include <sstream>

using namespace std;

int binarySearch(const int array[], int first, int last, int value);
bool isMember(const int array[], int size, int value);

int main()
{
    int size, value;

    string line;

    // Demonstrate the use of the function in a program that asks the user for the number
    // of elements in (the size of) an array of numbers, then to enter values into that
    // array, and finally prompts for value(s) to be searched for in that array.
    cout << "How many elements in the array?\n";
    cout << ">> ";
    getline(cin, line);
    {
        // Read the size
        stringstream ss(line);
        ss >> size;
    }

    cout << "\n";
    int values[size];

    cout << "Enter ordered elements separated by spaces:\n";
    cout << ">> ";
    getline(cin, line);
    {
        // Assign each value to the array.
        // Danger: no bounds checking here, could lead to segmentation fault
        stringstream ss(line);
        int i = 0;
        while (ss >> value)
        {
            values[i++] = value;
        }
    }

    cout << "\n";
    cout << "You entered:\n" << ">> ";

    for (auto &e : values)
        cout << e << " ";
    
    cout << "\n\n";
    cout << "What value(s) to search for?\n";
    cout << ">> ";
    getline(cin, line);
    {
        stringstream ss(line);
        int i = 0;
        while (ss >> value)
        {
            cout << "Value: " << value << ", found? " << boolalpha << isMember(values, size, value) << "\n";
        }
    }

    return 0;
}

// This is based on binary search function in page 942 of Gaddis book
int binarySearch(const int array[], int first, int last, int value)
{
    int mid;

    // Base case, indices overlap because did not find
    if (first > last)
        return -1;

    // compute mid point position in search array
    mid = (first + last) / 2;

    if (array[mid] == value)
    {
        // found it, return index position
        return mid;
    }

    if (array[mid] < value)
    {
        // Value is not in lower half, check upper half
        return binarySearch(array, mid + 1, last, value);
    }
    else
    {
        // Value is not in upper half, check lower half
        return binarySearch(array, first, mid - 1, value);
    }
}

// Check to see if value is found in array
// Uses recursive binary search and returns true if found, false if not found
bool isMember(const int array[], int size, int value)
{
    int idx = binarySearch(array, 0, size - 1, value);

    return (idx != -1);
}
