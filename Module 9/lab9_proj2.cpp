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
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    const int nNums = 10;
    const string fname = "array.dat";
    int in_val_int, out_val_int;
    double in_val_dbl, out_val_dbl;
    long long position, position1;  // store the current "read" position in a  long long

    // Step 2:  Open an ofstream variable for binary input/output using the file name created above.
    // If the statement fails, print an error message and stop returning an exit code of 1.
    fstream data_file(fname, ios::binary | ios::in | ios::out);
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
    
    //  Step 4: For each of the 10 integers in the file, read the number into an int variable,
    //  display the number on the console, multiply by the multiplier, and write back out onto
    // the file in the same position:
    cout << "Reading and updating ints...\n";
    for (int i = 0; i < nNums; ++i)
    {
        // compute relative position
        position = i * sizeof(int);

        // set pointer to the read position
        data_file.seekg(position);
        // read the next int in the file
        data_file.read(reinterpret_cast<char *>(&in_val_int), sizeof(int));
        if (!data_file)
        {
            cout << "ERROR: reading from " << fname << "\n";
            exit(1);
        }

        // multiply the  int  by  multiplier  and round to the nearest  int
        out_val_int = static_cast<int>(in_val_int * multiplier + 0.5);

        // set pointer to the original read position
        data_file.seekp(position);  
        // write the new number to the old number
        data_file.write(reinterpret_cast<char *>(&out_val_int), sizeof(int));
        if (!data_file)
        {
            cout << "ERROR: writing to " << fname << "\n";
            exit(1);
        }

        // clear any flags
        data_file.clear();

        // write to screen
        cout << in_val_int << " -> " << out_val_int << "\n";
    }
    
    position1 = nNums * sizeof(int);

    cout << "\n";

    // Step 5:  Do the same for the 10 remaining double values in the file, but do not
    // round the result of the multiplication, since we're working with double values
    // instead of int values.
    cout << "Reading and updating doubles...\n";
    for (int i = 0; i < nNums; ++i)
    {
        // compute relative position, starting from end of int positions
        position = i * sizeof(double) + position1;

        // set pointer to the read position
        data_file.seekg(position);
        // read the next int in the file
        data_file.read(reinterpret_cast<char *>(&in_val_dbl), sizeof(double));
        if (!data_file)
        {
            cout << "ERROR: reading from " << fname << "\n";
            exit(1);
        }

        // multiply but do not round
        out_val_dbl = in_val_dbl * multiplier;

        // set pointer to the original read position
        data_file.seekp(position);  
        // write the new number to the old number
        data_file.write(reinterpret_cast<char *>(&out_val_dbl), sizeof(double));
        if (!data_file)
        {
            cout << "ERROR: writing to " << fname << "\n";
            exit(1);
        }

        // clear any flags
        data_file.clear();

        // write to screen
        cout << in_val_dbl << " -> " << out_val_dbl << " (root of " << pow(out_val_dbl, 2) << ")" << "\n";
    }

    cout << "\n";
    
    // Step 6:  Close the file and exit
    data_file.close();

    return 0;
}

