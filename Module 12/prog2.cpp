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
    void twist()
    {
        a *= 3;
    }
    int getVal()
    {
        twist();
        return a;
    }
};
class Second : public First
{
private:
    int b;
public:
    Second(int y = 3)
    {
        b = y;
    }
    void twist()
    {
        b *= 10;
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
