/* lab13_proj2.cpp - Accumulator
 * Author:     Jack Marriott
 * Module:     13
 * Project:    Lab, Project 2
 * Problem statement:  Compute accumulated value of elements in a vector
 *
 * Algorithm:
 *   1. Write a template function that finds the accumulated value of the elements in a vector
 *      - if the vector data type is numeric, output a total sum of elements
 *      - if the vector data type is string, output a concatenated string
 *   2. Demonstrate using at least two numeric and one string data types
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>

using namespace std;

// A template function that forms and returns the "sum" of all items in the  vector v  passed to it. 
template<typename T>
T accum(vector<T> v);


int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> b = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5};
    vector<string> c = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    cout << "Vector a: ";
    for (auto e : a)
    {
        cout << e << " ";
    }
    cout << "\n";
    cout << "Data type: " << typeid(a[0]).name() << "\n";
    cout << "Vector sum: " << accum(a) << "\n\n";

    cout << "Vector b: ";
    for (auto e : b)
    {
        cout << e << " ";
    }
    cout << "\n";
    cout << "Data type: " << typeid(b[0]).name() << "\n";
    cout << "Vector sum: " << accum(b) << "\n\n";

    cout << "Vector c: ";
    for (auto e : c)
    {
        cout << e << " ";
    }
    cout << "\n";
    cout << "Data type: " << typeid(c[0]).name() << "\n";
    cout << "Vector sum: "  << accum(c) << "\n\n";

    return 0;
}

// A template function that forms and returns the "sum" of all items in the  vector v  passed to it. 
template<typename T>
T accum(vector<T> v)
{
    // For any type  T,  the expression  T( )  yields the "zero" value or an object
    // created by the default constructor for that type
    T sum = T();
    for (auto e : v)
    {
        sum += e;
    }
    return sum;
}
