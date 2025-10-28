/* lab8_proj1.cpp - String Encryption
 * Author:     Jack Marriott
 * Module:     8
 * Project:    Lab, Project 1
 * Problem statement:  Encrypt a string using lambda functions
 *
 * Algorithm:
 *   1.  Write encryption function that handles one character
 *       - each character is encrypted by adding "1" to its ascii code
 *       - only encrypt letters and numbers
 *       - letters at end of alphabet roll back to the beginning
 *       - 9 rolls back to zero
 *   2.  Write a while loop that takes input until user enters "quit"
 *   3.  This loop encrypts each phrase as follows:
 *       - call encryption function on each character one at a time
 *       - use a lambda function that calls the encryption function
 */
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

void encrypt(char &ch);

int main()
{
    char orig[250];
    string message;

    // ask the user to enter a  string  to encode
    while (true)
    {
        // Get the original C-string
        cout << "Enter a string to encode \"quit\" to stop: ";
        cin.getline(orig, 250);

        // Stop if the user enters "quit"
        message = orig;

        // ignore case for quit, use for_each loop
        for_each(message.begin(), message.end(),
                 [](char &c)
                 {
                     c = tolower(c); // from c standard library
                 });

        if (message == "quit")
            break;

        message = orig;

        cout << "You entered: " << message << "\n";

        // use another for_each loop to encrypt one character at a time
        for_each(message.begin(), message.end(),
                 [](char &c)
                 {
                     encrypt(c); // our function defined below
                 });

        cout << "Encrypted: " << message << "\n";
    }

    return 0;
}

// Create a function which takes a single character (passed by reference) and encrypts that character as described above
void encrypt(char &ch)
{
    if (!isalnum(ch)) // do nothing if neither letter nor number
        return;

    if (ch == 'Z')
        ch = 'A';
    else if (ch == 'z')
        ch = 'a';
    else if (ch == '9')
        ch = '0';
    else
        ch += 1; // this is the ascii encryption

    return;
}
