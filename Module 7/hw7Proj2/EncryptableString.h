/* EncryptableString.h - Homework 7, project 2
 * Author:     Jack Marriott
 * Module:     7
 * Problem statement:  Encryptable string class derived from std::string
 */
#ifndef _ENCRYPTABLE_STRING_
#define _ENCRYPTABLE_STRING_

#include <iostream>
#include <string>

// Reference: https://cplusplus.com/reference/string/string/

// EncryptableString class that is derived from the C++ string class with public base class access
class EncryptableString : public std::string
{

// no private members because just using parent string
//private:

public:
    // A constructor that takes a  string as a parameter and
    // passes it to the  string  (base class) constructor
    EncryptableString(const std::string &word) : std::string(word) {}

    // A constructor that takes a a C-string as a parameter and
    // passes it to the  string  (base class) constructor
    EncryptableString(const char* cword) : std::string(cword) {}

    // A member function which encrypts the string contained in the object by replacing
    // each letter with its successor in the ASCII ordering.
    void encrypt();

    // A getter function to get the string
    const std::string &getPhrase(void) const;

    // A setter function to update the string
    void setPhrase(const std::string& word);
};

#endif // _ENCRYPTABLE_STRING_
