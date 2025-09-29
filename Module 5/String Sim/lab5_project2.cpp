#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String a("hello");
    print(a);
    
    a.change("goodbye");
    print(a);

    cout << "\ndone....\n";

    return 0;
}
