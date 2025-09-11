#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    long double term;
    long double total = 0.0;
    long double old_total = 0.0;

    for (int i = 0; i < 2000000; ++i)
    {
        old_total = total;
        term = pow(-1.0, i*1.0) / (2*i + 1);
        total += term;
        cout << setprecision(8);
        cout << total << endl;
        if (static_cast<long>(1E6 * old_total) == static_cast<long>(1E6 * total))
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}