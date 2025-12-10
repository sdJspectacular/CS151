// CS151 Fall 2025, Decimal to Binary Converter
// Author:   Jack Marriott
// Module:   4
// Project:  Display Box
// Problem Statement: Demonstrate random number generation and unique pointers
//
// Algorithm:
//   1. Set up random number generator for uniform integer distribution in range 0-9
//   2. Create an array of 10 unique pointers to Stone objects
//   3. Randomly assign each stone to an empty slot in a box of 10 slots
//      - Try repeatedly when the random slot is already taken
//   4. Display box contents by stone and by slot
//      - Output is pretty-printed and total attempts tallied
//      - Demonstrate how to do insertion sort of Stone list

#include <iostream>
#include <iomanip>
#include <memory>
#include <random>

using namespace std;

struct Stone {
    char letter;    // Letter of the stone occupying a slot in the display box (A - J)
    int attempts;   // Number of attempts it takes to find an available slot for this stone by selecting a slot at random
    int slot;       // The slot to which the stone is assigned
    Stone(char ltr, int n, int loc) : letter(ltr), attempts(n), slot(loc) {}
};

// Sort an Stone list in increasing order
void insertionSort(unique_ptr<Stone> *slotPtr, int size);

int main()
{
    const int kNumberOfStones = 10;

    // 3. Random number generator
    random_device seed ;  // A random sequence (“seed”) is created based on system clock
    default_random_engine gen(seed());  // A “generator” is created using default_random_engine and the random sequence rd
    //default_random_engine gen(8888);
    uniform_int_distribution<int> slot(0, kNumberOfStones - 1); // The distribution type, low and high range, and returned data type are specified
    
    // 4. Create an array of 10 unique pointers to Stone objects
    unique_ptr<Stone> slots[kNumberOfStones];

    // 5. Create a for loop which processes a single stone (lettered A, B, C... through J)
    int spot, attempts;
    char ltr;
    for (ltr = 'A'; ltr < ('A' + kNumberOfStones); ++ltr)
    {
        attempts = 0;
        // 6. For each stone, use an inner loop
        do
        {
            spot = slot(gen); // 6a.  Generate a random number between 0 and 9
            ++attempts;  // 6b. Track number of attempts until finding an empty spot
        } while(slots[spot]!=nullptr);

        slots[spot] = make_unique<Stone>(ltr, attempts, spot);

    }

    // 7. When each of the 10 stones has been placed into its own slot in the display box, print a nicely formatted (columnar) report
    int tot = 0;
    cout << "    Report by Slot\n";
    cout << "Slot" << "  " << "Stone" << "  " << "Attempts\n";
    cout << "----" << "  " << "-----" << "  " << "--------\n";
    for (int i = 0; i < kNumberOfStones; ++i)
    {
        cout << setw(4) << 1 + slots[i]->slot << "  " << setw(5) << slots[i]->letter << "  " << setw(8) << slots[i]->attempts << "\n";
        tot += slots[i]->attempts;
    }
    cout << "Total Attempts: " << tot << "\n\n";

// 8. Show the results sorted by the stone's letter.  Do this by adding a new data member to the  Stone  structure for the slot the stone is in
    tot = 0;
    cout << "    Report by Stone\n";
    cout << "Stone" << "  " << "Slot" << "  " << "Attempts\n";
    cout << "-----" << "  " << "----" << "  " << "--------\n";
#if 0
    // This part was removed after initial submission
    for (ltr = 'A'; ltr < ('A' + kNumberOfStones); ++ltr)
    {
        for (auto &e : slots)
        {
            if (e->letter == ltr)
            {
                cout << setw(5) << e->letter << "  " << setw(4) << 1 + e->slot << "  " << setw(8) << e->attempts << "\n";
                tot += e->attempts;
            }
        }
    }
    cout << "Total Attempts: " << tot << "\n\n";
#else
    // This part was added after submission
    insertionSort(slots, kNumberOfStones);  // call insertion sort
    for (int i = 0; i < kNumberOfStones; ++i)
    {
        cout << setw(5) << slots[i]->letter << "  " << setw(4) << 1 + slots[i]->slot << "  " << setw(8) << slots[i]->attempts << "\n";
        tot += slots[i]->attempts;
    }
    cout << "Total Attempts: " << tot << "\n\n";
#endif

    return 0;
}

// Sort an Stone list in increasing order
// This is the insertion sort from module 3, modified to work with 
// unique pointers and to srt by letter
void insertionSort(unique_ptr<Stone> *slotPtr, int size)
{

    // At any i-th element, parse thru subelements [0, ..., i-1] and shift
    // one place to the right IF the subelement is greater than the i-th element.
    for (int i = 1; i < size; ++i)
    {
        unique_ptr<Stone> val = move(slotPtr[i]);  // this is the i-th element
        char val_letter = val->letter;
        int k;

        // parse thru subelements in order [i-1, i-2, ..., 0]
        for (k = i - 1; k >= 0; --k)
        {
            if (val_letter < slotPtr[k]->letter)
                slotPtr[k + 1] = move(slotPtr[k]); // move greater values to the right
            else
                break; // stop because remaining elements are less than
        }
        slotPtr[k + 1] = move(val); // set the i-th element where it belongs
   }
}
