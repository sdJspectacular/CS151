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

using namespace std;

const int NCHARS = 80;
struct item_t
{
    char description[NCHARS];
    int qty;
    double cost, price;
    char dateAdded[NCHARS];

};

int main()
{
    string fname = "inventory.dat";

    vector<item_t> items;
    items.push_back({"Item A", 10, 10.50, 14.99, "25-Dec-2024"});
    items.push_back({"Item B", 100, 0.99, 2.99, "25-Dec-2024"});
    items.push_back({"Item C", 50, 4.09, 7.67, "25-Dec-2024"});

    ofstream data_file(fname, ios::binary | ios::app);
    if (!data_file)
    {
        cout << "ERROR: could not open " << fname << "\n";
        exit(1);
    }

    for (auto it : items)
    {
        data_file.write(reinterpret_cast<const char*>(&it), sizeof(item_t));
    }

    data_file.close();

    return 0;
}
