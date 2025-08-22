// CS151 Fall 2025
// HW1 Project 1: Use a vector to sort numbers
// Jack Marriott
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>

using namespace std;

// Generates a random number between 1 and 10
inline int randNum(void)
{
    return 1 + rand() % 10;
}

int main()
{
    vector<int> numbers;
    vector<int>::iterator it;
    int value;
    const int N_ELEMS = 30;

    // seed with current time each run
    srand(time(0));

    // Sort the vector in descending order
    // sort(numbers.begin(), numbers.end(), std::greater<int>());

    // Assign the first element
    numbers.push_back(randNum());

    // Loop for the additional elements
    for (int i = 1; i < N_ELEMS; ++i)
    {
        value = randNum();

        it = numbers.begin();
        while (it <= numbers.end())
        {
            if (value >= *it)
            {
                numbers.insert(it, value);
                break;
            }
            ++it;
        }
    }

    // Print to double check descending order
    cout << "Print in descending order:\n";
    for (int num : numbers)
        cout << num << " ";

    cout << "\n\n";

    cout << "Print in ascending order:\n";
    it = numbers.end() - 1;  // the end goes past the last element
    while (it >= numbers.begin())
    {
        cout << *it << " ";
        numbers.pop_back();
        --it;
    }

    cout << "\n\n";

    return 0;
}
