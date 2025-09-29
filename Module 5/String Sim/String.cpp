#include <iostream>
#include "String.h"

using namespace std;

String::~String()
{
    if (string)
        delete [] string;
    
    string = nullptr;
    size = 0;
}

// This function replaces the current string or characters with a new string
void String::change(const char *original)
{
    // Delete old string to create new one
    if (string)
        delete [] string;

    size = strlen(original);      // number of chars, not including '\0'
    string = new char[size + 1];  // create new string, add extra char for '\0'
    strcpy(string, original);     // copy original --> string, including '\0'
}

void print(const String &word)
{
    cout << word.string << "\n";
}
