/* lab9_proj2.cpp - Binary file
 * Author:     Jack Marriott
 * Module:     9
 * Project:    Lab, Project 2
 * Problem statement:  Multiply numbers in a binary file
 *
 * Algorithm:
 *   1. Create a binary file for input/output
 *      - exit with error code 1 if the file can't be accessed
 *   2. Write the integers 1 - 10 to the file
 *   3. Write the doubles sqrt(j), where j is 1 - 10, to the file
 *   4. Close the file
 */
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    const string fname = "array.dat";

    // Step 2:  Open an ofstream variable for binary input/output using the file name created above.
    // If the statement fails, print an error message and stop returning an exit code of 1.
    ofstream data_file(fname, ios::binary | ios::in | ios::out);
    if (!data_file)
    {
        cout << "ERROR: could not open " << fname << "\n";
        exit(1);
    }
    
    // Step 3:  Ask the user to enter a "multiplier" and store in a double variable named,
    // for example,  multiplier.
    string line;
    double multiplier;
    cout << "Enter a multiplier value: ";
    getline(cin, line);
    stringstream ss(line);
    ss >> multiplier;
    
    // Step 4:  For each of the 10 integers in the file, read the number into an int variable,
    // display the number on the console, multiply by the multiplier, and write back out onto
    // the file in the same position
    cout << "Reading and updating ints...\n";
    int val;
    for (int i = 0; i < 10; ++i)
    {
        data_file.read(reinterpret_cast<char *>(&val), sizeof(int));
        cout << val << " -> " << val * multiplier << "\n";
    }
    
    

    // Step 6:  Close the file and exit
    data_file.close();

    return 0;
}

