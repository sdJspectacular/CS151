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

    while (true)
    {
        // Get the original C-string
        cout << "Enter a string to encode \"quit\" to stop: ";
        cin.getline(orig, 250);

        // Stop if the user enters "quit"
        message = orig;

        for_each(message.begin(), message.end(),
                 [](char &c)
                 {
                     c = tolower(c);
                 });

        if (message == "quit")
            break;

        message = orig;

        cout << "You entered: " << message << "\n";

        for_each(message.begin(), message.end(),
                 [](char &c)
                 {
                     encrypt(c);
                 });

        cout << "Encrypted: " << message << "\n";
    }

    return 0;
}

void encrypt(char &ch)
{
    if (!isalnum(ch))
        return;

    if (ch == 'Z')
        ch = 'A';
    else if (ch == 'z')
        ch = 'a';
    else if (ch == '9')
        ch = '0';
    else
        ch += 1;

    return;
}
