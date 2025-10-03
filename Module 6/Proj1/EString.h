#ifndef _ESTRING_H_
#define _ESTRING_H_

#include <cstring>
#include <iostream>

class EString
{
private:
    char *string;
    int size;

public:
    // constructor
    EString(const char *s = "");

    // copy constructor
    EString(const EString &rhs);

    // destructor
    ~EString();

    // reassign string
    void change(const char *);

    // assignment operator=
    EString &operator=(const EString &);

    // prefix increment
    EString operator++();

    // postfix increment
    EString operator++(int);

    // indexing operator
    char &operator[](int);

    // stream insertion operator>>

    // friend functions
    friend std::ostream &operator<<(std::ostream &, const EString &);
    friend EString operator+(const EString &, const EString &);
};

#endif // _ESTRING_H_
