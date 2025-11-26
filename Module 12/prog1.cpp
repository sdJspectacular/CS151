#include <iostream>

using namespace std;

class First
{
protected:
    int a;
public:
    First(int x = 5)
    {
        a = x;
    }

    int getVal()
    {
        return a;
    }
};

class Second : public First
{
private:
    int b;
public:
    Second(int y = 4)
    {
        b = y;
    }
    int getVal()
    {
        return b;
    }
};

int main()
{
    First object1;
    Second object2;

    cout << object1.getVal() << "\n";
    cout << object2.getVal() << "\n";

    return 0;
}
