#include <iostream>
#include <string>

using namespace std;

//int function(int);
//void function(int num);
void function(string, int);

int main()
{
    string names = "Rose, Poinsettia, Tsubaki, Plumeria";
    function(names, 0);

    return 0;
}

void function(string str, int pos)
{
    if (pos < str.length())
    {
        function(str, pos + 1);
        cout << str[pos];
    }
}

#if 0
int function(int num)
{
    return num <= 0 ? 0 : function(num - 1) + num;
}
#endif

#if 0
void function(int num)
{
    if (num <= 0)
        return;
    for (int i = 0; i < num; i++)
        cout << '*';
    cout << endl;
    function(num - 1);
}
#endif
