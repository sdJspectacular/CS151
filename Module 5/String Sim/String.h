#ifndef _STRING_H_
#define _STRING_H_

#include <cstring>

using namespace std;

class String
{
private:
    char *string;
    int size;

public:
    String(const char *s = "");        // constructor
    ~String();                         // destructor
    void change(const char *);         // reassign string
    // if this friend function is commented out, the compiler throws this message?
    //   ‘print’ was not declared in this scope; did you mean ‘printf’?
    friend void print(const String &); // friend function
};

#endif // _STRING_H_
