#include <iostream>

using namespace std;

int arraySum(int arr[], int size)

{

    if (size <= 0)
        return 0;

    return arr[size - 1] + arraySum(arr, size - 1);
}

int main()
{
    cout << "hello\n";

    int vals[] = {1, 2, 3, 4, 5};

    cout << arraySum(vals, 5) << endl;
    return 0;
}
