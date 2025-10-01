#ifndef _STRING_H_
#define _STRING_H_

#include <cstring>

class String
{
private:
    char *string;
    int size;

public:
    // constructor
    String(const char *s = "");
    String(const String &rhs); // copy constructor
    ~String();                 // destructor
    void change(const char *); // reassign string
    // if this friend function is commented out, the compiler throws this message?
    //   ‘print’ was not declared in this scope; did you mean ‘printf’?
    friend void print(const String &); // friend function
};

String::String(const char *s)
{
    size = strlen(s);
    string = new char[size + 1]; // add 1 for the null terminator
    strcpy(string, s);
}

#endif // _STRING_H_
