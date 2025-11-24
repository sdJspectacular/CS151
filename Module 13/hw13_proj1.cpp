/* hw13_proj1.cpp - String Bound Exceptions
 * Author:     Jack Marriott
 * Module:     13
 * Project:    W, Project 1
 * Problem statement:  String bound exceptions
 *
 * Algorithm:
 *   1.
 */
#include <iostream>

using namespace std;

class BoundsException : public exception
{
private:
    int badIndex;

public:
    BoundsException(int n) : badIndex(n) {}
    int getIndex(void)
    {
        return badIndex;
    }

    virtual const char * what() const
    {
        
    }
};

class BCheckString : public string
{

public:
    // A constructor that receives a string object passed by value and
    // passes it on to the base class constructor.
    BCheckString(string s) : string(s) {}

    // A  function that throws a BoundsException object if the index k
    // is negative or is greater than or equal to the length of the string.
    // If k is within the bounds of the string, this function should return
    // the character at position k in the string.
    char operator[](int k)
    {
        int n = getVal().length();

        if ((k < 0) || (k >= n))
            throw BoundsException(k);
        else
            return getVal()[k];
    }

    // A getter function to retrieve the contents of the string in the
    // base class
    string getVal(void)
    {
        return *this;
    }
};

int main()
{
    BCheckString a("hola");
    cout << a.getVal() << "\n";
    return 0;
}
