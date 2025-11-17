/* hw11_proj1.cpp - Iterative Factorial
 * Author:     Jack Marriott
 * Module:     11
 * Project:    HW, Project 1
 * Problem statement:  Demonstrate a factorial computation using iteration
 *
 * Algorithm:
 *   1. Create two factorial function that multiplies from 1 through N
 *      - The function uses a for loop, up to and including N
 *      - The function returns 0 if the input is 0 or negative
 *      - The function returns long double data type
 */
#include <iostream>
#include <sstream>

using namespace std;

long long factorial(int val);

int main()
{
    string line;
    int choice;

    while (true)
    {
        // prompt for number by the user, call your function, then print the value returned and loop back to prompt for another number
        cout << "\nEnter a number, or -1 to quit:\n";
        cout << ">> ";
        getline(cin, line);
        {
            stringstream ss(line);
            ss >> choice;
        }
        // Stop looping when the user enters a negative number
        if (choice == -1)
            break;

        cout << "Factorial: " << factorial(choice) << "\n";
    }
    cout << "\n";
    return 0;
}

long long factorial(int val)
{
    long long prod = 1;

    // Make sure that your answer doesn't go negative or is too small to make sense
    if (val <= 0)
        return 0;
    
    // Multiply up starting from 1
    for (int i = 1; i <= val; ++i)
    {
        prod *= i;
    }

    return prod;
}
