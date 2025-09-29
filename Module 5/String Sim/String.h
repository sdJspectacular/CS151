#ifndef _STRING_H_
#define _STRING_H_

#include <cstring>

class String
{
private:
    char *string;
    int size;

public:
    String(const char *s = ""); // constructor
    String(const String &);     // copy constructor
    ~String();                  // destructor
    void change(const char *);  // reassign string
    // if this friend function is commented out, the compiler throws this message?
    //   ‘print’ was not declared in this scope; did you mean ‘printf’?
    friend void print(const String &); // friend function
};

// 4. Below the  String  class (but still in the  String.h  file), the constructor for this
// class should take a  C-string,  store in in the heap, and assign it to the  string
// data member.  Notice that this constructor uses two functions from the C++ Standard
// Library (strlen  and  strcpy).  Please include a comment above each function you enter
// below, so I know what each one does:

#if 0
// Placing constructor here will produce an error at compile time
String::String(const char *original)
{
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}
#endif

#endif // _STRING_H_
