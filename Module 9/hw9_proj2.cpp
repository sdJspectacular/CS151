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
#include <algorithm>
#include <random>
#include <chrono>

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

void addNewRecord(vector<item_t> *inventory, int idx);
void displayRecord(vector<item_t> *inventory);
void modRecord(vector<item_t> *inventory, vector<int> *mod_record);

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
    vector<item_t> *inventory = new vector<item_t>();
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
    int old_records = inventory->size();
    vector<int> *mod_records = new vector<int>;
    while (!done)
    {
        string line;
        int choice;
        cout << "\nEnter a selection:\n";
        cout << "\t1 to add a new record\n";
        cout << "\t2 to display any record\n";
        cout << "\t3 to modify any record\n";
        cout << "\t4 to quit the program\n";
        cout << ">> ";
        getline(cin, line);
        stringstream ss(line);
        ss >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n........Adding Record........\n";
            addNewRecord(inventory);
            break;
        case 2:
            cout << "\n......Displaying Record......\n";
            displayRecord(inventory);
            break;
        case 3:
            cout << "\n.......Modifying Record......\n";
            modRecord(inventory, mod_records);
            break;
        case 4:
            done = true;
            break;
        default:
            cout << "Invalid choice, try again\n";
            break;
        }
    }

    // Write new items to end of file
    int new_records = inventory->size();
    if (new_records > old_records) // check to see if new records were added
    {
        for (int i = old_records; i < new_records; ++i)
        {
            item_t &it = inventory->at(i);
            data_file.write(reinterpret_cast<char *>(&it), sizeof(item_t));
        }
    }

    long long position;
    // Update existing items
    for (int i = 0; i < mod_records->size(); ++i)
    {
        // Only update items that were not already written as part of new items
        int idx = mod_records->at(i);
        if (idx < old_records)
        {
            item_t &it = inventory->at(i);
            position = idx * sizeof(item_t);
            data_file.seekp(position);  
            data_file.write(reinterpret_cast<char *>(&it), sizeof(item_t));
        }
    }

    // Deallocate memory
    delete inventory;
    delete mod_records;

    // Close file
    data_file.close();

    return 0;
}

// Modify a record
void modRecord(vector<item_t> *inventory, vector<int> *mod_record)
{
    string line;
    int n = inventory->size();
    int idx = n + 1;

    while (true)
    {
        cout << "\nSelect item to modify 0 .. " << (n - 1) << "\n";
        cout << ">> ";
        getline(cin, line);
        {
            stringstream ss(line);
            ss >> idx;
        }

        if ((0 <= idx) && (idx < n)) // Display single item
        {
            cout << "\n  Item number : " << idx << "\n";
            cout << "  Description : " << inventory->at(idx).description << "\n";
            cout << "   Date Added : " << inventory->at(idx).dateAdded << "\n";
            cout << "     Quantity : " << inventory->at(idx).qty << "\n";
            cout << "         Cost : $" << inventory->at(idx).cost << "\n";
            cout << "        Price : $" << inventory->at(idx).price << "\n";
            break;
        }
        else // User selected out-of-bounds element
        {
            cout << "\nThat item does not exist, try again.\n";
        }
    }

    // Keep track of the index of the item to modify
    mod_record->push_back(idx);

    // Modify the record
    addNewRecord(inventory, idx);
}

// Display either a single record (user choice), or all records randomly
void displayRecord(vector<item_t> *inventory)
{
    string line;
    int n = inventory->size();
    int idx = n + 1;

    while (true)
    {
        cout << "\nSelect inventory index 0 .. " << (n - 1) << ", or -1 for all\n";
        cout << ">> ";
        getline(cin, line);
        {
            stringstream ss(line);
            ss >> idx;
        }

        if ((0 <= idx) && (idx < n)) // Display single item
        {
            cout << "\n  Item number : " << idx << "\n";
            cout << "  Description : " << inventory->at(idx).description << "\n";
            cout << "   Date Added : " << inventory->at(idx).dateAdded << "\n";
            cout << "     Quantity : " << inventory->at(idx).qty << "\n";
            cout << "         Cost : $" << inventory->at(idx).cost << "\n";
            cout << "        Price : $" << inventory->at(idx).price << "\n";
            break;
        }
        else if (idx == -1) // Display all items in random order
        {
            // Will need a vector of indices into the inventory
            vector<int> rand_idx;

            // Initialize 0 .. N
            for (int i = 0; i < inventory->size(); ++i)
            {
                rand_idx.push_back(i);
            }

            // Use the current time as a random seed
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            default_random_engine generator(seed);

            // Shuffle the inventory copy
            shuffle(rand_idx.begin(), rand_idx.end(), generator);

            // Display the shuffled list
            for (auto &it : rand_idx)
            {
                cout << "\n  Item number : " << it << "\n";
                cout << "  Description : " << inventory->at(it).description << "\n";
                cout << "   Date Added : " << inventory->at(it).dateAdded << "\n";
                cout << "     Quantity : " << inventory->at(it).qty << "\n";
                cout << "         Cost : $" << inventory->at(it).cost << "\n";
                cout << "        Price : $" << inventory->at(it).price << "\n";
            }
            break;
        }
        else // User selected out-of-bounds element
        {
            cout << "\nThat item does not exist, try again.\n";
        }
    }
}

// Add a new item to the inventory
// Does not add to file immediately, this is handled later
void addNewRecord(vector<item_t> *inventory, int idx = -1)
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

    if (idx == -1)
    {
        // Add the record to the end of the list
        inventory->push_back(item_t(descr, qty, cost, price, date));
        cout << "\nNew record added: " << descr << "\n\n";
    }
    else
    {
        // Add the record at a specific position in the list
        inventory->at(idx) = item_t(descr, qty, cost, price, date);
        cout << "\nNew record added: " << descr << "\n\n";
    }
}
