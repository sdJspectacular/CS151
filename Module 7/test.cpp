#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string id;

protected:
    string name;

public:
    Person() { setName(""); }
    Person(const string &pName) { setName(pName); }
    void setName(const string &pname) { name = pname; }
    string getName() const { return name; }
};

class Student : public Person
{
    private:
    string major;
    public:
    Student(const string &sname, const string &discp)
    {
        major = discp;
        name = sname;
        //id = 0;
    }

};

int main()
{
    Person p1("joe");
    Student s1("joe", "cs");

    
    return 0;
}