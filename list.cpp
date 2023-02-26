#include "list.h"
#include <iostream>
using namespace std;

node *findMid(node *fast, node *slow)
{
    if (fast->next == nullptr || fast->next->next == nullptr)
    {
        // cout << slow->num << " ";
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

    node *cur = list3;
    while (cur != nullptr)
    {
        cout << cur->num << " ";
        cur = cur->next;
    }
    cout << endl;
    return list3;
}

void list::msort(node *head_ref)
{
    if (head_ref == nullptr || head_ref->next == nullptr)
        return;

    node *left = head_ref;
    node *mid = findMid(head_ref, head_ref);
    // splitting list into two
    node *right = mid->next;
    mid->next = nullptr;

    // sorting both halves
    msort(left);
    msort(right);

    head_ref = merge(left, right);
}
