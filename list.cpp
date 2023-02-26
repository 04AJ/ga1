#include "list.h"
#include <iostream>
using namespace std;
// implement recursive selection sort

node *findMid(node *fast, node *slow)
{
    if (fast == nullptr || fast->next == nullptr)
    {
        cout << slow->num;
        return slow;
    }

    else
        return findMid(fast->next->next, slow->next);
}

node *merge(node *list1, node *list2)
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
        if (list2->num < list1->num)
        {
            list3 = list2;
            list3->next = merge(list1, list2->next);
        }
    }
    return list3;
}

node *list::msort(node *head_ref)
{
    if (head_ref == nullptr || head_ref->next == nullptr)
        return nullptr;

    node *left = head_ref;
    node *mid = findMid(left, left);
    // splitting list into two
    node *right = mid->next;
    mid->next = nullptr;

    // sorting both halves
    node *l = msort(left);
    node *r = msort(right);

    node *new_head = merge(l, r);
    return new_head;
}
