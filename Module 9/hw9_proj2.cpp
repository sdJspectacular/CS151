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
#include <limits>

using namespace std;

const int NCHARS = 80;

// A structure to store inventory information
struct item_t
{
    char description[NCHARS]; // use C-string
    int qty;
    double cost, price;
    char dateAdded[NCHARS]; // use C-string

    // Use a constructor to avoid invalid inputs
    item_t(const char *tdescr, const int tqty, const double tcost, const double tprice, const char *tdate)
    {
        // The sizes of the inventory description field isn't exceeded
        strncpy(description, tdescr, NCHARS - 1);
        description[NCHARS - 1] = '\0';

        // The sizes of the date field isn't exceeded
        strncpy(dateAdded, tdate, NCHARS - 1);
        dateAdded[NCHARS - 1] = '\0';

        // The quantity-on-hand, cost, and price of an item cannot be negative
        qty = max(tqty, 0);
        cost = max(tcost, 0.0);
        price = max(tprice, 0.0);
    }

    // Also need a default constructor
    item_t() = default;
};

void addNewRecord(vector<item_t> *);

int main()
{
    string fname = "inventory.dat";

    // Check to see if there is an input file
    ifstream in_file(fname, ios::binary);
    bool file_good = in_file.good();
    in_file.close();

    // If the input file does not exist, create one
    if (!file_good)
    {
        cout << "\nInput file not found, creating one...\n\n";

        // Some initial stock items
        vector<item_t> items;
        items.push_back(item_t{"Item A", 10, 10.50, 14.99, "25-Dec-2024"});
        items.push_back(item_t{"Item B", 100, 0.99, 2.99, "25-Dec-2024"});
        items.push_back(item_t{"Item C", 50, 4.09, 7.67, "25-Dec-2024"});

        ofstream data_file(fname, ios::binary);

        if (!data_file)
        {
            cout << "ERROR: could not open " << fname << "\n";
            exit(1);
        }

        // Write the items to the inventory file
        for (const auto &it : items)
        {
            data_file.write(reinterpret_cast<const char *>(&it), sizeof(item_t));
        }

        data_file.close();
    }
    else
        cout << "\nInput file found\n\n";

    // Load the inventory file
    fstream data_file(fname, ios::binary | ios::in | ios::out | ios::app);
    if (!data_file)
    {
        cout << "ERROR: could not open " << fname << "\n";
        exit(1);
    }

    // Assign all items to a vector
    vector<item_t> *inventory;
    item_t temp_item;
    while (data_file.read(reinterpret_cast<char *>(&temp_item), sizeof(item_t)))
    {
        inventory->push_back(temp_item);
    }

    // The program should have a menu that allows the user to perform the following tasks:
    // * add new records to the file
    // * display any record in the file
    // * quit the program

    bool done = false;
    while (!done)
    {
        string line;
        int choice;
        cout << "Enter a selection:\n";
        cout << "\t1 to add a new record\n";
        cout << "\t2 to display any record\n";
        cout << "\t3 to quit the program\n";
        cout << ">> ";
        getline(cin, line);
        stringstream ss(line);
        ss >> choice;

        switch (choice)
        {
        case 1:
            // addNewRecord();
            cout << "adding record....\n";
            break;
        case 2:
            // displayRecord();
            cout << "displaying record...\n";
            break;
        case 3:
            done = true;
            break;
        default:
            cout << "Invalid choice, try again\n";
            break;
        }
    }

    // Demonstrate the functionality of your program by entering at least 3 items and
    // then displaying them individually on the console in a random order
    // (not sequential).

    // Also demonstrate what happens when the user tries to display an items which
    // doesn't exist in the data file (out-of-bounds).

    // TODO:
    //   add new records to file
    //.  modify any records to file

    // Close file
    data_file.close();

    return 0;
}

// Add a new item to the inventory
void addNewRecord(vector<item_t> *inventory)
{
    string line;
    char descr[NCHARS];
    char date[NCHARS];
    int qty;
    double cost;
    double price;

    cout << "Provide item description: ";
    cin.getline(descr, NCHARS);
    // Check if the input exceeded size limit
    // only using the first 80 chars
    // If user makes a mistake, they'll have to modify the record
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Provide date added: ";
    cin.getline(date, NCHARS);
    // Check if the input exceeded size limit
    // only using the first 80 chars
    // If user makes a mistake, they'll have to modify the record
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter quantity: ";
    getline(cin, line);
    {
        stringstream ss(line);
        ss >> qty;
    }

    cout << "Enter cost: ";
    getline(cin, line);
    {
        stringstream ss(line);
        ss >> cost;
    }

    cout << "Enter price: ";
    getline(cin, line);
    {
        stringstream ss(line);
        ss >> price;
    }

    // Add the record to the array (not to the file just yet)
    inventory->push_back(item_t(descr, qty, cost, price, date));
    cout << "New record added: " << descr << "\n";
}
