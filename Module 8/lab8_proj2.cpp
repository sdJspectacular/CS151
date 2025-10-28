/* lab8_proj2.cpp - String Conversions
 * Author:     Jack Marriott
 * Module:     8
 * Project:    Lab, Project 2
 * Problem statement:  String conversions
 *
 * Algorithm:
 *   1.  blah
 */
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;


int main()
{
    // 1. Create an int variable named "original", prompt for and read in the value from the user
    int original;
    cout << "Please enter an integer: ";
    cin >> original;
    
    // 2. Convert the number to a string using the "to_string" function.
    //    Add the word " rah!" onto the end of the new string.
    //    Print the string on the console.
    string orig_to_string = to_string(original) + " rah!";
    cout << orig_to_string << '\n';
    
    // 3. Convert back to a number using a stringstream class.
    //    Print the new number on the console.
    stringstream inpstr(original_as_string);
    int original_copy;
    inpstr >> original_copy;
    cout << "Converted back to a number: " << original_copy << '\n';
    
    // 4. Convert your number to a binary string of 0's and 1's by putting it in a
    //    C-string, then print the results:
    char *binary = new char[33];
    *(binary + 32) = '\0' ;
    int index = 32 ;
    do {
        *(binary + (--index)) =
        (char) (original_copy % 2 + '0');
        original_copy /= 2;
    } while (original_copy > 0) ;
    cout << "That number in binary is: " << (binary + index) << '\n';
    
    // 5. Use the  stoi  function to convert the string of binary 0's and 1's
    //    back the original number in decimal and print.
    int original_copy = stoi((binary + index), nullptr, 2) ;
    cout << "The original number is: " << original_copy << '\n';
    
    // 6. Convert your number to hexadecimal (base 16).  Print the number in hex.
    stringstream iostr ;
      iostr << hex << original ;
      cout << "The original number in hex is: " << iostr << '\n';
    
    // 7. Back to decimal and print
    iostr >> hex >> original_copy ;
    cout << "The number back to decimal is: " << iostr << "\n";
    
    return 0;
}

