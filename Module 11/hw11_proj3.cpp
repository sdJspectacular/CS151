/* hw11_proj3.cpp - Recursive Test for Palindrome
 * Author:     Jack Marriott
 * Module:     11
 * Project:    HW, Project 3
 * Problem statement:  Recursively check to see if a string is a palindrome
 *
 * Algorithm:
 *   1. Write a function that checks to see if a phrase is a palindrome
 *      - use recursive character checking, starting from the outer edges
 *      - skip any character that is not a letter or number
 *      - ignore case for all valid characters
 *   2. Demonstrate program with a known set of test cases
 *   3. Allow user to enter their own test phrases
 *      - exit if user enters an empty line
 */
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

bool isPalindrome(string str, int lower, int upper);

int main()
{
    vector<string> words = {"reed", "oreo", "Kayak", "Deed", "1x2x3x4x5", "A Toyota's a Toyota.",
    "Stressed desserts.", "74 ABC ba47", "Never odd or even.", "A man, a plan, a canal --  Panama.",
    "Sit on a potato pan, Otis!", "Red roots to order", "Bob 7117 Bob"};

    cout << setw(40) << left << "    Phrase    " << setw(20) << left << "   Palindrome?   " << "\n";
    cout << setw(40) << left << "+------------+" << setw(20) << left << "+---------------+" << "\n";

    for (auto &wd : words)
    {
        cout << setw(40) << left << wd << setw(20) << boolalpha << isPalindrome(wd, 0, wd.length() - 1) << "\n";
    }

    cout << "\n";
    while (true)
    {
        string line;
        cout << "\nEnter your own string, or just enter to quit: \n";
        cout << ">> ";
        getline(cin, line);
        if (line.empty())
        {
            cout << "Goodbye!\n";
            break;
        }
    
        cout << "\nPhrase: " << line << "\n";
        cout << "Is palindrome? " << boolalpha << isPalindrome(line, 0, line.length() - 1) << "\n";
    }


    cout << "\n";

    return 0;
}

// Check to see if a phrase is a palindrome starting
// from the outer edges and iterating inward
// Case insensitive and skips non-letter characters
bool isPalindrome(string str, int lower, int upper)
{
    // Jump ahead from left when a character is non alpha numeric
    while ((lower < upper) && !isalnum(str[lower]))
        lower += 1;
    
    // Jump back from right when a character is non alpha numeric
    while ((lower < upper) && !isalnum(str[upper]))
        upper -= 1;

    // Indices crossed and has not been false, therefore must be true
    if (upper <= lower)
        return true;
    

    if (tolower(str[lower]) != tolower(str[upper]))
    {
        // letters not equal therefore not a palindrome
        return false;
    }
    else
    {
        // check the next two endpoints
        return isPalindrome(str, lower + 1, upper - 1);
    }
}
