#include <iostream>
using namespace std;
class First
{
protected:
    int a;
public:
    First(int x = 3)
    {
        a = x;
    }
    virtual void twist()
    {
        a *= 4;
    }
    int getVal()
    {
        twist();
        cout << "Inside getval(), a: " << a << "\n";
        return a;
    }
};

class Second : public First
{
private:
    int b;
public:
    Second(int y = 8)
    {
        b = y;
    }
    virtual void twist()
    {
        cout << "Inside twist(Second - before, b): " << b << "\n";
        b *= 10;
        cout << "Inside twist(Second - after, b:):" << b << "\n";
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
