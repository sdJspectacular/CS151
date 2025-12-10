#ifndef _NUMBERS_H_
#define _NUMBERS_H_

#include <string>
#include <iostream>

// This class holds a number and writes it out as text
// for all values between 0-9999
class Numbers
{
private:
    // The class holds a single private integer member variable
    int number;
    // members of the class itself, not local to any function in the class.
    static const std::string lessThan20[20];
    static const std::string tens[9];
    static const std::string hundred;
    static const std::string thousand;

public:
    // a constructor that accepts a non-negative integer and uses it to initialize the Numbers object's data member
    Numbers(int num = 0) : number(num) {}
    // Get the integer value
    int getNumber(void) const;
    // Set the integer value
    void setNumber(const int num) { number = num; }
    // a function named  print that displays the English description of the number instance variable number
    void print(void);
};
#endif // _NUMBERS_H_
