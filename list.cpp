#include "list.h"
#include <iostream>
using namespace std;

node *findMid(node *fast, node *slow)
{
    if (fast == nullptr || fast->next == nullptr)
    {
        return slow;
    }

    else
        return findMid(fast->next->next, slow->next);
}

node *list::merge(node *list1, node *list2)
{
    node *list3 = nullptr;
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;
    if (list1 != nullptr && list2 == nullptr)
        return list1;
    if (list1 == nullptr && list2 != nullptr)
        return list2;
    else
    {

        if (list1->num <= list2->num)
        {
            list3 = list1;
            list3->next = merge(list1->next, list2);
        }
        else if (list2->num < list1->num)
        {
            list3 = list2;
            list3->next = merge(list1, list2->next);
        }
    }
    // important!
    head = list3;
    return list3;
}

/*
HOW TO CALL MSORT ON A LIST:
node *head = test.getHead();
    test.msort(&head);

- note you are passing in a reference to the pointer head (pointer of pointers)
*/

void list::msort(node **head_ref)
{
    node *_head = *head_ref;
    if (_head == nullptr || _head->next == nullptr)
        return;

    node *left = _head;

    node *mid = findMid(_head->next, _head);
    // splitting list into two
    node *right = mid->next;
    mid->next = nullptr;

    // cotinues splitting list until individual nodes - merges through recursive stack
    msort(&left);
    msort(&right);

    *head_ref = merge(left, right);
}
