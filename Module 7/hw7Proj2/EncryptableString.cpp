/* EncryptableString.h - Homework 7, project 2
 * Author:     Jack Marriott
 * Module:     7
 * Problem statement:  Encryptable string class derived from std::string
 */
#include "EncryptableString.h"
#include <iostream>
#include <cctype>

void EncryptableString::encrypt()
{
    // Initialize a pointer to the end and a pointer to the start
    std::string::iterator it1 = this->begin();
    std::string::iterator it2 = this->end();

    std::string encrypted = "";  // start with an empty string and build it

    // Encrypt all character one at a time
    while(it1 < it2)
    {
        // Skip any character that are not alphanumeric
        while (!isalnum(*it1) && (it1 != it2))
        {
            encrypted += *it1;  // non-alphanums just get concatenated to the string
            ++it1;
        }
       
        if (*it1 == 'z')
            encrypted += 'a';   // handle alphabetic rollover
        else if (*it1 == 'Z')
            encrypted += 'A';  // handle alphabetic rollover
        else if (*it1 == '9')
            encrypted += '0';  // handle numeric rollover
        else
            encrypted += (*it1 + 1);  // otherwise just encode with next letter/number
        
        ++it1;
    }

    // Update the word
    setPhrase(encrypted);
}

// Getter function for phrase
const std::string &EncryptableString::getPhrase(void) const
{
    return *this;
}

// Setter function for phrase
void EncryptableString::setPhrase(const std::string& word)
{
    *this = word;
}
