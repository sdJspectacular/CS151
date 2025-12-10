#include <iostream>

using namespace std;

class NumberList
{
protected:

    struct ListNode
    {
        double value;
        ListNode *next;
        ListNode(double val, ListNode *next1 = nullptr)
        {
            value = val;
            next = next1;
        }
    };
    ListNode *head; // head pointer

public:
NumberList() {head = nullptr;}
~NumberList();
void add(double number);
void remove(double number);
void displayList() const;
};

