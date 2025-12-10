/* lab11_proj2.cpp - Binary to Decimal
 * Author:     Jack Marriott
 * Module:     11
 * Project:    Lab, Project 2
 * Problem statement:  Binary to Decimal demonstration using iterative and recursive methods
 *
 * Algorithm:
 *   1. Create two binary-to-decimal functions, one using iteration, the other using recursion
 *   2. In the iterative function, build the integer value from left to right, with MSB in leftmost position
 *      - compute a running sum initilized to zero
 *      - multiply the sum by 2
 *      - add the remaining leftmost bit
 *   3. In the recursive function, slice the string from the beginning each time until there are no lower bits left
 *      - the base cases is when the string is empty, in which case we return 0
 *      - otherwise the function returns the value of the current lower bit plus twice the function with the remaining substring as argument
 *   4. Add test cases to revert back the previous test cases
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int bin2decIter(string value);
int bin2decRecurs(string value);

int main()
{
    // Test values
    string values[] = {"0", "1", "101", "100000", "11110000", "1010101010"};

    cout << setw(15) << "Value" << setw(15) << "Iterative" << setw(15) << "Recursive" << "\n";
    cout << setw(15) << "-----" << setw(15) << "---------" << setw(15) << "---------" << "\n";

    for (auto &e : values)
    {
        // Check test values using both iterative and recursive functions
        cout << setw(15) << e << setw(15) << bin2decIter(e) << setw(15) << bin2decRecurs(e) << "\n";
    }

    cout << "\n";

    return 0;
}

int bin2decIter(string value)
{
    int sum = 0;

    for (int i = 0; i < value.length(); ++i)
    {
        sum *= 2;               // Progressively raise sum to the 2^n power
        sum += value[i] - '0';  // Add MSB
    }
    return sum;
}

int bin2decRecurs(string value)
{
    // If value string is empty, we are done
    if (value.empty())
        return 0;

    // Grab LSB
    int this_bit = value.back() - '0';
    
    // Grab portion of the string from MSB to (LSB - 1)
    string substring = value.substr(0, value.length() - 1);
    
    // This works when slicing from the beginning until there are no lower bits left
    return (2 * bin2decRecurs(substring) + this_bit);
}
