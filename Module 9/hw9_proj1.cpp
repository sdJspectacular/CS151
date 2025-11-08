/* hw9_proj1.cpp - Sentence filter
 * Author:     Jack Marriott
 * Module:     9
 * Project:    HW, Project 1
 * Problem statement:  Capitalization for input file
 *
 * Algorithm:
 *   1. Ask the user for input and output file names
 *   2. Check that both files can be opened, exit if not
 *   3. Parse each character one at a time, capitalizing:
 *      - The first character of each sentence.  First char
 *        is defined as the first letter after a period.
 *      - The personal pronoun I should also be capitalized
 *      - All other letters must be lower case
 *      - use the C functions: isspace(), toupper(), tolower()
 */
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string inFile, outFile;
    stringstream ss;

    // Asks the user for two filenames.  The first file should be opened for input,
    // and the second file should be opened for output. 
    cout << "Enter the input file name: ";
    getline(cin, inFile);
    if (inFile == "")
    {
        inFile = "A Study In Scarlet.txt";
    }
    cout << "Your input file: " << inFile << "\n";
    
    ifstream inDataFile(inFile);
    if (!inDataFile.is_open())
    {
        cout << "ERROR: could not open input file " << inFile << "\n";
        exit(1);
    }

    cout << "\nEnter the output file name: ";
    getline(cin, outFile);
    if (outFile == "")
    {
        outFile = "A_Study_In_Scarlet.txt";
    }
    cout << "Your output file: " << outFile << "\n";
    
    ofstream outDataFile(outFile);
    if (!outDataFile.is_open())
    {
        cout << "ERROR: could not open output file " << outFile << "\n";
        inDataFile.close();
        exit(1);
    }

    // The program will read the contents of the first file character-by-character
    // and convert every character to lowercase with exceptions.
    char ch, nCh;
    int ctr = 0;
    bool nextCap = false;
    bool prevSpace;
    bool maybeIcap = false;

    cout << "\n";
    // Parse each character one at a time
    while (inDataFile.get(ch))
    {
        if (ctr == 0)           // always capitalize first character
            nCh = toupper(ch);
        else if (ch == '.')     // found a period, this means next character
        {                       // that is not whitespace will be capitalized
            nextCap = true;
            nCh = ch;
        }
        else if (nextCap && !isspace(ch))
        {                       // this is the first character after a period
            nextCap = false;    // and should be capitalized
            nCh = toupper(ch);
        }
        else if (prevSpace && (tolower(ch) == 'i'))
        {                       // found a space followed by an "i" or "I"
            nCh = 'i';          // this might need to be capitalized, we'll see
            maybeIcap = true;
        }
        else if (maybeIcap && isspace(ch))
        {                               // found sequence space-I/i-space
            maybeIcap = false;          // this means remove the 'i' from the stream
            string content = ss.str();  // and replace with 'I
            content.back() = 'I';   // replace last letter
            ss.str("");             // reset string stream
            ss.clear();
            ss << content;          // assign back to stringstream
            nCh = ch;
        }
        else                    // nothing special about that character
        {
            nCh = tolower(ch);
            maybeIcap = false;
        }

        if (isspace(ch))        // keep track of spaces, in case we have to capitalize
            prevSpace = true;
        else
            prevSpace = false;

        cout << ch;

        ss << nCh;

        ++ctr;
    }

    // write to file
    outDataFile << ss.str();

    // write to screen
    cout << "\n\n" << ss.str() << "\n\n";

    // close files
    inDataFile.close();
    outDataFile.close();

    return 0;
}

