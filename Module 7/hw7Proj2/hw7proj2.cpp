/* hw7proj2.cpp - Homework 7, project 2
 * Author:     Jack Marriott
 * Module:     7
 * Problem statement:  Encryptable string class derived from std::string
 *
 * Algorithm:
 *   1.  Create the encryptable string class
 *   2.  Demonstrate how each phrase encrypts the first time
 *   3.  Demonstrate how each phrase encrypts the second time
 */
#include "EncryptableString.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    EncryptableString words[] = {
        EncryptableString("Holy Moly!"),
        EncryptableString("San Diego Zoo."),
        EncryptableString("The cost is $25.89."),
        EncryptableString("Go away – unless you have tacos."),
        EncryptableString("No one can make you feel inferior without your consent."),
        EncryptableString("Ayatollah of Rock\'n Rolla"),
        EncryptableString("ZZ Top"),
        EncryptableString("AC/DC"),
        EncryptableString("10 Minutes to Midnight"),
    };


    for (EncryptableString word : words)
    {
        cout << setw(20) << left << "Phrase:" << setw(40) << left << word.getPhrase() << "\n";
        word.encrypt();
        cout << setw(20) << left << "Encrypted:" << setw(40) << left << word.getPhrase() << "\n";
        word.encrypt();
        cout << setw(20) << left << "Double Encrypted:" << setw(40) << left << word.getPhrase() << "\n\n";
    }

    cout << "\n";

    return 0;
}
