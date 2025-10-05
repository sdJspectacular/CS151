#include "EString.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

#undef _DBG_

// Regular constructor
EString::EString(const char *s)
{
#ifdef _DBG_
    std::cout << "calling constructor\n";
#endif
    size = strlen(s);
    string = new char[size + 1]; // add 1 for the null terminator
    strcpy(string, s);
}

// Copy Constructor to create a deep copy of the character array
//   Called whenever
//   1. An object is initialized by another object of the same type
//   2. An object is passed by value as a function argument
//   3. An object is returned by value from a function.
EString::EString(const EString &rhs)
{
#ifdef _DBG_
    std::cout << "calling copy constructor\n";
#endif
    size = rhs.size;
    string = new char[size + 1]; // add 1 for the null terminator
    strcpy(string, rhs.string);
}

// Assignment operator=
EString &EString::operator=(const EString &rhs)
{
#ifdef _DBG_
    std::cout << "calling assignment operator\n";
#endif
    // must delete because new size could be different
    if (string)
        delete[] string;

    size = rhs.size;
    string = new char[size + 1]; // add 1 for the null terminator
    strcpy(string, rhs.string);
    return *this;
}

// prefix increment
EString EString::operator++()
{
    int i = 0;
    char ltr;
    // Loop through each letter in the string, stopping at the null char
    // Convert each lower case letter into upper case
    while (string[i])
    {
        ltr = string[i];
        string[i] = static_cast<char>(std::toupper(ltr));
        ++i;
    }
    return *this;
}

// postfix increment
EString EString::operator++(int)
{
    EString temp = *this;  // take a copy of the original
    int i = 0;
    char ltr;
    // Loop through each letter in the string, stopping at the null char
    // Convert each lower case letter into upper case
    while (this->string[i])
    {
        ltr = string[i];
        string[i] = static_cast<char>(std::toupper(ltr));
        ++i;
    }
    return temp;  // return the original
}

// indexing operator
char &EString::operator[](int idx)
{
    if ((idx > this->size) || (idx < 0))
    {
        // If the index of the parameter is less than 0 or greater than
        // the size of the string, then print an error message and stop
        // the program
        std::cout << "ERROR: Array index is out of bounds!!!\n";
        exit(1);
    }
    else
        return this->string[idx];
}

// change function replaces the current string or characters with a new string
void EString::change(const char *original)
{
    // Delete old string to create new one
    if (string)
        delete[] string;

    size = strlen(original);     // number of chars, not including '\0'
    string = new char[size + 1]; // create new string, add extra char for '\0'
    strcpy(string, original);    // copy original --> string, including '\0'
}

// Destructor
EString::~EString()
{
    // De-allocate character array
    if (string)
        delete[] string;

    // Avoid dangling pointer and set size to zero
    string = nullptr;
    size = 0;
}

// Friend functions

std::ostream &operator<<(std::ostream &out, const EString &word)
{
    out << word.string;
    return out;
}

EString operator+(const EString &lhs, const EString &rhs)
{
    char word[lhs.size + rhs.size + 1];
    strcpy(word, lhs.string);  // Copy the first word
    strcat(word, rhs.string);  // Add the second word to the end

    return EString(word);
}
