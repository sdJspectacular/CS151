#include "String.h"
#include <iostream>
#include <cstring>

// Constructor
String::String(const char *s)
{
    size = strlen(s);     // number of chars, not including '\0'
    string = new char[size + 1]; // create new string, add extra char for '\0'
    strcpy(string, s);    // copy original --> string, including '\0'
}

// Copy Constructor to create a deep copy of the character array
String::String(const String &original)
{
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

// change function replaces the current string or characters with a new string
void String::change(const char *original)
{
    // Delete old string to create new one
    if (string)
        delete[] string;

    size = strlen(original);     // number of chars, not including '\0'
    string = new char[size + 1]; // create new string, add extra char for '\0'
    strcpy(string, original);    // copy original --> string, including '\0'
}

// Destructor
String::~String()
{
    // De-allocate character array
    if (string)
        delete[] string;

    // Avoid dangling pointer and set size to zero
    string = nullptr;
    size = 0;
}

void print(const String &word)
{
    std::cout << word.string << "\n";
}
