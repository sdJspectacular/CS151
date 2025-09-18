#include <iostream>

using namespace std;

int main()
{
    const double taxRates[] = {0.1, 0.2, 0.3};

    taxRates[1] = 0.25;

    cout << taxRates[1] << endl;

    return 0;
}
