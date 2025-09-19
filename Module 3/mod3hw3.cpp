#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void insertionSort(int *arr, int size);
double avgScore(int *arr, int size);

int main()
{
    // Get number of test scores
    string token;
    int length;
    cout << "Enter number of scores: ";
    getline(cin, token);
    length = stoi(token);

    // dynamically allocated score array
    int *arrPtr = new int[length];

    // assign test scores randomly (it's faster than manual entry)
    cout << "Assigning " << length << " test scores:\n";
    for (int i = 0; i < length; ++i)
        arrPtr[i] = rand() % 100;
    
    // Pass test scores to a function that sorts them in ascending order
    insertionSort(arrPtr, length);
    for (int i = 0; i < length; ++i)
        cout << arrPtr[i] << "\n";

    cout << "\n";

    // Calculate the average score
    cout << "Average Score: " << fixed << setprecision(2) << avgScore(arrPtr, length) << "\n\n";

    delete [] arrPtr;

    return 0;
}

// Sort an integer list in increasing order
void insertionSort(int *arr, int size) {

    // At any i-th element, parse thru subelements [0, ..., i-1] and shift
    // one place to the right IF the subelement is greater than the i-th element.
    for (int i = 1; i < size; ++i)
    {
        int val = arr[i];  // this is the i-th element
        int k;

        // parse thru subelements in order [i-1, i-2, ..., 0]
        for (k = i - 1; k >= 0; --k)
        {
            if (val < arr[k])
                arr[k + 1] = arr[k];    // move greater values to the right
            else
                break;  // stop because remaining elements are less than
        }
        arr[k + 1] = val;   // set the i-th element where it belongs
    }
}

// Compute the average of a list of scores
double avgScore(int *arr, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum/size;
}