// CS151 Fall 2025, Dynamic Allocation of an Array
// Author:   Jack Marriott
// Module:   3
// Homework: 3
// Project:  2
// Problem Statement: Demonstration of Dynamic Allocation Methods for 2D Arrays
//
// Algorithm:
//   1. 1D array of size nrows * ncols
//   2. Print contents, total, and average
//   3. Method 1: Long 1D array of consecutive rows in memory
//   4. Print contents, total, and average
//   5. Method 2: Array of arrays
//   6. Print contents of the array, total, and avg
//   7. Release DMA
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

string totAvg(int total, const int nElems);

int main()
{
    const int NROWS = 4;
    const int NCOLS = 5;

    // 1. Create a one-dimensional dynamic array of 20 ints and fill with random numbers from 1 to 99
    int *c = new int[NROWS * NCOLS];
    for (int i = 0; i < NROWS * NCOLS; i++)
        c[i] = 1 + rand() % 98; // fill with random numbers from 1 to 99

    // 2. Print contents of the array, total, and avg
    int total = 0;
    double avg;
    cout << setw(45) << "** Original array of 20 numbers **\n";
    for (int i = 0; i < NROWS * NCOLS; i++)
    {
        cout << c[i] << " ";
        total += c[i];
    }
    cout << "\n";
    string legend = totAvg(total, NROWS * NCOLS);
    cout << setw(35) << legend << "\n\n";

    // 3. Method 1: Long 1D array of consecutive rows in memory
    int *a = new int[NROWS * NCOLS];
    for (int i = 0; i < NROWS; i++)
    {
        for (int j = 0; j < NCOLS; j++)
        {
            a[i * NCOLS + j] = c[i * NCOLS + j];
        }
    }

    // 4. Print contents of the array, total, and avg
    cout << setw(45) << "*** Using that array as a 4 x 5 array ***\n";
    int grandTotal = 0;
    for (int i = 0; i < NROWS; i++)
    {
        total = 0;
        cout << "Row " << i << ":  ";
        for (int j = 0; j < NCOLS; j++)
        {
            cout << setw(2) << a[i * NCOLS + j] << " ";
            total += a[i * NCOLS + j];
        }
        legend = totAvg(total, NROWS * NCOLS);
        cout << " " << legend << "\n";
        grandTotal += total;
    }
    legend = totAvg(grandTotal, NROWS * NCOLS);
    cout << setw(50) << legend << "\n";

    // 5. Method 2: Array of arrays
    int **b = new int *[NROWS];
    for (int i = 0; i < NROWS; i++)
    {
        b[i] = new int[NCOLS];
        for (int j = 0; j < NCOLS; j++)
            b[i][j] = c[i * NCOLS + j];
    }

    // 6. Print contents of the array, total, and avg
    cout << "\n";
    cout << setw(45) << "*** Using an array-of-arrays ***\n";
    grandTotal = 0;
    for (int i = 0; i < NROWS; i++)
    {
        total = 0;
        cout << "Row " << i << ":  ";
        for (int j = 0; j < NCOLS; j++)
        {
            cout << setw(2) << b[i][j] << " ";
            total += b[i][j];
        }
        legend = totAvg(total, NROWS * NCOLS);
        cout << " " << legend << "\n";
        grandTotal += total;
    }
    legend = totAvg(grandTotal, NROWS * NCOLS);
    cout << setw(50) << legend << "\n\n";

    // 7. Release DMA
    delete[] c;
    delete[] a;
    for (int i = 0; i < NROWS; i++)
        delete[] b[i];
    delete[] b;
    return 0;
}

// Create a string legend with total value and average
string totAvg(int total, const int nElems)
{
    string legend = "";
    ostringstream oss;
    legend += "Total: ";
    legend += to_string(total);
    legend += ", Average: ";
    oss << setw(5) << fixed << setprecision(2) << (1.0 * total / nElems);
    legend += oss.str();
    return legend;
}
