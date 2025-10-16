#ifndef _ENCRYPTABLE_STRING_
#define _ENCRYPTABLE_STRING_

#include <iostream>
#include <string>

// Reference: https://cplusplus.com/reference/string/string/

// EncryptableString class that is derived from the C++ string class with public base class access
class EncryptableString : public std::string
{
private:
    std::string phrase;

public:
    // A constructor that takes a  string  object (or a C-string)  as a parameter and
    // passes it to the  string  (base class) constructor
    EncryptableString(std::string word) : phrase(word) {}

    // A member function which determines whether the string is a palindrome
    bool isPalindrome(void);

    // A getter function
    std::string getPhrase(void) const;
};

#endif // _ENCRYPTABLE_STRING_
