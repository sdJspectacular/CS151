/* hw8_proj1.cpp - Word Counter
 * Author:     Jack Marriott
 * Module:     8
 * Project:    Homework, Project 1
 * Problem statement:  Count the number of words in a C-string
 *
 * Algorithm:
 *   1. Write encryption function that  takes a C-string 
 *      as an argument and returns the number of words contained in the C-string.
 *   2. This function counts words, where a word is a set of characters between spaces
 *   3. Use C library functions
 *   4. Test with C-strings using leading blanks, multi blanks, final blanks, empty strings
 */
#include <iostream>
#include <cctype>

using namespace std;

int wordCounter(const char *str);

int main()
{
    char *str[] = {"Four score and seven years ago",  // regular phrase
                   "  Now is the time ",              // leading blanks
                   " for   all      the  young men",  // multi spacing
                   "to  come to the aid  of    ",     // terminal blanks
                   "their country....",               // non-letters
                   "    "};                           // empty strings
    for (int i = 0; i < 6; ++i)
    {
        cout << "Phrase: " << str[i] << "\n";
        cout << "Words:  " << wordCounter(str[i]) << "\n\n";
    }

    return 0;
}

// Loop through a set of characters to count the number of words
int wordCounter(const char *str)
{
    int i = 0, j = 0;
    char c = str[i];
    while (true)
    {
        // This while loops through each word, where a word is anything between spaces
        // The word is counted at the end of the letter group, whether it be followed
        // by a space or EOL character
        while (!isspace(c) && c != '\0')
        {
            c = str[++i];
            if (isspace(c) || c == '\0')
                ++j;
        }

        // Break out of the loop if we find EOL character
        if (c == '\0')
            break;
        else
            c = str[++i];
    }

    return j;
}
