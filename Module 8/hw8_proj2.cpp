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
 *   2. Have single function to test each case and set a bit according
 *      to the results from that case
 *   2. Test with some test passwords
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
                          "OLIVIA",
                          "12345",
                          "Pass  9",
                          "Mannix12"};

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

    // check bit0 for error
    if (!(checks & 0x01))
        cout << "Error: Too short\n";

    // check bit1 for error
    if (!(checks & 0x02))
        cout << "Error: Does not pass upper/lower case criteria\n";

    // check bit2 for error
    if (!(checks & 0x04))
        cout << "Error: Needs at least 1 digit\n";

    // check bit3 for error
    if (!(checks & 0x08))
        cout << "Error: Contains blank space\n";

    // this is the case of everything passes
    if (checks == 0x0F)
        cout << "This password is good!\n";

    cout << "\n";
}

// Function to check all criteria, one at a time.
// A bit is set when each is passed.  
u_int8_t checkCriteria(const char *passwd)
{
    return (checkLen(passwd) +          // sets bit0, 1 = passed, 0 = failed
            2 * checkCase(passwd) +     // sets bit1, 1 = passed, 0 = failed
            4 * checkDigit(passwd) +    // sets bit2, 1 = passed, 0 = failed
            8 * checkBlank(passwd));    // sets bit3, 1 = passed, 0 = failed
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
        // When find an upper case letter, don't check
        // for upper case again
        if (isupper(str[i]) && !foundUpper)
        {
            foundUpper = true;
        }

        // When find a lower case letter, don't check
        // for lower case again
        if (!isupper(str[i]) && !foundLower)
        {
            foundLower = true;
        }

        // Found both, skip the rest because the
        // test is now conclusive
        if (foundLower && foundUpper)
            break;

        i++; // advance to next char
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
            // because the test is now conclusive
            foundDigit = true;
            break;
        }
        i++; // advance to next char
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
            // because test is now conclusive
            foundSpace = true;
            break;
        }
        i++; // advance to next char
    }

    // Invert result, because good result is when
    // there is no space
    return !foundSpace;
}
