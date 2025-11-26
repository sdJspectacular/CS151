#include <iostream>
using namespace std;
class Base
{
protected:
    int baseVar;
public:
    Base(int val = 6)
    {
        baseVar = val;
    }
    int getVar()
    {
        return baseVar;
    }
};
class Derived : public Base
{
private:
    int derivedVar;
public:
    Derived(int val = 11)
    {
        derivedVar = val;
    }
    int getVar()
    {
        return derivedVar;
    }
};

int main()
{
    Base *optr;
    Derived object;

    optr = &object;
    cout << optr->getVar() << "\n";

    return 0;
}
