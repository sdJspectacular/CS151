/* hw9_proj1.cpp - Sentence filter
 * Author:     Jack Marriott
 * Module:     9
 * Project:    HW, Project 1
 * Problem statement:  Capitalization for input file
 *
 * Algorithm:
 *   1. Ask the user for input and output file names
 *   2.
 */
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string inFile, outFile;
    
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

    cout << "Enter the output file name: ";
    getline(cin, outFile);
    if (outFile == "")
    {
        outFile = "A_Study_In_Scarlet.txt";
    }
    cout << "Your output file: " << outFile << "\n";
    
    ofstream outDataFile(inFile);
    if (!outDataFile.is_open())
    {
        cout << "ERROR: could not open output file " << outFile << "\n";
        inDataFile.close();
        exit(1);
    }

    // The program will read the contents of the first file character-by-character
    // and convert every character to lowercase with exceptions.
    char ch;
    while (inDataFile.get(ch))
    {
        cout << ch << "\n";
    }

    cout << "\n";

    inDataFile.close();
    outDataFile.close();

    return 0;
}

