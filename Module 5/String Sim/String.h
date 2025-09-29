#include <cstring>
#pragma once


class String
{
private:
    char *string;
    int size;

public:
    String(const char *s = ""); // constructor
    ~String();                  // destructor
    void change(const char *);  // reassign string
    friend void print(const String &); // friend function
};

// Constructor
String::String(const char *original)
{
    size = strlen(original);      // number of chars, not including '\0'
    string = new char[size + 1];  // create new string, add extra char for '\0'
    strcpy(string, original);     // copy original --> string, including '\0'
}
