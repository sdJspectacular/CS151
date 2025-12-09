#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
private:
    struct ListNode
    {
        T value;
        ListNode *next;
        ListNode(T value1, ListNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    ListNode *head;
public:
    LinkedList()
    {
        head = nullptr;
    }
    ~LinkedList();
    void add(T value);
    void remove(T value);
    void displayList() const;
};
