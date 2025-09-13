#include <iostream>
#include <string>

using namespace std;

    void modify (int &x) {
        x = 10;
    }

int main()
{
    // 10.2 Write a statement defining a variable named  dPtr.  The variable should be a pointer to a  double.
    double *dPtr = nullptr; // assignment to nullptr is good practice but not required

    // 10.3  List three uses of the  *  symbol in C++.
    //   Multiplication, e.g. 3 * 4 = 12
    //   Pointer declaration, e.g. double *dPtr;
    //   Pointer dereferencing, e.g. *dPtr = 10.0; // this saves the value 10.0 at the location being pointed to by dPtr

    // 10.4  What is the output of the following program? 
    int x = 35, y = 40, z = 45;
    int *ptr = nullptr;
    cout << x << " " << y << " " << z << endl;
    ptr = &x;
    *ptr *= 10;
    ptr = &y;
    *ptr /= 8;
    ptr = &z;
    *ptr -= 20;
    cout << x << " " << y << " " << z << endl;
    
    // 35 40 45
    // 350 5 25

    // 10.5  Rewrite the following loop so it uses square bracket notation (with  [  and  ] ) instead of the indirection operator.
    int array[30] = {0, 1, 2, 3, 4, 5, 6 , 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    // for (int x = 0 ; x < 30 ; x++)
    //    cout << *(array + x) << endl;
    for (int x = 0 ; x < 30 ; x++)
        cout << array[x] << endl;

    // 10.6  Assume  ptr  is a pointer to an  int  and holds the memory address (decimal)  4950.
    //       On a system with 4-byte integers, what address will be in  ptr  (in decimal) after the following statement?
    int *ptra = &array[0];
    ptra += 12;
    cout << &array[0] << " " << ptra << endl;
    cout << sizeof(int) << endl;
    // 4950 dec = 0x1356
    // 4950 + 4*12 = 4998 dec = 0x1386

    // 10.7 Assume  ptrInt  is a pointer to an  int,  and  ptrDouble  is a pointer to a  double. 
    //      Both have previously been assigned values.  For each of the following statements,
    //      determine whether the statement is valid or invalid.  For those that are invalid, explain why.
    int *ptrInt = &array[5];

    double X;
    double *ptrDouble = &X;
    *ptrDouble = 200.0;

    // A. ptrInt++;  Yes, although this increment might go out of bounds
    ptrInt++;
    cout << *ptrInt << endl;
    // B. ptrInt -= 1; Yes, although this increment might go out of bounds
    ptrInt -= 1;
    cout << *ptrInt << endl;
    // C. ptrInt -= ptrDouble; No, left and right types are not equal
    // D. ptrInt += ptrDouble; No, left and right types are not equal
    // E. ptrInt += x; Yes, if x is an int variable
    // F. ptrInt = ptrInt * 2; No, multiplication not defined
    
    // 10.34 Show how to call the modify function so that it sets the integer defined below to 10
    int i = 0;
    modify(i);
    cout << i << endl;


    return 0;
}