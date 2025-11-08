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
    
    cout << "Enter the input file name: ";
    getline(cin, inFile);
    if (inFile == "");
        inFile = "A Study In Scarlet.txt";
    cout << "Your input file: " << inFile << "\n";
    
    cout << "Enter the output file name: ";
    getline(cin, outFile);
    if (outFile == "");
        outFile = "A_Study_In_Scarlet.txt";
    cout << "Your output file: " << outFile << "\n";
    
    
    return 0;
}

