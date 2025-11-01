/* hw8_proj2.cpp - Password Verifier
 * Author:     Jack Marriott
 * Module:     8
 * Project:    Homework, Project 2
 * Problem statement:  Verify that a password meets criteria
 *
 * Algorithm:
 *   1. Write password checker that test candidate passwords for:
 *      - each password should be at least six characters long
 *      - each password should contains at least one uppercase and at least one lowercase letter
 *      - each password should have at least one digit
 *      - each password cannot contain any blanks
 *   2. Test with some test cases
 *   3. Request user input until user quits
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

bool checkLen(const char *str);
bool checkCase(const char *str);
bool checkDigit(const char *str);
bool checkBlank(const char *str);
u_int8_t checkCriteria(const char *passwd);
void checkPassword(string password);

int main()
{
    string line;
    string testCases[] = {"psswd",
                          "",
                          "Nowisthe time",
                          "foralltheyoungmen",
                          "tocometotheaid0f",
                          "their country...."};

    // Check all my test cases
    for (int i = 0; i < 6; ++i)
        checkPassword(testCases[i]);

    // Check user input until user quits
    while (true)
    {
        cout << "Enter a password, or \"quit\" to quit: ";
        getline(cin, line);
        if (line == "quit")
            break;
        checkPassword(line);
    }

    return 0;
}

// Check password and explicitly state what criteria were not met
void checkPassword(string password)
{
    uint checks;
    cout << "Password: " << password << "\n";
    checks = checkCriteria(password.c_str());

    if (!(checks & 0x01))
        cout << "Error: Too short\n";

    if (!(checks & 0x02))
        cout << "Error: Does not pass upper/lower case criteria\n";

    if (!(checks & 0x04))
        cout << "Error: Needs at least 1 digit\n";

    if (!(checks & 0x08))
        cout << "Error: Contains blank space\n";

    if (checks == 0x0F)
        cout << "This password is good!\n";

    cout << "\n";
}

// Check each criteria, set a bit when each is passed
u_int8_t checkCriteria(const char *passwd)
{
    return (checkLen(passwd) +
            2 * checkCase(passwd) +
            4 * checkDigit(passwd) +
            8 * checkBlank(passwd));
}

// Check if string length is at least 6 characters of any type
// This also includes empty spaces
bool checkLen(const char *str)
{
    return (strlen(str) >= 6);
}

// Check to see if we find one lower and one upper case character
bool checkCase(const char *str)
{
    int i = 0;
    bool foundUpper = false;
    bool foundLower = false;

    // Walk through all characters until finding EOL
    while (str[i] != '\0')
    {
        if (isupper(str[i]) && !foundUpper)
        {
            // Found an upper case letter, skip the rest
            foundUpper = true;
        }

        if (!isupper(str[i]) && !foundLower)
        {
            // Found a lower case letter, skip the rest
            foundLower = true;
        }

        // Found both, skip the rest
        if (foundLower && foundUpper)
            break;

        i++;
    }

    return (foundLower && foundUpper);
}

// Check for a digit
bool checkDigit(const char *str)
{
    bool foundDigit = false;
    int i = 0;

    // Walk through all characters until finding EOL
    while (str[i] != '\0')
    {
        if (isdigit(str[i]))
        {
            // Found a digit, skip the rest
            foundDigit = true;
            break;
        }
        i++;
    }

    return foundDigit;
}

// Check for a blank space
bool checkBlank(const char *str)
{
    bool foundSpace = false;
    int i = 0;

    // Walk through all characters until finding EOL
    while (str[i] != '\0')
    {
        if (isspace(str[i]))
        {
            // Found a space, skip the rest
            foundSpace = true;
            break;
        }
        i++;
    }

    return !foundSpace;
}
