/* PString.cpp - Homework 7, project 1
 * Author:     Jack Marriott
 * Module:     1
 * Problem statement:  Palindrome string class derived from std::string
 */
#include "PString.h"
#include <iostream>
#include <cctype>

bool PString::isPalindrome(void)
{
    
    // Initialize a pointer to the end and a pointer to the start
    std::string::iterator it1 = this->phrase.begin();
    std::string::iterator it2 = this->phrase.end();

    // Move back pointer to account for '\0' at end
    it2--;

    char c1, c2;

    // Compare all characters front-to-back
    while(it1 <= it2)
    {
        // Advance front pointer if character is non alphanumeric
        while (!isalnum(*it1) && (it1 != it2))
            ++it1;

        // Advance back pointer if character is non alphanumeric
        while (!isalnum(*it2) && (it1 != it2))
            --it2;

        // Only consider lower case
        c1 = tolower(*it1); 
        c2 = tolower(*it2);

        // Not a palindrome if any character comparison fails
        if (c1 != c2) return false;
        
        ++it1;
        --it2;
    }

    return true;
}

// Getter function for phrase
std::string PString::getPhrase(void) const
{
    return phrase;
}
