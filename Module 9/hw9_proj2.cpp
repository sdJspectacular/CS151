/* hw9_proj2.cpp - Inventory Item
 * Author:     Jack Marriott
 * Module:     9
 * Project:    HW, Project 2
 * Problem statement:  Handle inventory data in a binary file
 *
 * Algorithm:
 *   1.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

const int NCHARS = 80;

// A structure to store inventory information
struct item_t
{
    char description[NCHARS]; // use C-string
    int qty;
    double cost, price;
    char dateAdded[NCHARS]; // use C-string

    // Use a constructor to avoid string inputs that exceed NCHARS
    item_t(const char *tdescr, const int tqty, const double tcost, const double tprice, const char *tdate) : qty(tqty), cost(tcost), price(tprice)
    {
        strncpy(description, tdescr, NCHARS - 1);
        description[NCHARS - 1] = '\0';

        strncpy(dateAdded, tdate, NCHARS - 1);
        dateAdded[NCHARS - 1] = '\0';
    }

    // Also need a default constructor
    item_t() = default;
};

int main()
{
    string fname = "inventory.dat";

    vector<item_t> items;

    // If the inventory file doesn't exist, create one when first running
    // your program

    ifstream in_file(fname, ios::binary);
    bool file_good = in_file.good();
    in_file.close();

    if (!file_good)
    {
        cout << "Input file not found, creating one...\n";

        items.push_back(item_t{"Item A", 10, 10.50, 14.99, "25-Dec-2024"});
        items.push_back(item_t{"Item B", 100, 0.99, 2.99, "25-Dec-2024"});
        items.push_back(item_t{"Item C", 50, 4.09, 7.67, "25-Dec-2024"});

        ofstream data_file(fname, ios::binary);

        if (!data_file)
        {
            cout << "ERROR: could not open " << fname << "\n";
            exit(1);
        }

        for (const auto &it : items)
        {
            data_file.write(reinterpret_cast<const char *>(&it), sizeof(item_t));
        }

        data_file.close();
    }



    return 0;
}
