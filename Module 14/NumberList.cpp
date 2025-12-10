#include "NumberList.h"
using namespace std;

void NumberList::add(double number)
{
    if (head == nullptr)
    {
        head = new ListNode(number);
    }
    else
    {
        ListNode *nodePtr = head;
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }

        ListNode *newNode = new ListNode(number);
        nodePtr->next = newNode;
    }
}

void NumberList::remove(double number)
{
    if (head == nullptr)
        return;

    ListNode *nodePtr = head;
    ListNode *nodePrev = head;

    while (nodePtr->next)
    {
        if (nodePtr->value == number)
        {
            nodePrev->next = nodePtr->next;
            delete nodePtr;
            break;
        }
        nodePrev = nodePtr;
        nodePtr = nodePtr->next;
    }
}

void NumberList::displayList() const
{
    ListNode *nodePtr = head;

    while (nodePtr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}

NumberList::~NumberList()
{
    ListNode *nodePtr = head;

    while (nodePtr)
    {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}
