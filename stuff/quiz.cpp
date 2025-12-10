#include <iostream>

using namespace std;

struct ListNode
{
    double value;
    ListNode *next;
    // Constructor
    ListNode(double new_value, ListNode *new_next = nullptr)
    {
        value = new_value;
        next = new_next;
    }

    // 10. Write a function with the heading: void printSecond(ListNode *ptr)
    // which prints the value stored in the second node of the list passed as a parameter.
    void printSecond(ListNode *ptr)
    {
        if (ptr == nullptr || ptr->next == nullptr)
        {
            // The function should print an error message and stop running the program if
            // the list passed to it has less than 2 nodes.
            cout << "ERROR: No second node.\n";
            return;
        }
        cout << "Second node value: " << ptr->next->value << "\n";
    }

    // 12. Write a function with the heading: ListNode * removeFirst(ListNode *ptr)
    //  Is passed a linked list as parameter and returns the new head of the list
    ListNode * removeFirst(ListNode *llPtr)
    {
        if (!llPtr)
        {
            // The function returns nullptr if the list passed to it is empty
            return nullptr;
        }

        // The function should deallocate the storage of the removed node. 
        ListNode *new_head = llPtr->next;
        delete llPtr;
        return new_head;
    }
};

int main()
{
    cout << "hola\n";

    // Create a list with nodes 10, 20, 30
    ListNode *head = new ListNode(10);
    head = new ListNode(20, head);
    head = new ListNode(30, head);
    
    // List is now: 30 -> 20 -> 10
    // Print the second node's value, should be 20
    head->printSecond(head);
    
    // Remove the first node (30)
    head = head->removeFirst(head);
    // Print the new head's value, should be 10
    head->printSecond(head);
#if 0
    // 14.  Predict output
    ListNode *p = new ListNode(56.4);
    p = new ListNode(34.2, p);
    cout << (*p).value << endl << p->value << endl;

    // (*p).value and p->value are the same thing.
    // It'll just print the head node value twice, i.e., 
    // 34.2
    // 34.2
#endif
    ListNode *p = new ListNode(56.4, new ListNode(31.5));
    ListNode *q = p;
    while (q->next != nullptr)
    {
        q = q->next;
    }
    cout << q->value << endl;

    return 0;
}
