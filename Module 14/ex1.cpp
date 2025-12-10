#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList list;
    list.add(2.5);
    list.add(7.9);
    list.add(12.6);
    list.displayList();
    list.remove(7.9);
    list.displayList();
    cout << "\n";
    return 0;
}