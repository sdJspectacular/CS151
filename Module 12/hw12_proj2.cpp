/* hw12_proj2.cpp - Sequence Sum
 * Author:     Jack Marriott
 * Module:     12
 * Project:    HW, Project 2
 * Problem statement:  Sequence Sum
 *
 * Algorithm:
 *   1. Create an abstract base class AbstractSeq
 *      - Contains a pure virtual function fun(int idx) to be overridden in derived classes
 *      - Contains a function printSeq(int low, int high) to print the sequence values from fun(low) to fun(high)
 *      - Contains a function sumSeq(int low, int high) to return the sum of the sequence values from fun(low) to fun(high)
 *   2. Create a derived class OddSeq
 *      - overrides fun(int idx)
 *      - Should return the odd numbers in sequence (fun(0) = 1, fun(1) =3, fun(2) = 5, fun(3) = 7...)
 *   3. Create a derived class FactorialSeq
 *      - overrides fun(int idx)
 *      - Should return the factorial of the parameter (fun(0) = 1, fun(1) = 1, fun(2) = 2, fun(3) = 6, fun(4) = 24...)
 *   4. Demonstrate the AbstractSeq class by creating objects of the child classes
 *      - Print the odd sequence from fun(3) to fun(12) using printSeq
 *      - Print the factorial sequence from fun(1) to fun(10) using printSeq
 *      - Also display the sum of the numbers using sumSeq.  Start and end somewhere inside the sequence, rather than at the beginning.
 */
#include <iostream>
#include <iomanip>

using namespace std;

class AbstractSeq
{
public:
    // Pure  virtual function to be overridden in derived classes
    // This is a stand-in for some sequence function
    virtual int fun(int idx) = 0;

    // The function  printSeq  will print all the terms  fun(low)  through  fun(high)  of the sequence
    void printSeq(int low, int high);

    // The function  sumSeq  will return the sum of  fun(low)  through  fun(high)
    int sumSeq(int low, int high);
};

void AbstractSeq::printSeq(int low, int high)
{
    cout << setw(8) << right << "    n   " << " " << setw(8) << right << " fun(n) " << "\n";
    cout << setw(8) << right << "--------" << " " << setw(8) << right << "--------" << "\n";
    for (int i = low; i <= high; i++)
    {
        cout << setw(8) << right << i << " " << setw(8) << right << fun(i) << "\n";
    }
    cout << "\n";
}

int AbstractSeq::sumSeq(int low, int high)
{
    int sum = 0;
    for (int i = low; i <= high; i++)
    {
        sum += fun(i);
    }
    return sum;
}


// The first child class should return the odd numbers in sequence
// (fun(0) = 1, fun(1) =3, fun(2) = 5, fun(3) = 7...).
class OddSeq : public AbstractSeq
{
public:
    int fun(int idx) override
    {
        return 2 * idx + 1;
    }
};

// The second child class should return the factorial of the parameter
// (fun(0) = 1, fun(1) = 1, fun(2) = 2, fun(3) = 6, fun(4) = 24...).
class FactorialSeq : public AbstractSeq
{
public:
    int fun(int idx) override
    {
        if (idx == 0 || idx == 1)
            return 1;
        int result = 1;
        for (int i = 2; i <= idx; i++)
        {
            result *= i;
        }
        return result;
    }
};


int main()
{
    OddSeq oddSeq;
    // Print the sequence using the  printSeq  function from fun(3) to fun(12)
    cout << "Odd Sequence from fun(3) to fun(12):\n";
    oddSeq.printSeq(3, 12);
    cout << "Sum of Odd Sequence from fun(7) to fun(10): "<< oddSeq.sumSeq(7, 10) << "\n\n";

    FactorialSeq factorialSeq;
    // Print the sequence from fun(1) to fun(10)
    cout << "\nFactorial Sequence from fun(1) to fun(10):\n";
    factorialSeq.printSeq(1, 10);
    cout << "Sum of Factorial Sequence from fun(4) to fun(7): " << factorialSeq.sumSeq(4, 7) << "\n\n";

    return 0;
}

