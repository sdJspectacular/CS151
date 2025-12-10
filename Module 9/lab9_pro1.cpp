/* lab9_proj1.cpp - Binary file
 * Author:     Jack Marriott
 * Module:     9
 * Project:    Lab, Project 1
 * Problem statement:  Initialize a binary file with 20 numbers
 *
 * Algorithm:
 *   1. Create a binary file for output
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
    // Step 3:  Create a  string  constant for the file name used in this lab: "array.dat"
    const string fname = "array.dat";

    // Step 4:  Open an ofstream variable for binary output using the file name created above.
    // If the statement fails, print an error message and stop returning an exit code of 1.
    ofstream data_file(fname, ios::binary | ios::out);
    if (!data_file)
    {
        cout << "ERROR: could not open " << fname << "\n";
        exit(1);
    }

    // Step 5:  Write the numbers from 1 to 10 as integers stored as binary numbers
    // (exactly the way they are stored in memory, 0's andd 1's).
    for (int i = 1; i <= 10; ++i)
    {
        data_file.write(reinterpret_cast<char *>(&i), sizeof(int));
    }

    // Step 6: After the 10 ints, write the square roots of the numbers from 1 - 10 onto the same file.
    // This time store the numbers as  doubles.
    for (int i = 1; i <= 10; ++i)
    {
        double j = sqrt(i);
        data_file.write(reinterpret_cast<char *>(&j), sizeof(double));
    }

    // Step 7:  Close the file and exit
    data_file.close();

    return 0;
}
