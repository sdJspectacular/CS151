/* lab11_proj1.cpp - Decimal to Binary
 * Author:     Jack Marriott
 * Module:     11
 * Project:    Lab, Project 1
 * Problem statement:  Decimal to Binary demonstration using iterative and recursive methods
 *
 * Algorithm:
 *   1. Create two decimal-to-binary functions, one using iteration, the other using recursion
 *   2. In the iterative function, build a string from right to left, with LSB in rightmost position
 *      - each bit is equal to modulo(value, 2)
 *      - at each iteration the value is divided by half
 *   3. In the recursive function, build a string from right to left, with LSB in rightmost position
 *      - the base cases are when the value is equal to either 1 or 0, return that value as a string
 *      - otherwise the function returns modulo(value, 2) plus itself with the argument value /2
 *   4. Add test cases including testing the recursive base cases
 */
#include <iostream>
#include <iomanip>

using namespace std;

string dec2binIter(int val);
string dec2binRecurs(int val);

int main()
{
    int val[] = {0, 1, 5, 32, 240, 682};

    cout << setw(5) << "Value" << setw(15) << "Iterative" << setw(15) << "Recursive" << "\n";
    cout << setw(5) << "-----" << setw(15) << "---------" << setw(15) << "---------" << "\n";

    for (auto &e : val)
    {
        cout << setw(5) << e << setw(15) << dec2binIter(e) << setw(15) << dec2binRecurs(e) << "\n";
    }

    cout << "\n";

    return 0;
}

string dec2binIter(int val)
{
    int rem;
    string result = "";  // empty string to initialize

    do
    {
        rem = val % 2;
        result.insert(0, to_string(rem));  // The binary bit is the remainder, pre-pend
        val /= 2;  // iterate with the half value
    } while (val != 0);  // Continue until hitting zero
    
    return result;
}

string dec2binRecurs(int val)
{
    if (val == 1)
    {
        // Base case: most significant bit
        // Also the case where the input is just 1
        return "1";
    }
    else if (val == 0)
    {
        // This only applies to the case of the input is 0
        return "0";
    }
    else
    {
        // The binary bit is the remainder, recursively call the
        // higher bits and pre-pend
        return dec2binRecurs(val/2) + to_string(val % 2);
    }
}
