/* hw12_proj1.cpp - Analysis of sorting algorithms
 * Author:     Jack Marriott
 * Module:     12
 * Project:    HW, Project 1
 * Problem statement:  Measure the runtime of a sorting algorithm by counting comparisons
 *
 * Algorithm:
 *   1. Create an abstract base class AbstractSort
 *      - Contains a comparison counter and a compare function
 *      - The compare function compares two elements and increments the counter
 *      - The compare function returns -1, 0, or 1 if result is less than, equal to, or greater than
 *      - Contains functions to get and reset the comparison counter
 *      - Contains a pure virtual sort function
 *   2. Create a subclass QuickSort that implements the sort function using the QuickSort algorithm
 *      - The QuickSort class overrides the sort function
 *      - The sort function uses a helper function quickSort and a partition function
 *      - Both quickSort and partition use the compare function in the base class
 *      - Both quickSort and partition are based on the Gaddis textbook implementation
 *      - The sort function resets the comparison counter and calls the quickSort helper function
 *      - The quickSort function recursively sorts the array using the partition function
 *      - The partition function rearranges the array elements around a pivot and uses the compare function
 *        to count comparisons
 *   3. In main, create two arrays of different sizes, fill them with random numbers
 *      - Sort each array using QuickSort
 *      - After sorting, print the number of comparisons made, along with expected and worst case values
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Class used to analyze the number of comparisons performed by a sorting algorithm.
class AbstractSort
{
protected:
    // The class should have a counter which tracks the number of times the compare function
    // is called while sorting the array
    int comparisons = 0;

public:
    // Function compare is capable of comparing two array elements and tracks the
    // number of comparisons performed
    // k, m are the indices of the two elements to be compared
    int compare(int arr[], int k, int m)
    {
        // Increment the number of times called
        comparisons++;

        if (arr[k] < arr[m])
            return -1;
        else if (arr[k] == arr[m])
            return 0;
        else
            return 1;
    }

    // A member function which can be called after the sorting is done to retrieve
    // the number of comparisons that were performed while sorting the array
    int getComparisons() const
    {
        return comparisons;
    }

    // A member function to reset the comparison counter to zero
    void resetComparisons()
    {
        comparisons = 0;
    }

    // Pure virtual member sort function
    // When overridden, will sort the array by calling the compare function to
    // determine the relative order of pairs of numbers
    virtual void sort(int arr[], int size) = 0;
};

// A subclass of AbstractSort which uses a simple sorting algorithm to implement the sort function
class QuickSort : public AbstractSort
{
public:
    // Wrapper function to override the sort function
    void sort(int arr[], int size) override
    {
        // Start the comparison counter from zero
        resetComparisons();

        // Implementation of the QuickSort algorithm
        quickSort(arr, 0, size - 1);
    }

    // partition: implementation from Gaddis book, page 944
    int partition(int arr[], int start, int end)
    {
        int pivot = arr[start]; // pivot value
        int i = start;          // index of the lower sub-array

        for (int j = start + 1; j <= end; j++)
        {
            comparisons++;
            // Use the compare function to determin if arr[j] < pivot value
            if (compare(arr, j, start) < 0)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[start], arr[i]);
        return i;
    }

    // quickSort: implementation from Gaddis book, page 944
    // Time complexity:
    // - Average: O(n log n)
    // - Worst case: O(n^2)
    void quickSort(int arr[], int start, int end)
    {
        if (start < end)
        {
            // p is partitioning index, arr[p] is now at the right place
            int p = partition(arr, start, end);

            // Separately sort the elements before and after the pivot point
            quickSort(arr, start, p - 1);  // Sort the left sub-array
            quickSort(arr, p + 1, end); // Sort the right sub-array
        }
    }
};

int main()
{
    // Create two arrays, one with an unsorted set of 20 numbers, and
    // the second with an unsorted set of numbers but of a different size

    const int SIZE1 = 20;
    const int SIZE2 = 40;
    
    int arr1[SIZE1] = {0};
    int arr2[SIZE2] = {0};

    // Fill arr1 with random numbers
    for (auto &e : arr1)
    {
        e = rand() % 100;
    }

    cout << "Array 1 before sorting: ";
    for (auto e : arr1)
    {
        cout << e << " ";
    }
    cout << "\n";

    QuickSort qsort1;
    qsort1.sort(arr1, SIZE1);

    cout << "Array 1 after sorting : ";
    for (auto e : arr1)
    {
        cout << e << " ";
    }
    cout << "\n\nNumber of comparisons for Array 1\n";
    cout << "Actual    : " << qsort1.getComparisons() << "\n";
    cout << "Expected  : " << SIZE1 * static_cast<int>(log2(SIZE1)) << "\n";
    cout << "Worst case: " << (SIZE1 * SIZE1) / 2 << "\n\n";

    // Fill arr2 with random numbers
    for (auto &e : arr2)
    {
        e = rand() % 100;
    }

    cout << "\nArray 2 before sorting: ";
    for (auto e : arr2)
    {
        cout << e << " ";
    }
    cout << "\n";

    QuickSort qsort2;
    qsort2.sort(arr2, SIZE2);
    cout << "Array 2 after sorting : ";
    for (auto e : arr2)
    {
        cout << e << " ";
    }

    cout << "\n\nNumber of comparisons for Array 2\n";
    cout << "Actual    : " << qsort2.getComparisons() << "\n";
    cout << "Expected  : " << SIZE2 * static_cast<int>(log2(SIZE2)) << "\n";
    cout << "Worst case: " << (SIZE2 * SIZE2) / 2 << "\n\n";

    return 0;
}
